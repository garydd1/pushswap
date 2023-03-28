//ATENTION!!!!!!
// THIS FILE SHOULD BE DELETED BEFOR SUBMITING. HERE IS ONLY DEPRECATED CODE

#include "pushswap.h"
/**
 * @brief Writes to standard output the operation that should be done.
 * only for rra/rrb and ra/rb. 
 * @param i 
 * @param len 
 */
void	ft_put_op(int i, int len, int code)
{
	// write( 1, "SIU\n", 4);
	// printf("\nlen: '%d'. i: '%d'\n", len, i);
	if (i > len / 2)
	{
		// if (code == 1)
		// 	write(1, "rra\n", 4);
		// if (code == 2)
		// 	write(1, "rrb\n", 4);
		while (i++ <= len - 1)
			write(1, "rra\n", 4);
	}
	else if (i <= len / 2)
	{
		// if (code == 1)
		// 	write(1, "ra\n", 3);
		// if (code == 2)
		// 	write(1, "rb\n", 3);
		while (i -- > 0)
			write(1, "ra\n", 3);
	}
	// write(1, "pb\n", 3);
}


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
	int	j;
	int	aux;

	aux = len;
	while ((*stack_a)->next != (*stack_a))
	{
		j = ft_find_min(&(*stack_a));
		ft_put_op(j, len, 1);
		ft_push(&(*stack_a), &(*stack_b), 1);
		len--;
	}
	j = 0;
	while (j++ < aux - 1)
	{
		ft_push(&(*stack_b), &(*stack_a), 2);
	}
	return (0);
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