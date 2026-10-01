/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:49:15 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/01 15:33:08 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h> //for bool
# include <stdlib.h>
# include <unistd.h>

/*
	First of all, here we'll have all the:
	- functions prototypes
	- enums
	- structures
	- etc...
*/

enum					e_strategies
{
	ADAPTIVE = 1,
	SIMPLE = 2,
	MEDIUM = 3,
	COMPLEX = 4
};

typedef struct s_stack
{
	int					*a;
	int					*b;
	int					size_a;
	int					size_b;
}						t_stack;

typedef struct s_parsed
{
	int					*sequence;
	size_t				sequence_size;
	bool				is_bench;
	enum e_strategies	strategy;
	t_operations		*operations;
	double				disorder;
}						t_parsed;

typedef struct s_operations
{
	sa;
	sb;
	ss;
	pa;
	pb;
	ra;
	rb;
	rr;
	rra;
	rrb;
	rrr;
}						t_operations;

t_stack					*init_stack(t_parsed *parsed);
//  OPERATIONS
void					sa(t_stack *stack);
void					sb(t_stack *stack);
void					ss(t_stack *stack);
void					pa(t_stack *stack);
void					pb(t_stack *stack);
void					ra(t_stack *stack);
void					rb(t_stack *stack);
void					rr(t_stack *stack);
void					rra(t_stack *stack);
void					rrb(t_stack *stack);
void					rrr(t_stack *stack);

size_t					ft_strlen(const char *str);
char					**ft_split(char const *s, char c);
t_parsed				*parser(int argc, char **argv);
int						free_parsed(t_parsed *parsed);
int						ft_isdigit(char *character);
int						ft_strncmp(char *s1, char *s2, size_t n);
int						validate_format(int argc, char **argv);
char					ft_tolower(char character);
int						ft_strcasecmp(char *s1, char *s2);
int						validate_ordering(int argc, char **argv);
int						validate_flag(char *flag);
int						extract_flags(t_parsed *parsed, int argc, char **args);
int						extract_strategy(char *strategy);
int						ft_atoi(char *str, int *result);
int						extract_sequence(t_parsed *parsed,
							int argc, char **args);
int						count_numbers(char *str);
int						extract_numbers(int *sequence, int argc, char **argv);
char					**ft_split(char const *str, char c);
char					*ft_substr(char const *s,
							unsigned int start, size_t len);
void					free_words(char **result, int count);
int						extract_token(int *sequence,
							char **numbers, int *index);

#endif
