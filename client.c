/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:25:32 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/15 15:52:55 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(char byte, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (byte >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

void	send_str(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_byte(str[i], pid);
		i++;
	}
	send_byte(0, pid);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac != 3)
	{
		ft_printf("./client [pid] [message]\n");
		exit(0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || pid > 4194304)
		return (0);
	str = av[2];
	send_str(str, pid);
	return (0);
}
