/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:31 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/17 12:47:44 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int	*stack_a;
	int	*stack_b;
	int	*stack_sort;
	int	size_a;
	int	size_b;
	int	stack_index;
	int	count;
	int	error;
}	t_list;

#endif
