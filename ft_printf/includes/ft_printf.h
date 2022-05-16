/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:28:25 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/20 19:38:39 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
void	print_s(char *str);
void	print_i(int n);
void	print_x(unsigned int n, const char *args);
void	print_u(unsigned int n);
void	print_p(unsigned long long ptr);
void	ft_putchar(char c);

#endif
