/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:15:08 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/23 17:29:31 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Checks if the stack is sorted in ascending values. 
 * 
 * @param stack 
 * @param len 
 * @return int 
 */
int	ft_is_sorted(t_list *stack)
{
	int	i;		
	t_list *aux;
	
	i = 0;
	aux = stack;
	while (stack->next != aux)
	{
		printf("%d ", stack->num);
		stack = stack -> next;
		if (stack->previous->num > stack->num)
			return (1);
		
	}
	return (0);
}