/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthammat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:46:17 by rthammat          #+#    #+#             */
/*   Updated: 2022/06/27 01:08:15 by rthammat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_arr(int *l_arr, int *r_arr, int len, int *arr)
{
	int	l;
	int	r;
	int	i;
	int	len_l;
	int	len_r;

	l = 0;
	r = 0;
	i = -1;
	len_l = len / 2;
	len_r = len - len_l;
	while (l < len_l && r < len_r)
	{
		if (l_arr[l] <= r_arr[r])
			arr[++i] = l_arr[l++];
		else
			arr[++i] = r_arr[r++];
	}
	while (l < len_l)
		arr[++i] = l_arr[l++];
	while (r < len_r)
		arr[++i] = r_arr[r++];
	free(l_arr);
	free(r_arr);
}

void	merge_sort(int *arr, int len)
{
	int	mid;
	int	*l_arr;
	int	*r_arr;

	if (len < 2)
		return ;
	mid = len / 2;
	l_arr = intdup(arr, mid, 0);
	r_arr = intdup(arr, len - mid, mid);
	merge_sort(l_arr, mid);
	merge_sort(r_arr, len - mid);
	merge_arr(l_arr, r_arr, len, arr);
}
