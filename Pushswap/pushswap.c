/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:01:26 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/23 23:32:26 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Iterates the stack each time the function is called
 * returns the index of the minimum value and points the head 
 *of the stack to it. 
 * @param stack 
 * @return int 
 */
int	ft_find_min(t_list **stack)
{
	t_list	*aux;
	t_list	*min;
	int		i;
	int		j;

	aux = (*stack);
	min = (*stack);
	i = 0;
	j = 0;
	while ((*stack)-> next != aux && i++ >= 0)
	{
		(*stack) = (*stack)-> next;
		if ((*stack)-> num < min -> num)
		{
			min = (*stack);
			j = i;
		}
	}
	if ((*stack)-> num < min -> num)
	{
		min = (*stack);
		j = i;
	}
	(*stack) = min;
	return (j);
}

void	ft_stackify(t_list **stack_a, int len, char **argv)
{
	t_list	*last;
	int		i;		

	i = 1;
	(*stack_a) = ft_lstnew(ft_atoi(argv[1]));
	last = (*stack_a);
	while (i < len)
	{
		last -> next = ft_lstnew(ft_atoi(argv[i + 1]));
		last -> next -> previous = last;
		last = last -> next;
		i++;
	}
	(*stack_a)-> previous = last;
	last -> next = (*stack_a);
}

void	ft_printlst(t_list *stack)
{
	t_list	*aux;

	printf("\n\n[");
	aux = stack;
	while (stack->next != aux)
	{
		printf("%d ", stack->num);
		stack = stack -> next;
	}
	printf("%d]\n", stack->num);
}

/**
 * @brief Non effiecient way to sort. 
 * finds the minimum value of the whole stack a and send it to
 * stack b.
 * @param stack_a 
 * @param len 
 * @return int 
 */
int	ft_mysort(t_list **stack_a, t_list **stack_b, int len)
{
	int j;
	int	aux;
	
	aux = len;
	while ((*stack_a)->next != (*stack_a))
	{
		j = ft_find_min(&(*stack_a));
		ft_put_op(j, len, 1);
		//ft_popart(&(*stack_a));
		ft_push(&(*stack_a), &(*stack_b), 1);
		len--;
	}
	j = 0;
	while (j++ < aux - 1)
	{
		ft_push(&(*stack_a), &(*stack_b), 2);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list  *stack_b;
	int		pivot;

	stack_b = NULL;
	stack_a = ft_lstnew(ft_atoi(argv[1]));
	ft_stackify(&stack_a, argc - 1, argv);
	//ft_printlst(stack_a);
	// MERGE
	int	*array; //NEED TO BE FREED
	array = ft_store_array(argv, argc - 1);
	pivot = ft_find_pivot(array, argc - 1);
	free(array);
	ft_divide_stack(&stack_a, &stack_b, argc - 1, pivot);
	//ft_half(&stack_a, &stack_b, argc -1);
	//END MERGE
	//ft_printlst(stack_a);
	//ft_mysort(&stack_a, &stack_b, argc - 1);
	// ft_push(&stack_a, &stack_b, 1);
	//  ft_printlst(stack_a);
	//ft_printlst(stack_b);
	// ft_push(&stack_a, &stack_b, 1);
	// ft_push(&stack_a, &stack_b, 1);
	// ft_printlst(stack_a);
	// ft_printlst(stack_b);
	// printf("\nHERE: '%d'\n", stack_a->next->next->next->next->next->next->num);
	return (0);
}
