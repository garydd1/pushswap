/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:38:30 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/27 22:06:25 by dgarizad         ###   ########.fr       */
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
 * @brief Takes the pivot and push all lower elements from a to b. 
 * or take all higher elements from b to a.
 * @param stack_a 
 * @param stack_b 
 * @param pivot 
 * @return int 
 */
int	ft_divide_stack(t_list **stack_a, t_list **stack_b, int pivot, int *q)
{
	while (ft_has_lower_higher((*stack_a), pivot, 1) == 1)
	{
		if ((*stack_a)->num < pivot)
		{
			ft_push(&(*stack_a), &(*stack_b), 1);
			(*q)++;
		}
		else if ((*stack_a)->previous->num < pivot)
			ft_rotate(&(*stack_a), &(*stack_b), 3);
		else
			ft_rotate(&(*stack_a), &(*stack_b), 1);
	}

	return (0);
}
