/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:01:26 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/27 21:55:55 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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

int	ft_medians_a(t_list **stack_a, t_list **stack_b, int *chunks, int *i)
{
	//MERGE
	int	*array; //NEED TO BE FREED
	int	q;
	int		pivot;
	
	pivot = 0;
	while (ft_lowest_len((*stack_a), 2) > 3 && (*i)++ >= 0)
	{
		q = 0;
		array = ft_store_array((*stack_a), ft_lowest_len((*stack_a), 2), &pivot);
		free(array);
		ft_divide_stack(&(*stack_a), &(*stack_b), pivot, &q);
		if (ft_lowest_len((*stack_a),2) < 4)
			ft_sort_three(&(*stack_a));
		ft_printlst((*stack_a));
		ft_printlst((*stack_b));
		chunks[*i - 1] = q;
		printf("\nchunk:'%d'. items: '%d'. pivot: '%d'\n", *i, q, pivot);
	}
	
	//END MERGE OKOKOKOKOKOKO CHECKPOINT
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list 	*stack_b;
	int chunks[100];
	int	i;

	stack_b = NULL;
	stack_a = ft_lstnew(ft_atoi(argv[1]));
	ft_stackify(&stack_a, argc - 1, argv);
	
	i = 0;
	ft_medians_a(&stack_a, &stack_b, chunks, &i);
	//B CHUNKS
	int j = 0;
	while (j++ < i)
		printf("\n chunk%d has:%d items\n", j, chunks[j-1]);
	//END BCHUNKS
	ft_printlst(stack_a);
	ft_printlst(stack_b);
	
	// ft_push(&(stack_b), &(stack_a), 2);
	// ft_push(&(stack_b), &(stack_a), 2);
	// ft_push(&(stack_b), &(stack_a), 2);
return (0);
}
