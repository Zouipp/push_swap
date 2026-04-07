/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 00:33:28 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:43:21 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	init_parsing(t_main *main, char **av);
static void	cleanup_stacks(t_list **stack_a, t_list **stack_b);

void	print_error(char *message)
{
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	exit(1);
}

int	get_array_size(char **av)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (av[i])
	{
		count += count_words(av[i], ' ');
		i++;
	}
	return (count);
}

static void	init_parsing(t_main *main, char **av)
{
	main->num = parsing(av);
	if (!main->num)
		print_error("Error");
	if (!check_duplicate(main->num, main->size))
	{
		free(main->num);
		print_error("Error");
	}
	main->idx = int_to_index(main->num, main->size);
	if (!main->idx)
		print_error("Error");
}

static void	cleanup_stacks(t_list **stack_a, t_list **stack_b)
{
	if (stack_a && *stack_a)
		ft_lstclear(stack_a, NULL);
	if (stack_b && *stack_b)
		ft_lstclear(stack_b, NULL);
}

int	main(int ac, char **av)
{
	t_main	main;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	main.size = get_array_size(av);
	if (main.size == 0)
		print_error("Error");
	init_parsing(&main, av);
	stack_a = create_stack_from_array(main.idx, main.size);
	if (!stack_a)
		print_error("Error");
	ft_sort(&stack_a, &stack_b);
	cleanup_stacks(&stack_a, &stack_b);
	return (0);
}
