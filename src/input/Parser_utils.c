/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 02:03:13 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/29 11:18:41 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	free_parsed(t_parsed *parsed)
{
	if (!parsed)
		return (1);
	if (parsed->sequence)
		free(parsed->sequence);
	if (parsed)
		free(parsed);
	return (0);
}

int	extract_strategy(char *strategy)
{
	if (ft_strcasecmp(strategy, "--adaptive") == 0)
		return (ADAPTIVE);
	if (ft_strcasecmp(strategy, "--simple") == 0)
		return (SIMPLE);
	if (ft_strcasecmp(strategy, "--medium") == 0)
		return (MEDIUM);
	if (ft_strcasecmp(strategy, "--complex") == 0)
		return (COMPLIX);
	return (0);
}

/*
	extract the flags out of the args
*/
void	extract_flags(t_parsed *parsed, int argc, char **args)
{
	int	arg;

	arg = 0;
	while (arg < argc)
	{
		if (ft_strncmp(args[arg], "--", 2) == 0)
		{
			if (extract_strategy(args[arg]))
				parsed->strategy = extract_strategy(args[arg]);
			else
				parsed->is_bench = true;
		}
		arg++;
	}
}
