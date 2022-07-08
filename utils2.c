/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:54:27 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/04 19:57:40 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(int *stack, int len)
{
	int	i;

	i = -1;
	while (++i < len)
	{
		ft_putnbr_fd(stack[len - 1 - i], 1);
		ft_putchar_fd('\n', 1);
	}
}

void	reverse_arr(t_swap *stack)
{
	int	tmp;
	int	i;
	int	len;

	len = stack->len_a;
	tmp = stack->a[len - 1];
	i = 0;
	while (i < len / 2)
	{
		tmp = stack->a[i];
		stack->a[i] = stack->a[len - i - 1];
		stack->a[len - i - 1] = tmp;
		++i;
	}
}

/*void	reverse_arr(t_swap *stack, int *stack_a, int len)
{
	int	tmp;
	int	i;

	tmp = stack_a[len - 1];
	i = 0;
	while (i < len / 2)
	{
		tmp = stack_a[i];
		stack_a[i] = stack_a[len - i - 1];
		stack_a[len - i - 1] = tmp;
		++i;
	}
	stack->mid_s = stack->len_a / 2;
}*/

int	*intdup(int *arr, int len, int index)
{
	int	*new_arr;
	int	i;

	i = -1;
	index -= 1;
	new_arr = (int *)malloc(len * sizeof(int));
	if (!new_arr)
		return (NULL);
	while (++i < len)
		new_arr[i] = arr[++index];
	return (new_arr);
}

int	*change_to_index(t_swap *stack)
{
	int	i;
	int	j;
	int	*res_arr;

	i = -1;
	stack->s = intdup(stack->a, stack->len_a, 0);
	res_arr = (int *)malloc(stack->len_a * sizeof(int));
	if (!res_arr)
		return (NULL);
	merge_sort(stack->s, stack->len_s);
	while (++i < stack->len_a)
	{
		j = -1;
		while (++j < stack->len_a)
		{
			if (stack->s[i] == stack->a[j])
				res_arr[j] = i;
		}
	}
	i = -1;
	while (++i < stack->len_s)
		stack->s[i] = i;
	free(stack->a);
	return (res_arr);
}

int	set_mid(int len)
{
	if (len % 2 == 0)
		len = (len / 2) - 1;
	else
		len = len / 2;
	return (len);
}

/*int	*change_to_index(t_swap *stack)
{
	int	i;
	int	j;
	int	*sort_arr;
	int	*res_arr;

	i = -1;
	sort_arr = intdup(stack->a, stack->len_a, 0);
	res_arr = (int *)malloc(stack->len_a * sizeof(int));
	if (!sort_arr || !res_arr)
		return (NULL);
	merge_sort(sort_arr, stack->len_a);
	stack->s = sort_arr;
	//stack->len_s = stack->len_a;
	//stack->mid_v = stack->s[stack->len_a / 2];
	while (++i < stack->len_a)
	{
		j = -1;
		while (++j < stack->len_a)
		{
			if (stack->s[i] == stack->a[j])
			{
				res_arr[j] = i;
				stack->s[i] = i; ////modify
			}
		}
	}
	//free(sort_arr);
	free(stack->a);
	return (res_arr);
}*/
