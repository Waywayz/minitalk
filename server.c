/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:29:47 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/11 16:04:57 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	reset_all_data(void)
{
	g_data.i = 0;
	g_data.c = 0;
}

void	reset_str(void)
{
	free(g_data.str);
	g_data.str = NULL;
}

void	handler(int sig)
{
	sig -= SIGUSR1;
	g_data.c = g_data.c << 1 | sig;
	g_data.i++;
	if (g_data.i == 8)
	{
		if (g_data.c == 0)
		{
			ft_printf("%s", g_data.str);
			reset_str();
		}
		g_data.str = ft_strjoin(g_data.str, &g_data.c);
		reset_all_data();
	}
}

int	main(void)
{
	reset_all_data();
	ft_printf("pid = %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		sleep(1);
	return (0);
}
