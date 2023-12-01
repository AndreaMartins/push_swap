/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:56:02 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/01 14:35:41 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	split_chunks(t_list *key_list, int num)
{
	int	cchunk_size;
	int	i;
	int	aux;

	i = 0;
	/*Ensures there are no left overs */
	cchunk_size = key_list->ac_list / num + (key_list->ac_list % num);
	/*Saves the size to pass to the next chunk */
	aux = cchunk_size;
	/*the number gets reduce cause it goes to next chunk itearation*/
	while(num-- > 0)
	{
		/*looking for adding in the first chunk of numbers and making sure there is still numbers in chunk a*/
		while(i < cchunk_size && key_list->size_a > 0)
		{
			/*if there is a number smaller in stack a than cchunk */
			if(key_list->stack_a[0] <= cchunk_size)
			{
				/*is added in stack b*/
				pb(key_list);
				/*check if there is at least 2 elements in stack b and if its in the half upper or lower*/
				if( key_list->stack_b[0] <= cchunk_size - (aux / 2) && key_list->size_b > 1)
					rrb(key_list);
				i++;

			}
			else
				rra(key_list);
		}
		cchunk_size += aux;
	}
}

int	aux_rr(t_list *key_list, int aux_exit, int i)
{
	while (i > 0 && aux_exit == 0)
	{
		if(key_list->stack_b[0] == key_list->size_b -1 && key_list-> msolve == 0)
		{
			pa(key_list);
			i--;
			key_list->msolve = 1;
			if(key_list->stack_b[0] == key_list->size_b + 1)
				aux_exit = 1;
		}
		if (aux_exit == 0)
			rb(key_list);
		i--;
	}
	return (aux_exit);
}

int	aux_rrr(t_list *key_list, int aux_exit, int i)
{
	i = key_list->size_b - i;
	while(i > 0 && aux_exit == 0 )
	{
		if(key_list->stack_b[0] == key_list->size_b - 1 && key_list->msolve == 0)
		{
			pa(key_list);
			i--;
			key_list->msolve = 1;
			rrb(key_list);
			if (key_list->stack_b[0] == key_list->size_b + 1)
				aux_exit = 1; 
		}
		if(aux_exit == 0)
			rrb(key_list);
		i--;
	}
	return (aux_exit);
}

void	solve(t_list *key_list)
{
	int	i;
	int	aux;
	int	aux_exit;

	aux = key_list->ac_list;
	aux_exit = 0;
	key_list->msolve = 0;
	/*while there are elments in stack_b */
	while(key_list->size_b > 0)
	{
		i = 0;

		while (key_list->stack_b[0] != key_list->size_b && i < key_list->size_b)
			i++;
		if (i <= (key_list->size_b / 2))
			aux_exit = aux_rr(key_list, aux_exit, i);
		else if( i > (key_list->size_b / 2))
			aux_exit = aux_rrr(key_list, aux_exit, i)
		pa(key_list);
		if(key_list->msolve == 1)
		{
			if(key_list->stack_a[0] - 1 == key_list->stack_a[1])
				sa(key_list->stack_a);
			key_list->msolve = 0;
			aux_exit = 0;
		}
	}
}
