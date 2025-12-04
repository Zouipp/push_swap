/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psuh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 03:55:50 by felix             #+#    #+#             */
/*   Updated: 2025/12/04 03:56:10 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*fill_the_node(t_thing *thing)
{
	int		i;
	t_list	*tmp;
	t_list	*stack_a;

	i = 0;
	stack_a = NULL;
	while (thing->list_num[i])
	{
		tmp = ft_lstnew(thing->list_num[i]);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&stack_a, tmp);
		i++;
	}
	return (stack_a);
}

t_list	*get_the_one_before_last(t_list **lst)
{
	if (!lst)
		return (NULL);
	while ((*lst) -> next && (*lst)->next->next)
		*lst = (*lst) -> next;
	return (*lst);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, NULL);
	sa(stack_b, NULL);
	ft_printf("ss\n");
}
void rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, NULL);
	rotate(stack_b, NULL);
	ft_printf("ss\n");
}
void rrb(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, NULL);
	reverse_rotate(stack_b, NULL);
	ft_printf("ss\n");
}