/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:31 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/30 13:50:54 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int	*stack_a; 
	int	*stack_b;
	int	*stack_sort; //array for sorting purposes
	int	size_a;//size stack a
	int	size_b;//size stack b
	/*int size_ip;//stack index position(related to position in the stack)*/
	/*int size_lsp;//last size of stack position */
	int ac_list;//number comand line arguments
	/*int	percentage; //percentage used in algorithm*/
	/*int control;//control variable*/
	/*int cont;//control variable count or cantainer*/ 
	int error;
	int	msolve;
	/*int atoierror;*/
	/*int jatoi;//variable for atoi*/
	/*int size_block; //size of block used in algorithm*/
	/*int argmax;// max number command line*/
	/*int arguments;//num of arguments used in algorithm */
}	t_list;


int	main(int ac, char **av);
int	ft_size_selector(int ac, t_list *key_list);
int av_to_init(t_list *key_list, int ac, char **av);
int	init_stacks(t_list *key_list);
int	check_av(char **av, int ac);
int	check_is_num(char *s);
int	check_order(t_list *key_list);
int	check_repeated_nums(t_list *key_list);
int	check_rep(t_list *key_list, int	num, int x);
int	ft_strlen(char *s);
void	ft_free(t_list *key_list);
void	ft_freenull(t_list *key_list);
long	ft_atoi(const char *str);
void	ft_error(void);
void	sa(int *stack);
void	swap_pointer(int *ptr1, int *ptr2);
void	ra(t_list *key_list);
void	rb(t_list *key_list);
void	rr(t_list *key_list);
void	rra(t_list *key_list);
void	rrb(t_list *key_list);
void	rrr(t_list *key_list);
void	pb(t_list *key_list);
void	pa(t_list *key_list);
void	size_small(int *stack, t_list *key_list);
void	size_medium(int *stack, t_list *key_list);
void	size_medium_small(int *sta, t_list *key_list);
int		size_medium_continue(int *sta, t_list *key_list, int i);
void	size_medium_big(t_list *key_list);
void	size_big(t_list *key_list);
void	size_extra(t_list *key_list);
void	print_stack(int *stack, int size);
void	assign_index(t_list *key_list);
void	split_chunks(t_list *key_list, int num);

#endif
