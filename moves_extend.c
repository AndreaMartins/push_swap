/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_extend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:21:56 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/05 12:23:59 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_list *key_list)
{
	int	i;

	i = key_list->size_a - 1;
	while (i > 0)
	{
		swap_pointer(&key_list->stack_a[i], &key_list->stack_a[i - 1]);
		i--;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_list *key_list)
{
	int	i;

	i = key_list->size_b - 1;
	while (i > 0)
	{
		swap_pointer(&key_list->stack_b[i], &key_list->stack_b[i - 1]);
		i--;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_list *key_list)
{
	rra(key_list);
	rrb(key_list);
	write(1, "rrr\n", 4);
}

void	pb(t_list *key_list)
{
	int	i;

	i = key_list->size_b;
	key_list->size_b = key_list->size_b + 1;
	key_list->size_a = key_list->size_a - 1;
	while (i > 0)
	{
		swap_pointer(&key_list->stack_b[i], &key_list->stack_b[i - 1]);
		i--;
	}
	key_list->stack_b[0] = key_list->stack_a[0];
	i = 0;
	while (i <= key_list->size_a - 1)
	{
		key_list->stack_a[i] = key_list->stack_a[i + 1];
		i++;
	}
	write(1, "pb\n", 3);
}

void	pa(t_list *key_list)
{
	int	i;

	i = key_list->size_a;
	key_list->size_b = key_list->size_b - 1;
	key_list->size_a = key_list->size_a + 1;
	while (i > 0)
	{
		swap_pointer(&key_list->stack_a[i], &key_list->stack_a[i - 1]);
		i--;
	}
	key_list->stack_a[0] = key_list->stack_b[0];
	i = 0;
	while (i <= key_list->size_b - 1)
	{
		key_list->stack_b[i] = key_list->stack_b[i + 1];
		i++;
	}
	write(1, "pa\n", 3);
}
