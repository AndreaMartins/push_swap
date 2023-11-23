/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:53:39 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/23 17:16:12 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	size_small(int *stack, t_list *key_list)
{
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
	else if(stack[0] < stack[1] && stack[0] > stack[2] && stack[1] < stack[2])
		rra(key_list);
}

void	size_medium(int *stack, t_list *key_list)
{
	sa(stack);
	ra(key_list);
}

void	size_big(t_list *key_list)
{
	ra(key_list);
}

void	size_extra(t_list *key_list)
{
	ra(key_list);
}

