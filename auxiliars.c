/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:05:01 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/23 13:12:43 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(char *s)
{
	int	i;
	i = 0;
	while(s[i])
		i++;
	return(i);
}

void	ft_free(t_list *key_list)
{
	if(key_list)
	{
		if(key_list->stack_a)
		{
			free(key_list->stack_a);
		}
		if(key_list->stack_b)
		{
			free(key_list->stack_b);
		}
		if(key_list->stack_sort)
		{
			free(key_list->stack_sort);
		}
		free(key_list);
	}
	else
	{
		write(2, "Error\n", 6);
		/*some doubts about exit */
		exit(0);
	}
}

void	ft_freenull(t_list *key_list)
{
	if(key_list)
	{
		if(key_list->stack_a)
		{
			free(key_list->stack_a);
			key_list->stack_a = NULL;
		}
		if(key_list->stack_b)
		{
			free(key_list->stack_b);
			key_list->stack_b = NULL;
		}
		if(key_list->stack_sort)
		{
			free(key_list->stack_sort);
			key_list->stack_sort = NULL;
		}
	}
	exit(0);
}

int	ft_atoi(const char *str, t_list *key_list)
{
	int				i;
	int				sign;
	long long int	nbr;

	nbr = 0;
	i = 0;
	sign = 1;

	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr *10 + str[i] - '0';
		i++;
		if(nbr > ((long long int)INT_MAX + 1) && sign == -1)
			return(ft_error(key_list, nbr));
		if(nbr > INT_MAX && sign == 1)
			return(ft_error(key_list, nbr));
	}
	return(nbr*sign);
}

int	ft_error(t_list *key_list, int nbr)
{
	nbr = 0;
	key_list->atoierror = 1;
	return(nbr);
}
