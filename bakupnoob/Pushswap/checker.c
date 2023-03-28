/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:15:08 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/27 21:25:38 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Checks if the stack is sorted in ascending values. 
 * 
 * @param stack 
 * @param len 
 * @return int 0 when sorted 1 when not sorted.
 */
int	ft_is_sorted(t_list *stack)
{
	int		i;		
	t_list	*aux;

	i = 0;
	aux = stack;
	while (stack->next != aux)
	{
		stack = stack -> next;
		if (stack->previous->num > stack->num)
			return (1);
	}
	return (0);
}

/**
 * @brief Checks if the stack contains nodes with
 * lower values than pivot.
 * @param stack 
 * @param pivot 
 * @param flag 1 for finding lowers. 2 for highers.
 * @return int 1 for true. 0 for false.
 */
int	ft_has_lower_higher(t_list *stack, int pivot, int flag)
{
	t_list	*aux;

	aux = stack;
	while (stack->next != aux)
	{
		if (flag == 1)
		{
			if (stack->next->num < pivot)
				return (1);
		}
		else if (flag == 2)
			if (stack->next->num > pivot)
				return (1);
		stack = stack->next;
	}
	if (flag == 1)
	{	
		if (stack->next->num < pivot)
			return (1);
	}
	else if (flag == 2)
		if (stack->next->num > pivot)
			return (1);
	return (0);
}
