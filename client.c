/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:36:45 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/18 14:21:42 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int		g_go = 1;

void	send_char(unsigned char c, int pid)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		while (!g_go)
		{
			pause();
		}
		g_go = 0;
		if (!(c & 128))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		c <<= 1;
		i--;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	g_go = 1;
}

void	send_string(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(str[i++], pid);
	}
	send_char(0, pid);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	sa.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
	{
		return (0);
	}
	send_string(argv[2], ft_atoi(argv[1]));
}
