/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackbops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:48:26 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/27 23:30:49 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_div_stckb(t_list **stack_a, t_list **stack_b, int pivot)
{	
	while (ft_has_lower_higher((*stack_b), pivot, 2) == 1)
	{
		if ((*stack_b)->num > pivot)
			ft_push(&(*stack_b), &(*stack_a), 2);
		else if ((*stack_b)->previous->num > pivot)
			ft_rotate(&(*stack_a), &(*stack_b), 4);
		else
			ft_rotate(&(*stack_a), &(*stack_b), 2);
	}
	return (0);
}

/**
 * @brief Sorts the top two element of the stack.
 * 
 * @param stack 
 * @param flag 1 for ascending (stack_a) 2 fir descending (stack_b)
 */
int	ft_sort_two(t_list **stack_a, t_list **stack_b, int flag)
{
	if (flag == 1)
		if ((*stack_a)->num > (*stack_a)->next->num)
			ft_swap(&(*stack_a), NULL, 1);
	if (flag == 2)
	{
		if ((*stack_b)->num < (*stack_b)->next->num)
			ft_swap(&(*stack_b), NULL, 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
	}
	return (0);
}

/**
 * @brief Auxiliary function for sorting top three elements
 * of stack_b. 
 * @param stack_a 
 * @param stack_b 
 * @param aux 
 * @return int returns 1 if it sorted the stack.  
 */
static int	ft_srt3b_aux(t_list **stack_a, t_list **stack_b, int *aux)
{
	if (aux[0] > aux[1] && aux[0] > aux[2])
	{
		ft_push(&(*stack_b), &(*stack_a), 2);
		if (aux[1] < aux[2])
			ft_swap(&(*stack_b), &(*stack_a), 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
		return (1);
	}
	if (aux[0] < aux[1] && aux[0] < aux[2])
	{
		ft_rotate(&(*stack_a), &(*stack_b), 2);
		if (aux[1] < aux[2])
			ft_swap(&(*stack_b), &(*stack_a), 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
		ft_rotate(&(*stack_a), &(*stack_b), 4);
		ft_push(&(*stack_b), &(*stack_a), 2);
		return (1);
	}
	return (0);
}
/**
 * @brief sorts top 3 elements 
 * and Push from stack b to stack a.
 * @param stack_a 
 * @param stack_b 
 * @param flag 
 * @return int 
 */

int	ft_srt3b(t_list **stack_a, t_list **stack_b)
{
	int	aux[3];

	aux[0] = (*stack_b)->num;
	aux[1] = (*stack_b)->next->num;
	aux[2] = (*stack_b)->next->next->num;
	if (ft_srt3b_aux(&(*stack_a), &(*stack_b), aux) == 1)
		return (0);
	if (aux[1] < aux[2])
	{
		ft_rotate(&(*stack_a), &(*stack_b), 2);
		ft_swap(&(*stack_b), &(*stack_a), 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
		ft_rotate(&(*stack_a), &(*stack_b), 4);
		ft_push(&(*stack_b), &(*stack_a), 2);
		ft_push(&(*stack_b), &(*stack_a), 2);
		return (0);
	}
	ft_swap(&(*stack_b), &(*stack_a), 2);
	ft_push(&(*stack_b), &(*stack_a), 2);
	ft_push(&(*stack_b), &(*stack_a), 2);
	ft_push(&(*stack_b), &(*stack_a), 2);
	return (0);
}
