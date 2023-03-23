/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:15:39 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/23 22:18:11 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_half(t_list **stack_a, t_list **stack_b, int len)
{
	int	i;

	i = 0;
	while (i++ < len/2)
	{
		ft_push(&(*stack_a), &(*stack_b), 1);
	}
}

int	ft_sort_array(int **array,int len)
{
	int i;
	int j;
	int aux;
	
	i = 0;
	aux = (*array)[0];
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if ((*array)[j] > (*array)[j + 1])
			{
				aux = (*array)[j];
				(*array)[j] = (*array)[j + 1];
				(*array) [j + 1] = aux;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	*ft_store_array(char **argv, int len)
{
	int *array;
	int	i;

	i = 1;
	array = (int *)malloc(sizeof(int) * len);
	array[0] = ft_atoi(argv[1]);
	while (i < len)
	{
		array[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	ft_sort_array(&array, len);
	return(array);
}

int	ft_find_pivot(int *array, int len)
{
	return (array[len/2]);
}