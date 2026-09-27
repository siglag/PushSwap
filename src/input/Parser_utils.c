/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 02:03:13 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/28 02:09:55 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_parsed(t_parsed *parsed)
{
	if (!parsed)
		return (1);
	if (*parsed->sequence)
		free(*parsed->sequence);
	if (parsed->strategy)
		free(parsed->strategy);
	if (parsed)
		free(parsed);
	return (0);
}
