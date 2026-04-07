/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 22:08:40 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 04:00:02 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	rotate(t_list **stack, char *message)
{
	t_list	*frst;
	t_list	*lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	frst = *stack;
	lst = ft_lstlast(*stack);
	*stack = frst->next;
	frst->next = NULL;
	lst->next = frst;
	if (message)
		ft_printf("%s\n", message);
	return ;
}

void	reverse_rotate(t_list **stack1, char *message)
{
	t_list	*last;
	t_list	*before_last;

	last = ft_lstlast(*stack1);
	before_last = get_the_one_before_last(*stack1);
	before_last->next = NULL;
	last->next = *stack1;
	*stack1 = last;
	if (message)
		ft_printf("%s\n", message);
	return ;
}

void	pa(t_list **stack1, t_list **stack2, char *message)
{
	t_list	*tmp;

	if (!stack2 || !*stack2)
		return ;
	tmp = *stack2;
	*stack2 = (*stack2)->next;
	tmp->next = *stack1;
	*stack1 = tmp;
	if (message)
		ft_printf("%s\n", message);
	return ;
}

void	sa(t_list **stack, char *message)
{
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	if (message)
		ft_printf("%s\n", message);
	return ;
}

void	ft_sort_to_a(t_list **stack_a, t_list **stack_b)
{
	int		pos;
	int		size;

	while (*stack_b)
	{
		pos = find_max_postion(*stack_b);
		size = ft_lstsize(*stack_b);
		if (pos <= size / 2)
		{
			while (pos > 0)
			{
				rotate(stack_b, "rb");
				pos--;
			}
		}
		else
		{
			while (pos < size)
			{
				reverse_rotate(stack_b, "rrb");
				pos++;
			}
		}
		pa(stack_a, stack_b, "pa");
	}
}