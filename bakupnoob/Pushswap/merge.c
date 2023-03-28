/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:15:39 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/27 19:38:14 by dgarizad         ###   ########.fr       */
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

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int		min;
	int		i;
	
	i = 1;
	while (ft_lowest_len(*stack_a, 2) > 3)
	{
		min = ft_lowest_len(*stack_a, 1);
		if (i-- > 0 && THIRD == min)
			ft_rotate(&(*stack_a), NULL, 1);
		if (FIRST == min)
			ft_push(&(*stack_a), &(*stack_b), 1);
		else if (SECOND == min)
			ft_rotate(&(*stack_a), NULL, 1);
		else
			ft_rotate(&(*stack_a), NULL, 3);
	}
	ft_sort_three(&(*stack_a));
	ft_push(&(*stack_b), &(*stack_a), 2);
	ft_push(&(*stack_b), &(*stack_a), 2);
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
