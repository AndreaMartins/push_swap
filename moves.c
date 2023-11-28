/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:52:38 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/28 12:51:54 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(int *stack)
{
	int temp;

	temp = stack[0];
	stack[0] = stack[1];
	stack[1] = temp;
	write(1,"sa\n", 3);
}

void swap_pointer(int *ptr1, int *ptr2)
{
	int temp;

	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void	ra(t_list *key_list)
{
	int i;

	i = 0;
	while(i + 1 < key_list->size_a)
	{
		swap_pointer(&key_list->stack_a[i], &key_list->stack_a[i+1]);
		i++;
	}
	write(1,"ra\n",3);
}

void	rra(t_list *key_list)
{
	int i;

	i = key_list -> size_a - 1;
	while (i > 0)
	{
		swap_pointer(&key_list->stack_a[i], &key_list->stack_a[i-1]);
		i--;
	}
	write(1,"rra\n",4);
}

void	pb(t_list *key_list)
{
	int	 i;

	i = key_list->size_b;
	key_list->size_b = key_list->size_b + 1;
	key_list->size_a = key_list->size_a - 1;
	while (i > 0)
	{
		swap_pointer(&key_list->stack_b[i], &key_list->stack_b[i-1]);
		i--;
	}
	key_list->stack_b[0] = key_list->stack_a[0];
	i = 0; 
	while(i <= key_list->size_a - 1)
	{
		key_list->stack_a[i] = key_list->stack_a[i+1];
		i++;
	}
	write(1, "pb\n", 3);
}

void pa(t_list *key_list)
{
	int	i;

	i = key_list->size_a;
	key_list->size_b = key_list->size_b - 1;
	key_list->size_a = key_list->size_a + 1;
	while(i > 0)
	{
		swap_pointer(&key_list->stack_a[i], &key_list->stack_a[i-1]);
		i--;
	}
	key_list->stack_a[0] = key_list->stack_b[0];
	i = 0;
	while(i <= key_list->size_b -1)
	{
		key_list->stack_b[i] = key_list->stack_b[i+1];
		i++;
	}
	write(1, "pa\n", 3);
}


