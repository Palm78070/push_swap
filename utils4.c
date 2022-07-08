/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 20:34:02 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/08 19:13:36 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_above(t_swap *stack, int index, char c)
{
	int	*stack2;
	int	top;
	int	i;

	stack2 = choose_stack(stack, &top, c);
	i = stack->above_i;
	if (i == top)
	{
		/*if (is_insort(stack2[top - 1], index, stack))
		{
			if (stack2[top - 1] < stack2[top])
				swap(stack, c);
		}*/
		return ;
	}
	while (i < top - 1)
	{
		rotate(stack, c);
		++i;
	}
	if (is_insort(stack2[0], index, stack))
		swap(stack, c);
	else
		rotate(stack, c);
}

void	use_below(t_swap *stack, int index, char c)
{
	int	*stack2;
	int	top;
	int	i;

	(void)index;
	stack2 = choose_stack(stack, &top, c);
	i = stack->below_i;
	if (i == 0)
	{
		rev_rotate(stack, c);
		return ;
	}
	while (i > 0)
	{
		rev_rotate(stack, c);
		--i;
	}
	rev_rotate(stack, c);
}

int	cal_above_b(t_swap *stack, int largest)
{
	int	top;
	int	count_step;

	count_step = 0;
	top = stack->len_b - 1;
	stack->mid_stack = (top + 1) / 2;
	while (top >= stack->mid_stack && stack->b[top] != largest)
	{
		--top;
		++count_step;
	}
	if (top < stack->mid_stack)
		return (-1);
	stack->above_i = top;
	return (count_step);
}

int	cal_below_b(t_swap *stack, int largest)
{
	int	i;
	int	count_step;

	stack->mid_stack = stack->len_b / 2;
	count_step = 0;
	i = 0;
	while (i < stack->mid_stack && stack->b[i] != largest)
	{
		++i;
		++count_step;
	}
	if (i >= stack->mid_stack)
		return (-1);
	stack->below_i = i;
	return (count_step + 1);
}
