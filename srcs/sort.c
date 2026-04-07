/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 19:53:54 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:46:01 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if ((int)(long)stack->next->content < (int)(long)stack->content)
			return (0);
		else
			stack = stack->next;
	}
	return (1);
}

void	sort_two(t_list **stack)
{
	if (is_sorted(*stack))
		return ;
	else
		sa(stack, "sa");
}

void	sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	if (is_sorted(*stack))
		return ;
	a = (int)(long)(*stack)->content;
	b = (int)(long)(*stack)->next->content;
	c = (int)(long)(*stack)->next->next->content;
	if (a == 2 && b == 1 && c == 0)
	{
		rotate(stack, "ra");
		sa(stack, "sa");
	}
	else if (a == 0 && b == 2 && c == 1)
	{
		reverse_rotate(stack, "rra");
		sa(stack, "sa");
	}
	else if (a == 1 && b == 2 && c == 0)
		reverse_rotate(stack, "rra");
	else if (a == 1 && b == 0 && c == 2)
		sa(stack, "sa");
	else
		rotate(stack, "ra");
}

void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int		pos;
	int		i;

	if (is_sorted(*stack_a))
		return ;
	i = 0;
	pos = 0;
	tmp = *stack_a;
	while (tmp)
	{
		if ((int)(long)tmp->content == 0)
			pos = i;
		tmp = tmp->next;
		i++;
	}
	if (pos <= 2)
		while ((int)(long)(*stack_a)->content != 0)
			rotate(stack_a, "ra");
	else
		while ((int)(long)(*stack_a)->content != 0)
			reverse_rotate(stack_a, "rra");
	pa(stack_b, stack_a, "pb");
	sort_three(stack_a);
	pa(stack_a, stack_b, "pa");
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	push_two_smallest(stack_a, stack_b);
	sort_three(stack_a);
	if (*stack_b && (*stack_b)->next && (int)(long)(*stack_b)->content
		< (int)(long)(*stack_b)->next->content)
		sa(stack_b, "sb");
	pa(stack_a, stack_b, "pa");
	pa(stack_a, stack_b, "pa");
}
