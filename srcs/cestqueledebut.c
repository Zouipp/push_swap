/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cestqueledebut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 23:49:30 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:45:17 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_clean_node(t_list *stack)
{
	t_list	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

void	ft_clean_exit(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && stack_b)
	{
		ft_clean_node(*stack_a);
		stack_a = NULL;
		ft_clean_node(*stack_b);
		stack_b = NULL;
	}
	exit(1);
}

void	final_rotation(t_list **stack_a)
{
	int	min_pos;
	int	size;

	min_pos = find_min_position(*stack_a);
	size = ft_lstsize(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			rotate(stack_a, "ra");
			min_pos--;
		}
	}
	else
	{
		while (min_pos < size)
		{
			reverse_rotate(stack_a, "rra");
			min_pos++;
		}
	}
}

void	aint_got_no_name(t_list **stack_a, t_list **stack_b)
{
	sort_three(stack_a);
	if (*stack_b && (*stack_b)->next && (int)(long)(*stack_b)->content
		< (int)(long)(*stack_b)->next->content)
		sa(stack_b, "sb");
	pa(stack_a, stack_b, "pa");
	pa(stack_a, stack_b, "pa");
}

void	keep_sort_five(t_list **stack_a, t_list **stack_b)
{
	sort_three(stack_a);
	if (*stack_b && (*stack_b)->next && (int)(long)(*stack_b)->content
		< (int)(long)(*stack_b)->next->content)
		sa(stack_b, "sb");
	pa(stack_a, stack_b, "pa");
	pa(stack_a, stack_b, "pa");
}
