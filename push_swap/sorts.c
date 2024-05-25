/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:59:02 by bsen              #+#    #+#             */
/*   Updated: 2024/04/30 17:06:47 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	selection_sort(t_stack *stack)
{
	int	i;
	int	min_index;
	int	temp;
	int	size;

	i = 0;
	size = stack->size_a;
	while (i < size && ft_checked_sorted(stack->a, stack->size_a) == 0)
	{
		min_index = find_min_index(stack->a, stack->size_a);
		temp = stack->a[min_index];
		if (stack->a[0] != temp && stack->size_a > 1)
			r_or_rr(stack, temp, min_index);
		if (ft_checked_sorted(stack->a, stack->size_a) == 0)
			pb(stack);
		i++;
	}
	while (stack->size_b > 0)
		pa(stack);
}

void	r_or_rr(t_stack *stack, int min_value, int min_index)
{
	if (min_index >= stack->size_a / 2 + stack->size_a % 2)
		while (stack->a[0] != min_value && ft_checked_sorted(stack->a,
				stack->size_a) == 0)
			rra(stack, 1);
	else
		while (stack->a[0] != min_value && ft_checked_sorted(stack->a,
				stack->size_a == 0))
			ra(stack, 1);
}

int	find_min_index(int *arr, int size)
{
	int	i;
	int	min;
	int	index;

	i = 0;
	min = arr[0];
	index = 0;
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	index_stack(int *stack, int size, t_stack *s)
{
	int	*visited;
	int	index;
	int	min_index;

	index = 0;
	visited = ft_calloc(size, sizeof(int));
	if (!visited)
		ft_error("Error\nMalloc", s, s->flag);
	min_index = get_next_min_index(stack, size, visited);
	while (min_index != -1)
	{
		stack[min_index] = index++;
		visited[min_index] = 1;
		min_index = get_next_min_index(stack, size, visited);
	}
	free(visited);
}

int	get_next_min_index(int *stack, int size, int *visited)
{
	int	min_index;
	int	min_value;
	int	i;

	min_index = -1;
	min_value = 0;
	i = 0;
	while (i < size)
	{
		if (!visited[i] && (min_index == -1 || stack[i] < min_value))
		{
			min_index = i;
			min_value = stack[i];
		}
		i++;
	}
	return (min_index);
}
