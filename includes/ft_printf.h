/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohammah <mohammah@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 16:26:24 by mohammah          #+#    #+#             */
/*   Updated: 2026/10/03 23:58:08 by mohammah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf( int fd, const char *input, ...);
int		ft_handle_conversion(int fd, char conversion, va_list args);
int		ft_print_char(int fd, int character);
int		ft_print_string(int fd, char *string);
int		ft_print_number(int fd, int number);
int		ft_print_number(int fd, int number);

#endif
