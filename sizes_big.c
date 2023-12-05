/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:28:47 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/05 12:30:13 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	size_medium_big(t_list *key_list)
{
	split_chunks(key_list, 2);
	solve(key_list);
}

void	size_big(t_list *key_list)
{
	split_chunks(key_list, 4);
	solve(key_list);
}

void	size_extra(t_list *key_list)
{
	split_chunks(key_list, 9);
	solve(key_list);
}
