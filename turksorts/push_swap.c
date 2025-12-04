/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 04:03:50 by felix             #+#    #+#             */
/*   Updated: 2025/12/04 04:25:13 by felix            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft/libft.h"

typedef struct s_thing
{
	int		**list_num;
	char	*int_max;
	char	*int_min;
}	t_thing;

typedef struct s_node
{
	int value;
	int index;
}	t_node;

int		count_words(char const *src, char c);
int		count_numbers(int ac, char **av);
int 	**parsing(int ac, char **av);
int		**from_char_to_int(char **list);
int		check_duplicate(int *list_num);
int		is_there_char(char **list);
void	print_error(char *message);
int		int_min(char *str, char *i_min);
int		int_max(char *str, char *i_max);
int		is_it_too_big(char *str);
int		is_there_char(char **list);
void	reverse_rotate(t_list **stack1, char *message);
t_list	*get_the_one_before_last(t_list **lst);
void	pa(t_list **stack1, t_list **stack2, char *message);
void	sa(t_list **stack, char *message);
t_list	*fill_the_node(t_thing *thing);
void	rotate(t_list **stack, char *message);
int		ft_intlen(int *in);
int    *int_to_index(int *stack, int size);
int		is_sorted(t_list **stack);
void	sort_five(t_list **stack_a, t_list **stack_b);
void	sort_four(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack);
void	sort_two(t_list **stack);
int     find_max_position(t_list *stack);
int     *find_min_position(t_list *stack);
