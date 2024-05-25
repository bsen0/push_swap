/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:25:24 by bsen              #+#    #+#             */
/*   Updated: 2024/04/30 17:06:58 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	max_bits = get_max_bits(stack);
	i = -1;
	while (++i < max_bits && ft_checked_sorted(stack->a, stack->size_a) == 0)
	{
		size = stack->size_a;
		j = -1;
		while (++j < size && ft_checked_sorted(stack->a, stack->size_a) == 0)
		{
			if (((stack->a[0] >> i) & 1) == 1)
				ra(stack, 1);
			else
				pb(stack);
		}
		if (i + 1 <= max_bits)
			radix_sort_b(stack, i + 1);
	}
	while (stack->size_b > 0)
		pa(stack);
}

void	radix_sort_b(t_stack *stack, int i)
{
	int	j;
	int	size;

	size = stack->size_b;
	j = 0;
	while (j < size)
	{
		if (((stack->b[0] >> i) & 1) == 1)
			pa(stack);
		else
			rb(stack, 1);
		j++;
	}
}

int	get_max_bits(t_stack *stack)
{
	int	i;
	int	max_bits;
	int	max;

	max = stack->a[0];
	i = 1;
	while (i < stack->size_a)
	{
		if (stack->a[i] > max)
			max = stack->a[i];
		i++;
	}
	max_bits = 0;
	while (max >> max_bits != 0)
		max_bits++;
	return (max_bits);
}
