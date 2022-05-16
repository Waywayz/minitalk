/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 19:27:25 by rovillar          #+#    #+#             */
/*   Updated: 2022/03/04 19:28:46 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "./ft_printf/includes/ft_printf.h"
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	char	c;
	char	*str;
}	t_data;

int		ft_printf(const char *input, ...);
int		ft_atoi(const char *nptr);
void	send_str(char *str, int pid);
void	send_byte(char byte, int pid);
void	reset_all_data(void);
void	handler_sig(int signum, siginfo_t *info, void *context);

#endif
