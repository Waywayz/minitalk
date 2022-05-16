/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:26:26 by rovillar          #+#    #+#             */
/*   Updated: 2022/04/15 15:53:33 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

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

void	handler2(int sig)
{
	sig = SIGUSR2;
	ft_printf("OK !");
	exit(0);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	signal(SIGUSR2, handler2);
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
	pause();
	return (0);
}
