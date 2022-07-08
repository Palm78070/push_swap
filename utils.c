/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 15:27:50 by rthammat          #+#    #+#             */
/*   Updated: 2022/06/28 12:04:44 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_instr(char c, char *s)
{
	while (*s)
	{
		if (c == *s)
			return (1);
		++s;
	}
	return (0);
}

static int	ft_isspace(char c)
{
	return (is_instr(c, " \t\r\n\v\f"));
}

static int	check_edge(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		++str;
	if (*str != '\0' && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (*str && ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		if (result > INT_MAX && sign > 0)
			return (1);
		else if ((result * sign) < INT_MIN)
			return (1);
		++str;
	}
	return (0);
}

static int	check_dup(char **argv, int index, int num)
{
	int	i;

	i = 0;
	while (argv[++i])
	{
		if (i == index)
			++i;
		if (argv[i] == NULL)
			break ;
		if (num == ft_atoi(argv[i]))
			return (0);
	}
	return (1);
}

/*int	check_error(char **argv, int *stack_a)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (argv[++i])
	{
		num = ft_atoi(argv[i]);
		if (!ft_str_isnum(argv[i]))
			return (1);
		if (check_edge(argv[i]))
			return (1);
	}
	i = 0;
	while (argv[++i])
	{
		stack_a[i - 1] = ft_atoi(argv[i]);
		if (!(check_dup(argv, i, stack_a[i - 1])))
			return (1);
	}
	return (0);
}*/

int	check_error(char **argv, int *stack_a)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (argv[++i])
	{
		num = ft_atoi(argv[i]);
		if (!ft_str_isnum(argv[i]))
			return (1);
		if (check_edge(argv[i]))
			return (1);
	}
	i = 0;
	while (argv[++i])
	{
		stack_a[i - 1] = ft_atoi(argv[i]);
		if (!(check_dup(argv, i, stack_a[i - 1])))
			return (1);
	}
	return (0);
}
