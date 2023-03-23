/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:38:30 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/23 23:43:36 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	ft_is_num(char str)
{
	int	flag;

	flag = 1;
	if (str < 48 || str > 57)
		flag = 0;
	return (flag);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	digit;
	int	number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
	{
		str++;
	}
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			sign *= -1;
		str++;
	}
	while (ft_is_num(str[i]) == 1)
	{
		digit = str[i++] - '0';
		number = (number * 10) + digit;
	}
		number = number * sign;
	return (number);
}

/**
 * @brief Creates a new node with the int value passed as parameter. 
 * 
 * @param num 
 * @return t_list* 
 */
t_list	*ft_lstnew(int num)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> num = num;
	new_node -> next = NULL;
	new_node -> previous = NULL;
	return (new_node);
}

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
			write( 1, "rra\n", 4);
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

int	ft_divide_stack(t_list **stack_a, t_list **stack_b, int len, int pivot)
{
	int	i;
	t_list *aux;

	i = 0;
	aux =(*stack_a);
	while(i++ < len)
	{
		if((*stack_a)->num < pivot)
			ft_push(&(*stack_a), &(*stack_b), 1);
		else
			ft_rotate(&(*stack_a), &(*stack_b), 1); 	
	}	
	return (0);
}
