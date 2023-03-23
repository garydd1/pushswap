/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:04:28 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/23 22:45:10 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

int		ft_atoi(const char *str);
t_list	*ft_lstnew(int num);
void	ft_put_op(int i, int len, int code);
t_list	*ft_popart(t_list **stack);
int		ft_push(t_list **stack1, t_list **stack2, int code);
int		ft_is_sorted(t_list *stack);
int		ft_rotate(t_list **stack_a, t_list **stack_b, int code);

// MERGE SORT ----
void	ft_half(t_list **stack_a, t_list **stack_b, int len);
int		*ft_store_array(char **argv, int len);
int		ft_sort_array(int **array,int len);
int		ft_find_pivot(int *array, int len);
int		ft_divide_stack(t_list **stack_a, t_list **stack_b, int len, int pivot);
#endif
