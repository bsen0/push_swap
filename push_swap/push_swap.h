/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsen <bsen@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 13:08:05 by bsen              #+#    #+#             */
/*   Updated: 2024/04/30 17:05:39 by bsen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	char	**tmp;
	int		*a;
	int		*b;
	char	*num;
	int		size_a;
	int		size_b;
	int		flag;
}			t_stack;

void		rrb(t_stack *stack, int print);
void		pa(t_stack *stack);
void		pb(t_stack *stack);
void		sa(t_stack *stack, int print);
void		sb(t_stack *stack, int print);
void		ra(t_stack *stack, int print);
void		rb(t_stack *stack, int print);
void		rra(t_stack *stack, int print);
void		ft_error(char *str, t_stack *stack, int flag);
void		repeat_num(t_stack *stack);
int			ft_ps_atoi(char *str, t_stack *stack);
int			ft_strlen_s(char **str);
void		ft_free(char **str);
void		ft_sort(t_stack *stack, int size);
int			ft_checked_sorted(int *stack, int size);
void		ft_sort_three(t_stack *s);
int			get_max_bits(t_stack *stack);
void		radix_sort_b(t_stack *stack, int i);
void		radix_sort(t_stack *stack);
int			get_next_min_index(int *stack, int size, int *visited);
void		index_stack(int *stack, int size, t_stack *s);
int			find_min_index(int *arr, int size);
void		r_or_rr(t_stack *stack, int min_value, int min_index);
void		selection_sort(t_stack *stack);

#endif
