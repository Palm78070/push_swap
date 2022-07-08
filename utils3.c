/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 14:35:51 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/08 18:49:32 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*choose_stack(t_swap *stack, int *top, char c)
{
	if (c == 'a')
	{
		if (top != NULL)
			*top = stack->len_a - 1;
		return (stack->a);
	}
	if (c == 'b')
	{
		if (top != NULL)
			*top = stack->len_b - 1;
		return (stack->b);
	}
	return (NULL);
}

int	is_insort(int num, int index, t_swap *stack)
{
	int	i;
	int	last;

	/*i = -1;
	if (index > stack->mid_sort)
	{
		i = stack->mid_sort;
		last = stack->len_s - 1;
	}
	else
		last = stack->mid_sort;*/
	i = index - 1;
	last = index + 19;
	while (++i <= last)
	{
		if (num == stack->s[i])
			return (1);
	}
	return (0);
}

int	cal_above(t_swap *stack, int index, char c)
{
	int	top;
	int	count_step;
	int	*stack2;

	stack2 = choose_stack(stack, &top, c);
	stack->mid_stack = (top + 1) / 2;
	if (!stack2)
		return (-1);
	count_step = 0;
	while (top >= stack->mid_stack && !is_insort(stack2[top], index, stack))
	{
		--top;
		++count_step;
	}
	if (top < stack->mid_stack)
		return (-1);
	stack->above_i = top;
	return (count_step);
}

int	cal_below(t_swap *stack, int index, char c)
{
	int	top;
	int	count_step;
	int	*stack2;

	stack2 = choose_stack(stack, &top, c);
	stack->mid_stack = (top + 1) / 2;
	if (!stack2)
		return (-1);
	count_step = 0;
	top = 0;
	while (top < stack->mid_stack && !is_insort(stack2[top], index, stack))
	{
		++top;
		++count_step;
	}
	if (top >= stack->mid_stack)
		return (-1);
	stack->below_i = top;
	return (count_step + 1);
}

void	check_stack_b(t_swap *stack)
{
	int	top;

	top = stack->len_b - 1;
	if (top == 0)
		return ;
	if (stack->b[top - 1] == stack->b[top] + 1)
		swap(stack, 'b');
	if (stack->b[top] == stack->b[0] + 1)
		rotate(stack, 'b');
}
