/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:12:32 by andmart2          #+#    #+#             */
/*   Updated: 2023/12/06 14:18:26 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int ac, char **av)
{
	t_list	*key_list;

	if (ac == 1)
		return (0);
	key_list = malloc(sizeof(t_list));
	if (!key_list)
		return (0);
	if (initialize_program(key_list, ac, av) == -1)
	{
		ft_error();
		return (0);
	}
	if (check_args(key_list) == -1)
	{
		ft_error();
		ft_free(key_list);
		return (0);
	}
	if (ft_size_selector(ac, key_list) == -1)
	{
		ft_error();
		ft_free(key_list);
	}
	ft_freenull(key_list);
	return (0);
}

int	initialize_program(t_list *key_list, int ac, char **av)
{
	if (check_av(av, ac - 1) == -1)
	{
		ft_free(key_list);
		return (-1);
	}
	key_list->ac_list = ac - 1;
	if (init_stacks(ac, key_list) == -1)
	{
		ft_free(key_list);
		return (-1);
	}
	if (av_to_init(key_list, ac, av) == -1)
	{
		ft_free(key_list);
		return (-1);
	}
	return (0);
}

int	init_stacks(int ac, t_list *key_list)
{
	key_list->stack_a = malloc(sizeof (int) * (ac - 1));
	if (!key_list->stack_a)
	{
		free(key_list);
		return (-1);
	}
	key_list->stack_sort = malloc(sizeof (int) * (ac - 1));
	if (!key_list->stack_sort)
	{
		free(key_list->stack_a);
		free(key_list);
		return (-1);
	}
	key_list->stack_b = malloc(sizeof (int) * (ac - 1));
	if (!key_list->stack_b)
	{
		free(key_list->stack_b);
		free(key_list->stack_a);
		free(key_list);
		return (-1);
	}
	key_list->ac_list = ac - 1;
	key_list->size_a = ac -1;
	key_list->size_b = 0;
	return (0);
}

int	av_to_init(t_list *key_list, int ac, char **av)
{
	int	i;

	i = 0;
	while (i != ac - 1)
	{
		if (check_is_num(av[i + 1]) == -1)
		{
			ft_free(key_list);
			return (-1);
		}
		key_list->stack_a[i] = ft_atoi(av[i + 1], key_list);
		if (key_list->atoierror == 1)
		{
			ft_error();
			return (-1);
		}
		key_list->stack_sort[i] = ft_atoi(av[i + 1], key_list);
		if (key_list->atoierror == 1)
		{
			ft_error();
			return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_size_selector(int ac, t_list *key_list)
{
	if (ac == 3 || ac == 4)
		size_small(key_list->stack_a, key_list);
	if (ac < 7 && ac > 4)
		size_medium(key_list->stack_a, key_list);
	if (ac > 6)
		assign_index(key_list);
	if (ac > 6 && ac < 22)
		size_medium_big(key_list);
	if (ac < 152 && ac > 21)
		size_big(key_list);
	if (ac > 151)
		size_extra(key_list);
	return (0);
}
