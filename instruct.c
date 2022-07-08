/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:32:46 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/07 17:38:38 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_swap *stack, char c)
{
	int	tmp;
	int	before_top;
	int	top;
	int	*stack2;

	stack2 = choose_stack(stack, &top, c);
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	if (c == 'b')
		ft_putstr_fd("sb\n", 1);
	before_top = top - 1;
	tmp = stack2[top];
	stack2[top] = stack2[before_top];
	stack2[before_top] = tmp;
	stack->instruct += 1;
}

void	rotate(t_swap *stack, char c)
{
	int	tmp;
	int	top;
	int	*stack2;

	stack2 = choose_stack(stack, &top, c);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
	tmp = stack2[top];
	while (top > 0)
	{
		stack2[top] = stack2[top - 1];
		--top;
	}
	stack2[0] = tmp;
	stack->instruct += 1;
}

void	rev_rotate(t_swap *stack, char c)
{
	int	tmp;
	int	top;
	int	i;
	int	*stack2;

	i = -1;
	stack2 = choose_stack(stack, &top, c);
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
	tmp = stack2[0];
	while (++i < top)
		stack2[i] = stack2[i + 1];
	stack2[top] = tmp;
	stack->instruct += 1;
}

/*void	push(t_swap *stack, char c)
{
	int	*stack_p;
	int	*stack_r;
	int	top_p;
	int	top_r;

	if (c == 'b')
	{
		(stack->len_a) -= 1;
		(stack->len_b) += 1;
		top_p = stack->len_a;
		top_r = stack->len_b - 1;
		stack_p = stack->a;
		stack_r = stack->b;
	}
	else if (c == 'a')
	{
		(stack->len_b) -= 1;
		(stack->len_a) += 1;
		top_p = stack->len_b;
		top_r = stack->len_a - 1;
		stack_p = stack->b;
		stack_r = stack->a;
	}
	else
		return ;
	stack_r[top_r] = stack_p[top_p];
}*/

void	pa(t_swap *stack)
{
	int	*stack_p;
	int	*stack_r;
	int	top_p;
	int	top_r;

	(stack->len_b) -= 1;
	(stack->len_a) += 1;
	top_p = stack->len_b;
	top_r = stack->len_a - 1;
	stack_p = stack->b;
	stack_r = stack->a;
	stack_r[top_r] = stack_p[top_p];
	ft_putstr_fd("pa\n", 1);
	stack->instruct += 1;
}

void	pb(t_swap *stack)
{
	int	*stack_p;
	int	*stack_r;
	int	top_p;
	int	top_r;

	(stack->len_a) -= 1;
	(stack->len_b) += 1;
	top_p = stack->len_a;
	top_r = stack->len_b - 1;
	stack_p = stack->a;
	stack_r = stack->b;
	stack_r[top_r] = stack_p[top_p];
	ft_putstr_fd("pb\n", 1);
	stack->instruct += 1;
}

/*void	rotate(int *stack, int top, char c)
{
	int	tmp;

	top -= 1;
	tmp = stack[top];
	while(top > 0)
	{
		stack[top] = stack[top - 1];
		--top;
	}
	stack[0] = tmp;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}*/

/*void	rev_rotate(int *stack, int top, char c)
{
	int	tmp;
	int	i;

	top -= 1;
	i = -1;
	tmp = stack[0];
	while(++i < top)
		stack[i] = stack[i + 1];
	stack[top] = tmp;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}*/
