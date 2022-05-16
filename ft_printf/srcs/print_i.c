/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:50:21 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/20 19:33:18 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

extern int	g_count;

void	print_i(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		g_count += 11;
	}
	else if (n < 0)
	{
		ft_putchar('-');
		print_i(n * -1);
	}
	else if (n >= 10)
	{
		print_i(n / 10);
		print_i(n % 10);
	}
	else
		ft_putchar(n + 48);
}
