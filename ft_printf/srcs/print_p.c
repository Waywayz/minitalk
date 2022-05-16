/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:27:30 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/20 19:45:38 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

extern int	g_count;

static void	print(unsigned long long n)
{
	if (n >= 16)
	{
		print(n / 16);
		print(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
}

void	print_p(unsigned long long ptr)
{
	write(1, "0x", 2);
	g_count += 2;
	if (ptr == 0)
		ft_putchar('0');
	else
		print(ptr);
}
