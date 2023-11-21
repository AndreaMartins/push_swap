/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:31 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/21 14:16:12 by andmart2         ###   ########.fr       */
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
	int	*stack_sort; //array for sorting purposes
	int	size_a;//size stack a
	int	size_b;//size stack b
	int size_ip;//stack index position(related to position in the stack)
	int size_lsp;//last size of stack position 
	int ac_list;//number comand line arguments
	int	percentage; //percentage used in algorithm
	int control;//control variable
	int cont;//control variable count or cantainer 
	int error;
	int atoierror;
	int jatoi;//variable for atoi
	int size_block; //size of block used in algorithm
	int argmax;// max number command line
	int arguments;//num of arguments used in algorithm 
}	t_list;

#endif
