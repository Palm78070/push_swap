/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:11:58 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/08 19:13:51 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct p_swap
{
	int	*a;
	int	*b;
	int	*s;
	int	len_a;
	int	len_b;
	int	len_s;
	int	mid_sort;
	int	mid_stack;
	int	above_i;
	int	below_i;
	int	instruct;
} t_swap;

//utils
int	check_error(char **argv, int *stack_a);

//utils2
void	print_stack(int *stack, int len);
//void	reverse_arr(t_swap *stack, int *stack_a, int len);
void	reverse_arr(t_swap *stack);
int	*intdup(int *arr, int len, int index);
//int	*change_to_index(int *stack_a, int len);
int	*change_to_index(t_swap *stack);
int	set_mid(int len);

//utils3
int	cal_above(t_swap *stack, int mid_sort, char c);
int	*choose_stack(t_swap *stack, int *top, char c);
int	cal_below(t_swap *stack, int mid_sort, char c);
int	is_insort(int num, int index, t_swap *stack);
void	check_stack_b(t_swap *stack);

//utils4
void	use_above(t_swap *stack, int index, char c);
void	use_below(t_swap *stack, int index, char c);
int	cal_above_b(t_swap *stack, int largest);
int	cal_below_b(t_swap *stack, int largest);

//utils5
void	use_above_b(t_swap *stack, int largest);
void	use_below_b(t_swap *stack, int largest);

//mergesort
void	merge_sort(int *arr, int len);

//instruct
void	swap(t_swap *stack, char c);
void	rotate(t_swap *stack, char c);
void	rev_rotate(t_swap *stack, char c);
void	pa(t_swap *stack);
void	pb(t_swap *stack);

#endif
