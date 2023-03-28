/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackaops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 14:16:07 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/28 18:09:37 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_srt3a_aux(t_list **stack_a, t_list **stack_b, int *aux)
{
	if (aux[0] < aux[1] && aux[0] < aux[2])
	{
		if (aux[1] < aux[2])
			return (1);
		ft_rotate(&(*stack_a), &(*stack_b), 1);
		ft_swap(&(*stack_a), &(*stack_b), 1);
		ft_rotate(&(*stack_a), &(*stack_b), 3);
		return (1);
	}
	if (aux[0] > aux[1] && aux[0] > aux[2])
	{
		ft_swap(&(*stack_a), &(*stack_b), 1);
		ft_rotate(&(*stack_a), &(*stack_b), 1);
		ft_swap(&(*stack_a), &(*stack_b), 1);
		ft_rotate(&(*stack_a), &(*stack_b), 3);
		if (aux[1] > aux[2])
			ft_swap(&(*stack_a), &(*stack_b), 1);
		return (1);
	}
	return (0);
}

int	ft_srt3a(t_list **stack_a, t_list **stack_b)
{
	int	aux[3];
	
	if (ft_topchunk_len((*stack_a)) == 2)
	{
		ft_sort_two(&(*stack_a), &(*stack_b), 1);
		return (0);
	}
	aux[0] = (*stack_a)->num;
	aux[1] = (*stack_a)->next->num;
	aux[2] = (*stack_a)->next->next->num;
	if (ft_srt3a_aux(&(*stack_a), &(*stack_b), aux) == 1)
		return (0);
	if (aux[1] > aux[2])
	{
		ft_rotate(&(*stack_a), &(*stack_b), 1);
		ft_swap(&(*stack_a), &(*stack_b), 1);
		ft_rotate(&(*stack_a), &(*stack_b), 4);
	}
	ft_swap(&(*stack_a), &(*stack_b), 1);
	return (0);
}
