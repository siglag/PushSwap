/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 18:49:15 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/28 02:11:09 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

/*
	First of all, here we'll have all the:
	- functions prototypes
	- enums
	- structures
	- etc...
*/

enum e_strategies
{
	ADAPTIVE = 1,
	NORMAL = 2,
	MEDIUM = 3,
	COMPLIX = 4
};

typedef struct t_parsed
{
	int					*sequence;
	bool				is_bench;
	enum e_strategies	strategy;
}	t_parsed;

size_t		ft_strlen(char *str);
t_parsed	*parser(int argc, char **argv);
int			free_parsed(t_parsed *parsed);

#endif