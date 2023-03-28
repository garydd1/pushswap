/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:01:26 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/28 19:36:13 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/**
 * @brief Transforms the input list in a circular linked list. 
 * 
 * @param stack_a 
 * @param len 
 * @param argv 
 */
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
 * @brief Counts the number of nodes of the highest chunk
 * of the stack.
 * @param stack 
 * @return int 
 */
int	ft_topchunk_len(t_list *stack)
{
	t_list	*aux;
	int		i;
	
	i = 0;
	aux = stack;
	while (aux->chunk == stack->chunk)
	{
		stack = stack->next;
		i++;
		if (i == ft_lowest_len(stack, 2))
			return(i);
	}
	return (i);
}
/**
 * @brief Obtains the median of the stack_a and
 * pushes any lower node to the stack_b until stack_a can be sort.
 * len < 4.
 * @param stack_a 
 * @param stack_b 
 * @param chunks 
 * @param i 
 * @return int 
 */
int	ft_medians_a(t_list **stack_a, t_list **stack_b, int *chunks, int *i)
{
	int	*array; //NEED TO BE FREED
	int	q;
	int		pivot;
	
	pivot = 0;
	while (ft_topchunk_len((*stack_a)) > 3 && (*i)++ >= 0)
	{
		q = 0;
		array = ft_store_array((*stack_a), ft_topchunk_len((*stack_a)), &pivot);
		free(array); //FREED HERE
		ft_divide_stack(&(*stack_a), &(*stack_b), pivot, &q, &(*i));
		if (ft_lowest_len((*stack_a),2) < 4)
			ft_sort_three(&(*stack_a));
		if (ft_topchunk_len((*stack_a)) < 4)
			ft_srt3a(&(*stack_a), &(*stack_b));
		ft_printlst((*stack_a));
		ft_printlst((*stack_b));
		chunks[*i - 1] = q;
		printf("\nchunk:'%d'. items: '%d'. pivot: '%d'\n", *i, q, pivot);
	}
	return (0);
}

int	ft_medians_b(t_list **stack_a, t_list **stack_b, int *i)
{
	int	*array; //NEED TO BE FREED
	int		pivot;
	//GET HIGHER CHUNK
		while (ft_topchunk_len(*stack_b) < 4)
		{
			if (ft_topchunk_len(*stack_b) == 1)
				ft_push(&(*stack_b), &(*stack_a), 2);
			else if (ft_topchunk_len(*stack_b) == 2)
				ft_sort_two(&(*stack_a), &(*stack_b), 2);
			else
				ft_srt3b(&(*stack_a), &(*stack_b));
		}	
	// END GET HIGHER CHUNK
	// SEND MEDIANS FROM B TO A
	if (ft_topchunk_len(*stack_b) > 3)
	{
		array = ft_store_array(*stack_b, ft_topchunk_len(*stack_b), &pivot);	
		free(array);
		(*i)++;
		ft_div_stack_b(&(*stack_a), &(*stack_b), pivot, &(*i));
	}
	//END SEND MEDIANS FROM B TO A
	return (0);
}

int	ft_print_chunks(t_list *stack)
{
	t_list	*aux;

	aux = stack;
	while (stack->next != aux)
	{
		printf(" chunk:%d", stack->chunk);
		stack = stack->next;
	}
	printf(" chunk: %d ", stack->chunk);
	return (0);
}
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list 	*stack_b;
	int chunks[100];
	int	i;

	stack_b = NULL;
	stack_a = ft_lstnew(ft_atoi(argv[1])); //NEED TO BE FREED
	ft_stackify(&stack_a, argc - 1, argv);
	
	i = 0;
	// FIRST STEP
	ft_medians_a(&stack_a, &stack_b, chunks, &i);
	//FOR VIUEWVING
	printf("\n111111111\n");
	ft_printlst(stack_a);
	ft_printlst(stack_b);
	ft_print_chunks(stack_a);
	printf("\n total chunks: %d\n", i);
	ft_print_chunks(stack_b);
	printf("\n111111111\n");
	//B CHUNKS
	int j = 0;
	while (j++ < i)
		printf("\n chunk%d has:%d items\n", j, chunks[j-1]);
	printf("\ntop chunk len: '%d'\n", ft_topchunk_len(stack_a));
	//END BCHUNKS
	
	//PAY ATTENTION TO DISCOVER THE  RECURSIVITY FROM HERE
	printf("\n AQUI 1\n");
	ft_medians_b(&stack_a, &stack_b, &i);
	printf("\n AQUI 21\n");
	//RECHECK A FOR UNSORTED CHUNKS (MEDIANS FROM B)
	if (ft_is_sorted(stack_a) != 0)
	{
		printf("\ntop chunk len: '%d'\n", ft_topchunk_len(stack_a));
		if (ft_topchunk_len(stack_a) < 4)
			ft_srt3a(&(stack_a), &(stack_b));
		else 
			ft_medians_a(&(stack_a), &(stack_b), chunks, &i);
	}
	// IF A IS SORTED AND B HAS CHUNKS!
		ft_medians_b(&stack_a, &stack_b, &i);
	
	if (ft_is_sorted(stack_a) != 0)
	{
		printf("\ntop chunk len: '%d'\n", ft_topchunk_len(stack_a));
		ft_printlst(stack_a);
		if (ft_topchunk_len(stack_a) < 4)
			ft_srt3a(&(stack_a), &(stack_b));
		else 
			ft_medians_a(&(stack_a), &(stack_b), chunks, &i);
	}
	ft_printlst(stack_a);
	ft_printlst(stack_b);
	ft_print_chunks(stack_a);
	printf("\n\n");
	ft_print_chunks(stack_b);
	// ft_push(&(stack_b), &(stack_a), 2);
	// ft_push(&(stack_b), &(stack_a), 2);
	// ft_push(&(stack_b), &(stack_a), 2);
return (0);
}
