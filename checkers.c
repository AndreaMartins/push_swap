/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:09:52 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/06 14:16:40 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*1st function implemented*/

int	check_av(char **av, int ac)
{
	int	i;

	i = -1;
	while (++i < ac)
	{
		if (check_is_num(av[i + 1]) == -1 || *av[i + 1] == '\0')
		{
			return (-1);
		}
	}
	return (0);
}

int	check_is_num(char *s)
{
	int	i;

	if (s[0] == '\0')
		return (-1);
	i = 0;
	if ((s[0] == '-' || s[0] == '+') && s[1])
		i = 1;
	while (s[i] && (s[i] >= '0' && s[i] <= '9'))
		i++;
	if (s[i] && (s[i] < '0' || s[i] > '9'))
		return (-1);
	return (0);
}

int	check_order(t_list *key_list)
{
	int	i;

	i = 0;
	while (i < key_list->ac_list -1)
	{
		if (key_list->stack_a[i] > key_list->stack_a[i + 1])
			return (0);
		i++;
	}
	return (-1);
}

int	check_repeated_nums(t_list *key_list)
{
	int	i;

	i = 0;
	while (i < key_list->ac_list)
	{
		if (check_rep(key_list, key_list->stack_a[i], i) == 1)
			i++;
		else
			return (-1);
	}
	return (0);
}

int	check_rep(t_list *key_list, int num, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (key_list->stack_a[i] == num)
			return (0);
		i++;
	}
	return (1);
}
