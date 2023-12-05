/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:53:39 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/05 14:16:00 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	size_small(int *stack, t_list *key_list)
{
	if (key_list->ac_list == 2 && stack[0] > stack[1])
		sa(stack);
	else if (stack[0] > stack[1] && stack[0] < stack[2] && stack[1] < stack[2])
	{
		sa(stack);
	}
	else if (stack[0] < stack[1] && stack[0] < stack[2] && stack[1] > stack[2])
	{
		rra(key_list);
		sa(stack);
	}
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] > stack[2])
	{
		ra(key_list);
		sa(stack);
	}
	else if (stack[0] > stack[1] && stack[0] > stack[2] && stack[1] < stack[2])
	{
		ra(key_list);
	}
	else if (stack[0] < stack[1] && stack[0] > stack[2] && stack[1] > stack[2])
	{
		rra(key_list);
	}
}

void	size_medium_small(int *s, t_list *key_list)
{
	if (key_list->size_a == 4)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && key_list->size_a == 4)
			pb(key_list);
		if (s[1] < s[0] && s[1] < s[2] && s[1] < s[3] && key_list->size_a == 4)
		{
			sa(key_list->stack_a);
			pb(key_list);
		}
		if (s[2] < s[0] && s[2] < s[1] && s[2] < s[3] && key_list->size_a == 4)
		{
			ra(key_list);
			sa(key_list->stack_a);
			pb(key_list);
		}
		if (s[3] < s[0] && s[3] < s[1] && s[3] < s[2] && key_list->size_a == 4)
		{
			rra(key_list);
			pb(key_list);
		}
	}
	if (key_list->size_a == 3)
		size_small(key_list->stack_a, key_list);
	pa(key_list);
}

void	size_medium(int *s, t_list *k)
{
	int	i;

	i = 0;
	if (k->size_a == 5)
	{
		if (s[0] < s[1] && s[0] < s[2] && s[0] < s[3] && s[0] < s[4]
			&& k->size_a == 5)
		{
			pb(k);
			i++;
		}
		if (s[1] < s[0] && s[1] < s[2] && s[1] < s[3] && s[1] < s[4]
			&& k->size_a == 5)
		{
			sa(k->stack_a);
			pb(k);
			i++;
		}
		i = size_medium_continue(k->stack_a, k, i);
	}
	size_medium_small(k->stack_a, k);
	if (i == 1)
		process_it(s, k);
}

void	process_it(int *s, t_list *k)
{
	pa(k);
	if (s[0] > s[1])
		sa(k->stack_a);
}

int	size_medium_continue(int *st, t_list *key_list, int i)
{
	if (st[2] < st[0] && st[2] < st[1]
		&& st[2] < st[3] && st[2] < st[4] && key_list->size_a == 5)
	{
		ra(key_list);
		sa(key_list->stack_a);
		pb(key_list);
		i++;
	}
	if (st[3] < st[0] && st[3] < st[1]
		&& st[3] < st[2] && st[3] < st[4] && key_list->size_a == 5)
	{
		rra(key_list);
		rra(key_list);
		pb(key_list);
		i++;
	}
	if (st[4] < st[0] && st[4] < st[1]
		&& st[4] < st[2] && st[4] < st[3] && key_list->size_a == 5)
	{
		rra(key_list);
		pb(key_list);
		i++;
	}
	return (i);
}
