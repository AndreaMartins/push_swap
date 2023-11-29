/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:09:52 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/29 17:38:43 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
/*1st function implemented*/

int	check_av(char **av, int ac)
{
	int	i;

	i = -1;
	while(++i < ac)
	{
		if(check_is_num(av[i+1]) == -1 || *av[i + 1] == '\0')
		{
			return(-1);
		}
	}
	return (0);
}

int	check_is_num(char *s)
{
	//int	count;
	int	i;
	
//	count = 0;
	i = 0;
	if((s[i] == '-' || s[i] == '+'))
		i++;
	if(s[i] >='0' && s[i] <= '9')
	{
		//count++;
		i++;
		while (s[i])
		{
			if(s[i]>= '0' && s[i] <= '9')
				//count++;
				i++;
		}
		if (ft_atoi(s)	< INT_MIN || ft_atoi(s) > INT_MAX)
			return (-1);
	}
	if (i == ft_strlen(s))
		return(0);
	return (-1);
}

/*4th function implemented*/

int	check_order(t_list *key_list)
{
	int	count;
	int	i;

	count = 0;
	i = 0;

	while( i < key_list->ac_list -1)
	{
		if(key_list->stack_a[i] < key_list->stack_a[i+1])
			count++;
		i++;
	}

	if(count == i)
		return(-1);
	else
		return(0);

}

int	check_repeated_nums(t_list *key_list)
{
	int 	i;
	i = 0;

	while( i < key_list->ac_list)
	{
		if(check_rep(key_list, key_list->stack_a[i], i) == 1)
				i++;
		else
			return(-1);
	}
	return(0);
}

/*doubt if it shuld be static*/

int	check_rep(t_list *key_list, int	num, int x)
{
	int i;

	i = 0;
	while(i<x)
	{
		if (key_list->stack_a[i] == num)
			return(0);
		i++;
	}
	return(1); 
}


