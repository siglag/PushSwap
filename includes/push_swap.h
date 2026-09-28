/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:49:15 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/28 16:30:59 by sbanimou         ###   ########.fr       */
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
	COMPLIX
};

typedef struct t_parsed
{
	int					*sequence;
	size_t				sequence_size;
	bool				is_bench;
	enum e_strategies	strategy;
}						t_parsed;

size_t					ft_strlen(char *str);
char					**ft_split(char const *s, char c);
int						ft_atoi(const char *str);
char					*ft_strjoin(char const *s1, char const *s2);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
t_parsed				*parser(int argc, char **argv);
int						free_parsed(t_parsed *parsed);

#endif
