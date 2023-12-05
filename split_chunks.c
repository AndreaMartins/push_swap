/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:56:02 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/05 12:59:52 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	split_chunks(t_list *k, int num)
{
	int	cchunk_size;
	int	i;
	int	aux;

	i = 0;
	cchunk_size = k->ac_list / num + (k->ac_list % num);
	aux = cchunk_size;
	while (num-- > 0)
	{
		while (i < cchunk_size && k->size_a > 0)
		{
			if (k->stack_a[0] <= cchunk_size)
			{
				pb(k);
				if (k->stack_b[0] <= cchunk_size - (aux / 2) && k->size_b > 1)
				{
					rb(k);
				}
				i++;
			}
			else
				ra(k);
		}
		cchunk_size += aux;
	}
}

static	int	aux_r(t_list *k, int aux_exit, int i)
{
	while (i > 0 && aux_exit == 0)
	{
		if (k->stack_b[0] == k->size_b -1 && k-> msolve == 0)
		{
			pa(k);
			i--;
			k->msolve = 1;
			if (k->stack_b[0] == k->size_b + 1)
			{
				aux_exit = 1;
			}
		}
		if (aux_exit == 0)
		{
			rb(k);
		}
		i--;
	}
	return (aux_exit);
}

static	int	aux_rr(t_list *k, int aux_exit, int i)
{
	i = k->size_b - i;
	while (i > 0 && aux_exit == 0)
	{
		if (k->stack_b[0] == k->size_b - 1 && k->msolve == 0)
		{
			pa(k);
			i--;
			k->msolve = 1;
			rrb(k);
			if (k->stack_b[0] == k->size_b + 1)
			{
				aux_exit = 1;
			}
		}
		if (aux_exit == 0)
		{
			rrb(k);
		}
		i--;
	}
	return (aux_exit);
}

void	solve(t_list *key_list)
{
	int	i;
	int	aux_exit;

	aux_exit = 0;
	key_list->msolve = 0;
	while (key_list->size_b > 0)
	{
		i = 0;
		while (key_list->stack_b[i] != key_list->size_b && i < key_list->size_b)
			i++;
		if (i <= (key_list->size_b / 2))
			aux_exit = aux_r(key_list, aux_exit, i);
		else if (i > (key_list->size_b / 2))
			aux_exit = aux_rr(key_list, aux_exit, i);
		pa(key_list);
		if (key_list->msolve == 1)
		{
			if (key_list->stack_a[0] - 1 == key_list->stack_a[1])
				sa(key_list->stack_a);
			key_list->msolve = 0;
			aux_exit = 0;
		}
	}
}
