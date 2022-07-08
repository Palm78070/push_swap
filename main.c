/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:25:23 by rthammat          #+#    #+#             */
/*   Updated: 2022/07/08 19:03:27 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_swap *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack->s);
	free(stack);
}

void	stack_init(t_swap *stack, int len)
{
	stack->len_a = len;
	stack->len_b = 0;
	stack->len_s = len;
	stack->a = (int *)malloc(stack->len_a * sizeof(int));
	stack->b = (int *)malloc(stack->len_a * sizeof(int));
	stack->s = NULL;
	stack->mid_sort = set_mid(stack->len_s);
	stack->mid_stack = 0;
	stack->above_i = 0;
	stack->below_i = 0;
	stack->instruct = 0;
}

void	stack_b_operation(t_swap *stack, int index, int largest)
{
	int	above;
	int	below;
	
	/*if (stack->b[stack->len_b - 1] == largest)
	{
		pa(stack);
		return ;
	}*/
	above = cal_above_b(stack, largest);
	below = cal_below_b(stack, largest);
	if (above == -1 && below == -1)
		return ;
	if (above == below)
	{
		if (stack->b[stack->above_i] > stack->b[stack->below_i])
			use_above(stack, index, 'b');
			//use_above_b(stack, largest);
			//use_above(stack, index, 'b');
		else
			use_below(stack, index, 'b');
			//use_below_b(stack, largest);
			//use_below(stack, index, 'b');
	}
	else if ((above > below && below != -1) || above == -1)
		use_below(stack, index, 'b');
		//use_below_b(stack, largest);
		//use_below(stack, index, 'b');
	else
		use_above(stack, index, 'b');
		//use_above_b(stack, largest);
		//use_above(stack, index, 'b');
	pa(stack);
	//stack_b_operation(stack, index, largest);
}

void	stack_a_operation(t_swap *stack, int index)
{
	int	above;
	int	below;
	//int	*stack2;

	//stack2 = choose_stack(stack, NULL, c);
	above = cal_above(stack, index, 'a');
	below = cal_below(stack, index, 'a');
	printf("stack->mid_stack is %i\n", stack->mid_stack);
	printf("above is %i\n", above);
	printf("below is %i\n", below);
	printf("above_value is %i\n", stack->a[stack->above_i]);
	printf("below_value is %i\n", stack->a[stack->below_i]);
	if (above == -1 && below == -1)
		return ;
	if (above == below)
	{
		printf("stack->a[above_i] is %i\n", stack->a[stack->above_i]);
		printf("stack->a[below_i] is %i\n", stack->a[stack->below_i]);
		if (stack->a[stack->above_i] < stack->a[stack->below_i])
			use_above(stack, index, 'a');
		else
			use_below(stack, index, 'a');
	}
	else if ((above > below && below != -1) || above == -1)
		use_below(stack, index, 'a');
	else
		use_above(stack, index, 'a');
	check_stack_b(stack);
	pb(stack);
	/*if (c == 'a')
	{
		pb(stack);
		//check_stack_b(stack);
	}*/
	/*if (c == 'b')
		pa(stack);*/
}

void	send_to_b(t_swap *stack, int chunk)
{
	int	n;
	static int	i = 0;
	static int	count = 0;
	int	top;

	n = stack->len_s / chunk;
	top = (i + n) - 1;
	if (count == chunk)
		return ;
	while (i <= top)
	{
		stack_a_operation(stack, i);
		++i;
	}
	++count;
	send_to_b(stack, chunk);
}

void	send_to_a(t_swap *stack, int chunk)
{
	int	n;
	static int	i = 0;
	static int	count = 0;
	int	floor;

	n = stack->len_s / chunk;
	floor = (i - n) + 1;
	if (i == 0)
		i = stack->len_s - 1;
	if (count == chunk)
		return ;
	while (i >= floor)
	{
		stack_b_operation(stack, floor, stack->s[i]);
		--i;
	}
	++count;
	send_to_a(stack, chunk);
}

int	main(int argc, char **argv)
{
	t_swap	*stack;
	//int	top;

	stack = (t_swap *)malloc(sizeof(t_swap));
	stack_init(stack, argc - 1);
	if (check_error(argv, stack->a) || argc <= 1)
	{
		ft_putstr_fd("Error\n", 2);
		free_all(stack);
		exit(1);
	}
	stack->a = change_to_index(stack);
	reverse_arr(stack);
	///Round1
	/*top = stack->len_s - 1;
	int i = 79;
	top = 19;
	i = -1;
	while (++i <= top)
		stack_a_operation(stack, 0);
	top = 39;
	i = 19;
	while (++i <= top)
		stack_a_operation(stack, 20);
	top = 59;
	i = 39;
	while (++i <= top)
		stack_a_operation(stack, 40);
	top = 79;
	i = 59;
	while (++i <= top)
		stack_a_operation(stack, 60);
	top = 99;
	i = 79;
	while (++i <= top)
		stack_a_operation(stack, 80);

	//B operation
	i = 99; //equal top
	while (i >= 80)
	{
		stack_b_operation(stack, 80, stack->s[i]);
		--i;
	}
	///Round2
	i = 79; //equal top
	while (i >= 60)
	{
		stack_b_operation(stack, 60, stack->s[i]);
		--i;
	}
	///Round3
	i = 59; //equal top
	while (i >= 40)
	{
		stack_b_operation(stack, 40, stack->s[i]);
		--i;
	}
	///Round4
	i = 39;
	while (i >= 20)
	{
		stack_b_operation(stack, 20, stack->s[i]);
		--i;
	}
	///Round5
	i = 19; //equal top
	while (i >= 0)
	{
		stack_b_operation(stack, 0, stack->s[i]);
		--i;
	}*/
	///End
	send_to_b(stack, 5);
	send_to_a(stack, 5);
	print_stack(stack->a, stack->len_a);
	printf("\n");
	print_stack(stack->b, stack->len_b);
	printf("instruct is %i\n", stack->instruct);
	free_all(stack);
	return (0);
}
