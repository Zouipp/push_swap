/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 03:56:40 by felix             #+#    #+#             */
/*   Updated: 2025/12/04 03:57:03 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	exit (0);
}

int main(int ac, char **av)
{
	t_thing *thing;
	t_list	*stack_b;

	stack_b = NULL;
	thing->list_num = parsing(ac, av);
	check_duplicate(thing->list_num);
}