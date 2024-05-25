/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:41:46 by bsen              #+#    #+#             */
/*   Updated: 2024/05/03 13:16:48 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error(char *str, t_stack *stack, int flag)
{
	if (flag == 1)
		ft_free(stack->tmp);
	if (stack->a != NULL)
		free(stack->a);
	if (stack->b != NULL)
		free(stack->b);
	if (stack->num != NULL)
		free(stack->num);
	ft_putstr_fd(str, 2);
	exit(-1);
}

int	ft_strlen_s(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ps_atoi(char *str, t_stack *stack)
{
	int			sign;
	long long	res;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str <= 13 && *str >= 9))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
		ft_error("Error\n", stack, stack->flag);
	while (*str)
	{
		if (ft_isdigit(*str) == 0)
			ft_error("Error\n", stack, stack->flag);
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (res * sign < -2147483648 || res * sign > 2147483647)
		ft_error("Error\n", stack, stack->flag);
	return (res * sign);
}

void	repeat_num(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = 0;
		while (j < stack->size_a)
		{
			if (stack->a[i] == stack->a[j] && i != j)
				ft_error("Error\n", stack, stack->flag);
			j++;
		}
		i++;
	}
}
