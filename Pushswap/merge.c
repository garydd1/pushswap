/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:15:39 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/28 21:07:28 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Asumming the stack is always unsorted. 
 * sorts the stack of three nodes in the minimum steps.
 *in descending order
 * @param stack_a 
 */
void	ft_sort_three(t_list **stack_a)
{
	if (ft_is_sorted(*stack_a) == 0)
		return;
	if (FIRST > SECOND && FIRST > THIRD)
	{
		ft_rotate(&(*stack_a), NULL, 1);
		if (FIRST > SECOND)
			ft_swap(&(*stack_a), NULL, 1);
	}
	else if (FIRST < SECOND && FIRST < THIRD)
	{
		ft_rotate(&(*stack_a), NULL, 3);
		ft_swap(&(*stack_a), NULL, 1);
	}
	else
	{
		if (SECOND > THIRD)
			ft_rotate(&(*stack_a), NULL, 3);
		else
			ft_swap(&(*stack_a), NULL, 1);
	}
}

/**
 * @brief Returns the lowest number inside the stack.
 * or returns the len of the stack. The flag defines the return value.
 * @param stack
 * @param flag any for lowest. 2 for len.
 * @return int 
 */
int	ft_lowest_len(t_list *stack, int flag)
{
	t_list	*aux;
	int		lowest;
	int		len;
	
	len = 1;
	aux = (stack);
	lowest = (stack)->num;
	while ((stack)->next != aux)
	{
		if ((stack)->next->num < lowest)
			lowest = (stack)->next->num;
		(stack) = (stack)->next;
		len++;
	}
	if ((stack)->next->num < lowest)
		lowest = (stack)->next->num;
	if (flag == 2)
		return (len);
	return (lowest);
}

int	ft_sort_array(int **array, int len)
{
	int	i;
	int	j;
	int	aux;

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
				(*array)[j + 1] = aux;
			}
			j++;
		}
		i++;
	}
	return (0);
}
//CHECKPOINT!
int	*ft_store_array(t_list *stack, int len, int *pivot)
{
	int	*array;
	int	i;

	i = 1;
	array = (int *)malloc(sizeof(int) * len);
	array[0] = (stack)->num;
	while (i < len)
	{
		stack = stack->next;
		array[i] = stack->num;
		i++;
	}
	ft_sort_array(&array, len);
	if (len % 2 == 0)
		*pivot = array[(len / 2) - 1];
	else 
		*pivot = array[len / 2];
	return (array);
}
