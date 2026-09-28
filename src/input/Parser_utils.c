/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/28 02:03:13 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/28 17:10:48 by mohammah         ###   ########.fr       */
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

int	validate_format(int argc, char **argv)
{
	int	arg;
	int	flags;
	int	last_is_digit;

	last_is_digit = 0;
	arg = 1;
	flags = 0;
	while (arg < argc)
	{
		if (ft_strncmp(argv[arg], "--", 2) == 0)
		{
			if (last_is_digit)
				return (-1);
			last_is_digit = 0;
			flags++;
		}
		else if (ft_isdigit(argv[arg]))
			last_is_digit = 1;
		else
			return (-1);
		arg++;
	}
	if (flags > 2)
		return (-1);
	return (1);
}
