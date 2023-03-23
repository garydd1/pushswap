/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:35:33 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/22 23:05:47 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Extracts the top element of the linked list. 
 * returns the pointer to the extracted node(linked to itself).
 * @return t_list* 
 */
t_list	*ft_popart(t_list **stack)
{
	t_list	*popped;

	popped = (*stack);
	(*stack)->previous->next = (*stack)->next;
	(*stack)->next->previous = (*stack)->previous;
	(*stack) = (*stack)-> next;
	popped->next = popped;
	popped->previous = popped;
	return (popped);
}

/**
 * @brief Swaps the first two elements of the stack 1.
 * the first stack received will be the one swapped in cases 1 and 2. 
 * @param stack1 
 * @param stack2
 * @param code 1 for sa, 2 for sb, 3 for ss.
 * @return int 
 */
int	ft_swap(t_list **stack1, t_list **stack2, int code)
{
	int	buffer;

	buffer = (*stack1)->num;
	(*stack1)->num = (*stack1)->next->num;
	(*stack1)->next->num = buffer;
	if (code == 1)
		write(1, "sa\n", 3);
	if (code == 2)
		write(1, "sb\n", 3);
	if (code == 3)
	{
		buffer = (*stack2)->num;
		(*stack2)->num = (*stack2)->next->num;
		(*stack2)->next->num = buffer;
		write(1, "ss\n", 3);
	}
	return (0);
}

/**
 * @brief Takes the top element from one list 
 * and places it at the top of the other.
 * @param stack1 
 * @param stack2 
 * @param code 1 for push from stack_1 to stack_2 (pb). 
 * 2 for push from stack_2 to stack_1 (pa).
 * @return int 
 */
int	ft_push(t_list **stack1, t_list **stack2, int code)
{
	t_list	*aux;
	if ((*stack2) == NULL)
	{
		(*stack2) = ft_popart(&(*stack1));
		write(1, "pb\n", 3);
		return (0);
	}
	if (code == 1)
	{
		aux = ft_popart(&(*stack1));
		aux->next = (*stack2);
		aux->previous = (*stack2)->previous;
		(*stack2)->previous->next = aux;
		(*stack2)->previous = aux;
		(*stack2) = aux;
		write(1, "pb\n", 3);
	}
	if (code == 2)
	{
		aux = ft_popart(&(*stack2));
		aux->next = (*stack1);
		aux->previous = (*stack1)->previous;
		(*stack1)->previous->next = aux;
		(*stack1)->previous = aux;
		(*stack1) = aux;
		write(1, "pa\n", 3);
	}
	return (0);
}

/**
 * @brief Shifts up/down all elements of the stack. 
 * shift up: The first node becomes the last one.
 * shift down: The last node becomes the first one.
 * @param stack_a 
 * @param stack_b 
 * @param code 1 for ra. 2 for rb. 3 for rra. 4 for rrb. 
 * @return int 0 for succesfull. 
 */
int	ft_rotate(t_list **stack_a, t_list **stack_b, int code)
{
	if (code == 1)
	{
		write(1, "ra\n", 3);
		(*stack_a) = (*stack_a)->next;
	}
	if (code == 2)
	{
		write(1, "rb\n", 3);
		(*stack_b) = (*stack_b)->next;
	}
	if (code == 3)
	{
		write(1, "rra\n", 4);
		(*stack_a) = (*stack_a)->previous;
	}
	if (code == 4)
	{
		write(1, "rrb\n", 4);
		(*stack_b) = (*stack_b)->previous;
	}
	return (0);
}

/**
 * @brief revers
 * 
 */