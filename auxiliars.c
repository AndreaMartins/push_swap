/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:05:01 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/22 14:22:59 by andmart2         ###   ########.fr       */
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
			free(key_list->stack_a)
		}
		if(key_list->stack_b)
		{
			free(key_list->stack_b)
		}
		if(key_list->stack_sort)
		{
			free(key_list->stack_sort)
		}
		free(key_list)
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
			free(key_list->stack_sort)
			key_list->stack_sort = NULL;
		}
	}
	exit(0);
}

