/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenech <fbenech@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:58:44 by fbenech           #+#    #+#             */
/*   Updated: 2025/12/07 03:55:33 by fbenech          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct s_thing
{
	int		*list_num;
	char	*int_max;
	char	*int_min;
}	t_thing;

typedef struct s_cost
{
	int		cost_a;
	int		cost_b;
	int		total;
}	t_cost;

typedef struct s_cheap
{
	int		pos;
	int		cheapest_pos;
	int		min_cost;
	int		size_a;
	int		size_b;
	int		element_b;
	int		target;
}	t_cheap;

typedef struct s_feur
{
	int		i;
	int		pos_b;
	int		element_b;
	int		target_pos;
	int		nbr_rota;
}	t_feur;

typedef struct s_main
{
	int		*num;
	int		*idx;
	int		size;
}	t_main;

int		count_words(char const *src, char c);
int		count_numbers(char **av);
int		*parsing(char **av);
int		*from_char_to_int(char **list, int size);
int		check_duplicate(int *list_num, int size);
int		is_there_char(char **list);
void	print_error(char *message);
int		int_min(char *str, char *i_min);
int		int_max(char *str, char *i_max);
int		is_it_too_big(char *str);
int		is_there_char(char **list);
void	reverse_rotate(t_list **stack1, char *message);
t_list	*get_the_one_before_last(t_list *lst);
void	pa(t_list **stack1, t_list **stack2, char *message);
void	sa(t_list **stack, char *message);
t_list	*fill_the_node(t_thing *thing);
void	rotate(t_list **stack, char *message);
int		*int_to_index(int *stack, int size);
int		is_sorted(t_list *stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack);
void	sort_two(t_list **stack);
t_list	*create_stack_from_array(int *arr, int size);
int		find_min_position(t_list *stack);
int		find_max_postion(t_list *stack);
int		find_target_postion(int element_b, t_list *stack_a);
void	ft_chunk(t_list **stack_a, t_list **stack_b);
void	ft_sort_to_a(t_list **stack_a, t_list **stack_b);
void	ft_medium_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	ft_clean_exit(t_list **stack_a, t_list **stack_b);
void	final_rotation(t_list **stack_a);
void	keep_sort_five(t_list **stack_a, t_list **stack_b);
void	aint_got_no_name(t_list **stack_a, t_list **stack_b);
void	final_rotation(t_list **stack_a);
void	aint_got_no_name(t_list **stack_a, t_list **stack_b);
void	keep_sort_five(t_list **stack_a, t_list **stack_b);
void	ft_clean_exit(t_list **stack_a, t_list **stack_b);
void	ft_chunk(t_list **stack_a, t_list **stack_b);
void	ft_sort_to_a(t_list **stack_a, t_list **stack_b);
void	ft_medium_sort(t_list **stack_a, t_list **stack_b);
void	ft_sort(t_list **stack_a, t_list **stack_b);
void	rotate_small_to_top(t_list **stack_a, int pos);
void	push_two_smallest(t_list **stack_a, t_list **stack_b);
void	ft_clean_node(t_list *stack);
int		find_small_pos(t_list *stack_a);
