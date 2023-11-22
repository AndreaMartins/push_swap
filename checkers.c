/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:09:52 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/22 14:22:55 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*1st function implemented*/

int	check_av(char **av, int ac)
{
	int	i;

	i = -1;
	while(++i < ac)
	{
		if(check_is_num(av[i+1] == -1) || *ac[i+1] == '\0')
		{
			return(-1);
		}
	}
}

int	check_is_num(char *s)
{
	int	count;
	int	i;
	
	count = 0;
	i = 0;
	if((s[i] == '-' && (s[i+1] >= '0' && s[i+1] <='0')) || (s[i] >='0' && s[i] <= '9'))
	{
		count++;
		i++;
		while (s[i])
		{
			if(s[i]>= '0' && s[i] <= '9')
				count++;
				i++;
		}
	}
	if (i == ft_strlen(s))
		return(0);
	return (-1);
}

/*4th function implemented*/

int	check_order(t_list *key_list)
{
	int	i;
	int	j;

	count = 0;
	i = 0;

	while( i < key_list->ac-1)
	{
		if(key_list->stack_a[i] < key_list->stack_a[i+1])
			count++;
		i++;
	}

	if(i == j)
		return(-1);
	else
		return(0);

}

int	check_repeated_nums(t_list *key_list)
{
	int 	i;
	i = 0;

	while( i<= key_list-> size_a -1)
	{
		if(ft_check_repetition(key_list, key_list ->stack_a[i], i) == 1)
				i++;
		else
			return(-1)
	}
	retunr(0)
}

/*doubt if it shuld be static*/



