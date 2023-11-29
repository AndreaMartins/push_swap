/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:05:01 by andmart2          #+#    #+#             */
/*   Updated: 2023/11/29 17:47:21 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strlen(char *s)
{
	int	i;
	i = 0;
	while(s[i])
		i++;
	return(i);
}

void	ft_free(t_list *key_list)
{
	if(key_list)
	{
		if(key_list->stack_a)
		{
			free(key_list->stack_a);
		}
		if(key_list->stack_b)
		{
			free(key_list->stack_b);
		}
		if(key_list->stack_sort)
		{
			free(key_list->stack_sort);
		}
		free(key_list);
	}
	else
	{
		write(2, "Error\n", 6);
		/*some doubts about exit */
		exit(0);
	}
}

void	ft_freenull(t_list *key_list)
{
	if(key_list)
	{
		if(key_list->stack_a)
		{
			free(key_list->stack_a);
			key_list->stack_a = NULL;
		}
		if(key_list->stack_b)
		{
			free(key_list->stack_b);
			key_list->stack_b = NULL;
		}
		if(key_list->stack_sort)
		{
			free(key_list->stack_sort);
			key_list->stack_sort = NULL;
		}
	}
	exit(0);
}

long	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long int	nbr;

	nbr = 0;
	i = 0;
	sign = 1;

	/*(void)key_list;*/
	if(str[i] == '-' || str[i] == '+')
	{
		if(str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (str[i] == '0' && nbr == 0)
		{
			i++;
		}

		nbr = nbr *10 + str[i] - '0';
		i++;

		if(nbr > ((long long int)INT_MAX + 1) && sign == -1)
			ft_error();
		if(nbr > INT_MAX && sign == 1)
			ft_error();
	}
	printf("The value of nbr is: %lld\n", nbr * sign);
	return(nbr*sign);
}

void	ft_error()
{
	printf("\n Error");
}

void assign_index(int *stack, int size)
{
	int	index;
	int i;
	int max_value;
	int max_index;
	int j; 

	index = 0;
	i = 0;
	max_value = INT_MIN;
	max_index = -1;
	j = 0;

	while (i < size)
	{
		while(j < size)
		{
			if(stack[j] == INT_MIN && j == 0)
				j++;
			if(stack[j] > max_value && max_index == -1)
			{
				max_value = stack[j];
				max_index = j;
			}
			j++;
		}

		if(max_index != -1)
		{
			stack[max_index] = index;
			index++;
		}
		i++;
	}
}

/*void assign_index(int *stack, int size)
{
    int index = 0;
    int i = 0;

    // Handle the first element separately
    if (stack[0] != INT_MIN)
    {
        stack[0] = index;
        index++;
    }

    // Iterate over the rest of the elements using a while loop
    i = 1;
    while (i < size)
    {
        if (stack[i] != INT_MIN)
        {
            stack[i] = index;
            index++;
        }
        i++;
    }
}
*/
