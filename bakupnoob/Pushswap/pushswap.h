/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 13:04:28 by dgarizad          #+#    #+#             */
/*   Updated: 2023/03/27 22:06:35 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H
# define FIRST (*stack_a)->num
# define SECOND (*stack_a)->next->num
# define THIRD (*stack_a)->next->next->num
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

// UTILS
int		ft_atoi(const char *str);
t_list	*ft_lstnew(int num);
int		ft_divide_stack(t_list **stack_a, t_list **stack_b, int pivot, int *q);
// OPERATIONS CECH POINT!!!
t_list	*ft_popart(t_list **stack);
int		ft_swap(t_list **stack1, t_list **stack2, int code);
int		ft_push(t_list **stack1, t_list **stack2, int code);
int		ft_rotate(t_list **stack_a, t_list **stack_b, int code);

//CHECKERS
int		ft_is_sorted(t_list *stack);
int		ft_has_lower_higher(t_list *stack, int pivot, int flag);

// MERGE SORT ----
void	ft_sort_three(t_list **stack_a);
int		ft_lowest_len(t_list *stack, int flag);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
int		*ft_store_array(t_list *stack, int len, int *pivot);
int		ft_sort_array(int **array,int len);

//STACK A-B OPERATIONS
int		ft_srt3a(t_list **stack_a, t_list **stack_b);
int		ft_srt3b(t_list **stack_a, t_list **stack_b);
#endif
