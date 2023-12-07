/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:12:31 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/07 10:40:48 by andmart2         ###   ########.fr       */
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
	int	*stack_sort;
	int	size_a;
	int	size_b;
	int	ac_list;
	int	error;
	int	msolve;
	int	atoierror;
}	t_list;

int		main(int ac, char **av);
int		initialize_program(t_list *key_list, int ac, char **av);
int		ft_size_selector(int ac, t_list *key_list);
int		av_to_init(t_list *key_list, int ac, char **av);
int		init_stacks(int ac, t_list *key_list);
int		check_args(t_list *key_list);
int		one_number(t_list *key_list);
int		check_av(char **av, int ac);
int		check_is_num(char *s);
int		check_order(t_list *key_list);
int		check_repeated_nums(t_list *key_list);
int		check_rep(t_list *key_list, int num, int x);
int		ft_strlen(char *s);
void	ft_free(t_list *key_list);
void	ft_freenull(t_list *key_list);
long	ft_atoi(const char *str, t_list *key_list);
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
void	process_it(int *s, t_list *k);
void	size_medium_big(t_list *key_list);
void	size_big(t_list *key_list);
void	size_extra(t_list *key_list);
void	print_stack(int *stack, int size);
void	assign_index(t_list *key_list);
void	split_chunks(t_list *key_list, int num);
void	solve(t_list *key_list);

#endif
