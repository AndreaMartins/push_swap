/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:56:02 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/30 14:31:32 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	split_chunks(t_list *key_list, int num)
{
	int	cut_num;
	int	i;
	int	aux;

	i = 0;
	cut_num = key_list->ac_list / num + (key_list->ac_list % num);
	aux = cut_num;
	while(num-- >0)
	{
		while(i < cut_num && key_list->size_a > 0)
		{
			if(key_list->stack_a[0] <= cut_num)
			{
				pb(key_list);
				if( key_list->stack_b[0] <= cut_num -(aux / 2) && key_list->size_b > 1)
					rrb(key_list);
				i++;

			}
			else
				rra(key_list);
		}
		cut_num += aux;
	}
}

void	solve(t_list *key_list)
{
	int	i;
	int	aux;
	int	aux_exit;

	aux = key_list->ac_list;
	aux_exit = 0;


}
