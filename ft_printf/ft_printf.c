/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:22:46 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/21 16:45:01 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		g_count = 0;

void	ft_putchar(char c)
{
	write(1, &c, 1);
	g_count++;
}

static void	check_arg(char *str, va_list args)
{
	int			i;

	i = 0;
	if (str[i + 1] == 'c')
		ft_putchar(va_arg(args, int));
	if (str[i + 1] == 's')
		print_s(va_arg(args, char *));
	if (str[i + 1] == 'p')
		print_p(va_arg(args, unsigned long long));
	if (str[i + 1] == 'd')
		print_i(va_arg(args, int));
	if (str[i + 1] == 'i')
		print_i(va_arg(args, int));
	if (str[i + 1] == 'u')
		print_u(va_arg(args, unsigned int));
	if (str[i + 1] == 'x' || str[i + 1] == 'X')
		print_x(va_arg(args, int), str);
	if (str[i + 1] == '%')
		ft_putchar('%');
}

static void	check_file(char *str, va_list args)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			check_arg(str + i, args);
			i++;
		}
		else if (str[i] != '%')
			ft_putchar(str[i]);
		i++;
	}
}

int	ft_printf(const char *input, ...)
{
	char		*str;
	va_list		args;
	int			ret;

	str = ft_strdup(input);
	va_start(args, input);
	check_file(str, args);
	va_end(args);
	free(str);
	ret = g_count;
	g_count = 0;
	return (ret);
}
