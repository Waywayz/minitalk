/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:27:20 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/20 19:27:23 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_x(unsigned int n, const char *args)
{
	if (n >= 16)
	{
		print_x((n / 16), args);
		print_x((n % 16), args);
	}
	else if (n > 9)
	{
		if (args[1] == 'x')
			ft_putchar(n - 10 + 'a');
		if (args[1] == 'X')
			ft_putchar(n - 10 + 'A');
	}
	else
		ft_putchar(n + '0');
}
