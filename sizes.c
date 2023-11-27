/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:53:39 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/27 12:19:27 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	size_small(int *stack, t_list *key_list)
{
	printf("\n=====stack before small swap=====\n");
	if(key_list->ac_list == 2 && stack[0] > stack[1])
		sa(stack);
	else if (stack[0] > stack[1] && stack[0] < stack[2] && stack[1] < stack[2])
		sa(stack);
	else if (stack[0] < stack[1] && stack[0] < stack[2] && stack[1] > stack[2])
	{
		rra(key_list);
		sa(stack);
	}
	else if(stack[0] > stack[1] && stack[0] >stack[2] && stack[1] >stack[2])
	{
		ra(key_list);
		sa(stack);
	}
	else if(stack[0] > stack[1] && stack[0] > stack[2] && stack[1] < stack[2])
		ra(key_list);
	else if(stack[0] < stack[1] && stack[0] > stack[2] && stack[1] > stack[2])
		rra(key_list);

	printf("\n=====stack after small swap=====\n");
	print_stack(key_list->stack_a, key_list->size_a);
}

void	print_stack(int *stack, int size)
{
	int i = 0;
	while(i < size)
	{
		printf("\n%d",stack[i]);
		i++;
	}
	printf("\n");
}



void	size_medium_small(int *sta, t_list *key_list)
{
	if(key_list->size_a == 4)
	{
		if(sta[0] < sta[1] && sta[0] < sta[2] && sta[0] <sta[3])
			pb(key_list);
		if(sta[1] < sta[0] && sta[1] < sta[2] && sta[1] < sta[3])
		{
			sa(key_list->stack_a);
			pb(key_list);
		}
		if(sta[2] < sta[0] && sta[2] < sta[1] && sta[2] < sta[3])
		{
			ra(key_list);
			sa(key_list->stack_a);
			pb(key_list);
		}
		if(sta[3] < sta[0] && sta[3] < sta[1] && sta[3] <sta[2])
		{
			rra(key_list);
			pb(key_list);
		}
	}
	if (key_list->size_a == 3)
		size_small(key_list->stack_a, key_list);
	pa(key_list);
	printf("\n=====stack after medium smalll swap=====\n");
	print_stack(key_list->stack_a, key_list->size_a);
}

void	size_medium(int *st, t_list *key_list)
{
	int i;

	i = 0;
	if(key_list->size_a == 5)
	{
		if (st[0] < st[1] && st[0] < st[2] && st[0] < st[3] && st[0] < st[4])
		{
			pb(key_list);
			i++;
		}
		if (st[1] < st[0] && st[1] < st[2] && st[1] < st[3] && st[1] < st[4])
		{
			sa(key_list->stack_a);
			pb(key_list);
			i++;
		}
		i = size_medium_continue(key_list->stack_a, key_list, i);
	}
	size_medium_small(key_list->stack_a, key_list);
	if (i == 1)
	{
		pa(key_list);
		if(st[0] > st[1])
			sa(key_list->stack_a);
		printf("\n=====stack after medium swap=====\n");
		print_stack(key_list->stack_a, key_list->size_a);
	}
}

int	 size_medium_continue(int *st, t_list *key_list, int i)
{
	if (st[2] < st[0] && st[2] < st[1] && st[2] < st[3] && st[2] < st[4])
	{
		ra(key_list);
		sa(key_list->stack_a);
		pb(key_list);
		i++;
	}
	if (st[3] < st[0] && st[3] < st[1] && st[3] < st[2] && st[3] < st[4])
	{
		rra(key_list);
		rra(key_list);
		pb(key_list);
		i++;
	}
	if (st[4] < st[0] && st[4] < st[1] && st[4] < st[2] && st[4] < st[3])
	{
		rra(key_list);
		pb(key_list);
		i++;
	}
	return(i);
}


void	size_big(t_list *key_list)
{
	ra(key_list);
}

void	size_extra(t_list *key_list)
{
	ra(key_list);
}

