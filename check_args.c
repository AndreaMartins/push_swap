/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:29:39 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/06 14:13:10 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check_args(t_list *key_list)
{
	if (check_repeated_nums(key_list) == -1)
	{
		return (-1);
	}
	if (check_order(key_list) == -1)
	{
		return (-1);
	}
	return (0);
}
