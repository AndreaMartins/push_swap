/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_chunks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 10:56:02 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/04 15:25:28 by andmart2         ###   ########.fr       */
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
	printf("\nchcunkvalue%d \n", cchunk_size);
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
				/*check if there is at least 2 elements in stack b and if its in the half lower of chunk*/
				if( key_list->stack_b[0] <= cchunk_size - (aux / 2) && key_list->size_b > 1)
				{	/*rotate b */
					rb(key_list);
					printf("\nniteration number %d \n", i);
					print_stack(key_list->stack_b, key_list->size_b);
				}
					/*next itearation*/ 
				i++;
			}
			/*if there isnt a small number rotate stack_a to check next number*/
			else
				ra(key_list);
		}
		/*go to next chunk */
		cchunk_size += aux;
	}
}

static	int	aux_r(t_list *key_list, int aux_exit, int i)
{

	printf("\ni value in aux r%d", i);
	while (i > 0 && aux_exit == 0)
	{
		/*if the first element of b is the prev bigger number*/
		if(key_list->stack_b[0] == key_list->size_b -1 && key_list-> msolve == 0)
		{
			//push it to a
			pa(key_list);
			i--;
			key_list->msolve = 1;
			//if the fist element is bigger thatn the size of b
			if(key_list->stack_b[0] == key_list->size_b + 1)
			{
				aux_exit = 1;
			}
		}
		if (aux_exit == 0)
		{
			/*rotate b */
			rb(key_list);
		}
		i--;
	}
	return (aux_exit);
}

static	int	aux_rr(t_list *key_list, int aux_exit, int i)
{
	i = key_list->size_b - i;
	printf("\ni value in aux rr %d", i);
	while(i > 0 && aux_exit == 0 )
	{
		/*if the first element of b is the prev biggest number */
		if(key_list->stack_b[0] == key_list->size_b - 1 && key_list->msolve == 0)
		{ 
			//push it to a *
			pa(key_list);
			i--;
			key_list->msolve = 1;
			//reverse rotate b 
			rrb(key_list);
			if (key_list->stack_b[0] == key_list->size_b + 1)
			{
				aux_exit = 1; 
			}
		}
		if(aux_exit == 0)
		{	
			// reverse rotate b and continue
			rrb(key_list);
		}
		i--;
	}
	return (aux_exit);
}

 void	solve(t_list *key_list)
{
	int	i;
	//int	aux_ac;
	int	aux_exit;

	//aux_ac = key_list->ac_list;
	aux_exit = 0;
	key_list->msolve = 0;
	/*while there are elments in stack_b */
	while(key_list->size_b > 0)
	{
		i = 0;
		/*find biggest element while the fisrst element in stack b is different that the biggest element and iterated less times than the total size of stack b */
		while (key_list->stack_b[i] != key_list->size_b && i < key_list->size_b)
		{/*continu iteration */
			printf("\ni value solve %d", i);
			i++;
		}
		/*if the iteration is in the first half */
		if (i <= (key_list->size_b / 2))
		{
			printf("\ni value solve n if%d", i);
			aux_exit = aux_r(key_list, aux_exit, i);
		}
		/*if the iteration is last half */
		else if( i > (key_list->size_b / 2))
		{
			
			printf("\ni value solve in else if %d", i);
			aux_exit = aux_rr(key_list, aux_exit, i);
		}
		/* push to a*/
		pa(key_list);
		if(key_list->msolve == 1)
		{
			/*if the first element in stack a -1 it's igual to the second element interchange them */
			if(key_list->stack_a[0] - 1 == key_list->stack_a[1])
				sa(key_list->stack_a);
			key_list->msolve = 0;
			aux_exit = 0;
		}
	}
}
