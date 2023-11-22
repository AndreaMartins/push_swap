/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:12:32 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/22 14:23:04 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int ac, char **av)
{
	t_list	*key_list;
	/*nothing to swap nothing provided*/
	if (ac == 1)
		return (0);
	/*make space for the list */
	key_list = malloc(sizeof(t_list));
	if (!key_list)
		return (0);
	/*1st function-check if the arguments are correct*/
	if (check_av(av, ac -1) == -1)
		ft_free(key_list);
	key_list->counter = ac - 1;
	key_list->error = 0;
	/*2nd function-init values*/
	if (init_stacks(key_list) == -1)
		ft_free(key_list);
	/*3rd function-convert av to int*/
	if (av_to_int(key_list, ac, av) == -1)
	{
		ft_free(key_list);
		return (0);
	}
	/*4rd function-check order*/
	if (check_order(key_list) == -1)
		ft_freenull(key_list);
	/*5th function-select size*/
	if (ft_size_selector(ac, key_list) == -1)
		ft_free(key_list);
	ft_freenull(key_list);
	return (0);
}

/*5th function implementedn*/
int	ft_size_selector(int ac, t_list *key_list)
{
	/*6th function -check there aren't repetitive numbers*/
	if (check_repeated_nums(key_list) == -1)
		return(-1);
	else
	{
		if(ac == 3 || ac == 4)
			size_small(key_list);
		if(ac < 7 &&  ac < 4)
			size_medium(key_list);
		if(ac < 102 && ac > 6)
			size_big(key_list);
		if(c > 101)
			size_extra(key_list);
	}
	return(0);
}	

/*3rd-function implemented*/
int av_to_init(t_list *key_list, int ac, char **av)
{
	int i;

	i = 0;
	while (i != ac - 1)
	{
		/*7th function*/
		if(check_is_num(av[i + 1] == -1))
			return (-1);
		/*8th fuction*/
		key_list->stack_a[i] = ft_atoi(av[i+1], key_list);
		if (key_list ->atoierror == 1)
			return(-1);
		key_list->stack_sort[i] = ft_atoi(av[i +1], key_list);
		i++;
	}
	return(0);
}

/*2nd-function implemented*/
int	init_stacks(t_list *key_list)
{
	/*space for stack_a*/
	key_list->stack_a = malloc(sizeof(int) * key_list->ac_list);
	if(!key_list->stack_a)
	{
		free(key_list);
		return(-1);
	}
	/*space for stack_size */
	key_list->stack_size = malloc(sizeof(int) * key_list->ac_list);
	if(!key_list->stack_size)
	{
		free(key_list->stack_a);
		free(key_list);
		return(-1);
	}
	/*space for stack_b */
	key_list->stack_b = malloc(sizeof(int) * key_list->ac_list);
	if(!key_list->stack_b)
	{
		free(key_list->stack_b);
		free(key_list->stack_a);
		free(key_list);
		return(-1);
	}
	key_list->size_a = key_list->ac_list;
	key_list->size_b = 0;
	/*not sure what is this for*/
	key_list->stack_index = key_list->ac_list;
	return(0);
}
