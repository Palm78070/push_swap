/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:45:43 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/07 18:19:41 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	use_above_b(t_swap *stack, int largest)
{
	int	top;

	top = stack->len_b - 1;
	//if (stack->b[top] == largest)
	//	pa(stack);
	/*while (stack->b[top - 1] != largest)
	{
		if (stack->b[top] > stack->b[top - 1])
			swap(stack, 'b');
		rotate(stack, 'b');
		rotate(stack, 'b');
		top = stack->len_b - 1;
	}*/
	if (stack->b[top - 1] == largest)
	{
		swap(stack, 'b');
		//pa(stack);
	}
	else
	{
		if (stack->b[top] > stack->b[top - 1])
			swap(stack, 'b');
		rotate(stack, 'b');
		rotate(stack, 'b');
	}
}

void	use_below_b(t_swap *stack, int largest)
{
	/*if (stack->b[0] == largest)
	{
		rev_rotate(stack, 'b');
		pa(stack);
	}
	while (stack->b[1] != largest)
	{
		if (stack->b[0] > stack->b[1])
			swap(stack, 'b');
		rev_rotate(stack, 'b');
		rev_rotate(stack, 'b');
	}*/
	if (stack->b[0] == largest)
		rev_rotate(stack, 'b');
	else if (stack->b[1] == largest)
	{
		swap(stack, 'b');
		rev_rotate(stack, 'b');
		//pa(stack);
	}
	else
	{
		if (stack->b[0] > stack->b[1])
			swap(stack, 'b');
		rev_rotate(stack, 'b');
		rev_rotate(stack, 'b');
	}
}
