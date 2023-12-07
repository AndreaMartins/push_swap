/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:29:39 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/07 11:31:59 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_args(t_list *key_list)
{
	if (one_number(key_list) == -1)
	{
		return (-1);
	}
	if (check_repeated_nums(key_list) == -1)
	{
		ft_error();
		return (-1);
	}
	if (check_order(key_list) == -1)
	{
		return (-1);
	}
	return (0);
}

int	one_number(t_list *key_list)
{
	if (key_list->ac_list == 1)
		return (-1);
	return (0);
}
