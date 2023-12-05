/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:28:13 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/05 11:31:06 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	assign_index(t_list *key_list)
{
	int	i;
	int	j;
	int	new_index;

	i = -1;
	while (i++ < key_list->ac_list)
		key_list->stack_sort[i] = key_list->stack_a[i];
	i = 0;
	while (i < key_list->ac_list)
	{
		new_index = 1;
		j = 0;
		while (j < key_list->ac_list)
		{
			if (i != j && key_list->stack_sort[i] > key_list->stack_sort[j])
				new_index++;
			j++;
		}
		key_list->stack_a[i] = new_index;
		i++;
	}
}
