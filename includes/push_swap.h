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
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
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

size_t					ft_strlen(char *str);
char					**ft_split(char const *s, char c);
int						ft_atoi(const char *str);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
t_parsed				*parser(int argc, char **argv);
int						free_parsed(t_parsed *parsed);
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
#endif
