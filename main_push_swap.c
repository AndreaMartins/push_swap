/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:12:32 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/17 12:38:10 by andmart2         ###   ########.fr       */
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
	/*check if the arguments are correct*/
	if (check_av(av, ac -1) == -1)
		ft_free(key_list);
	key_list->counter = ac - 1;
	key_list->error = 0;
	/*init values*/
	if (init_values(key_list) == -1)
		ft_free(key_list);
	/*convert av to int*/
	if (av_to_int(key_list, ac, av) == -1)
	{
		ft_free(key_list);
		return (0);
	}
	/*check order*/
	if (check_order(key_list) == -1)
		ft_complexfree(key_list);
	/*select size*/
	if (ft_size_selector(ac, key_list) == -1)
		ft_free(key_list);
	ft_complexfree(key_list);
	return (0);
}
