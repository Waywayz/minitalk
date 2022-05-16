/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:48:28 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/20 19:28:51 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

extern int	g_count;

void	print_s(char *str)
{
	int			i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		g_count += 6;
		return ;
	}
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}
