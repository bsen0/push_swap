/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:58:14 by bsen              #+#    #+#             */
/*   Updated: 2024/05/03 13:18:59 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	creat_s(char **tmp, t_stack *stack)
{
	int	i;

	i = -1;
	stack->size_a = ft_strlen_s(tmp);
	if (stack->size_a < 1)
		ft_error("Error\nMalloc Error", stack, stack->flag);
	stack->size_b = 0;
	stack->a = malloc(sizeof(int) * stack->size_a);
	if (!stack->a)
		ft_error("Error\nMalloc Error", stack, stack->flag);
	stack->b = malloc(sizeof(int) * stack->size_a);
	if (!stack->b)
		ft_error("Error\nMalloc Error", stack, stack->flag);
	while (tmp[++i])
	{
		stack->num = ft_strtrim(tmp[i], " ");
		stack->a[i] = ft_ps_atoi(stack->num, stack);
		free(stack->num);
	}
	stack->num = NULL;
	repeat_num(stack);
}

static void	init_null(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	stack->num = NULL;
	stack->flag = 0;
}

void	ft_sort(t_stack *stack, int size)
{
	if (ft_checked_sorted(stack->a, stack->size_a) == 0)
	{
		if (size == 2)
			sa(stack, 1);
		else if (size == 3)
			ft_sort_three(stack);
		else if (stack->size_a <= 32)
			selection_sort(stack);
		else
		{
			index_stack(stack->a, stack->size_a, stack);
			radix_sort(stack);
		}
	}
}

int	main(int ac, char **av)
{
	t_stack	stack;

	if (ac == 1)
		return (0);
	av++;
	init_null(&stack);
	if (ac == 2)
	{
		stack.tmp = ft_split(av[0], ' ');
		if (!stack.tmp)
			ft_error("Error\nMalloc Error", &stack, 0);
		stack.flag = 1;
		creat_s(stack.tmp, &stack);
	}
	else
		creat_s(av, &stack);
	if (stack.flag == 1)
		ft_free(stack.tmp);
	ft_sort(&stack, stack.size_a);
	free(stack.a);
	free(stack.b);
}
