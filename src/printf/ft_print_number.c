/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 00:39:41 by mohammah          #+#    #+#             */
/*   Updated: 2026/09/12 01:16:30 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(int fd, char c)
{
	write(fd, &c, 1);
}

int	ft_print_number(int fd, int number)
{
	int		count;
	long	long_num;

	long_num = number;
	count = 0;
	if (long_num < 0)
	{
		ft_write(fd, '-');
		long_num = -long_num;
		count++;
	}
	if (long_num >= 10)
		count += ft_print_number(fd, long_num / 10);
	ft_write(fd, long_num % 10 + '0');
	return (count + 1);
}
