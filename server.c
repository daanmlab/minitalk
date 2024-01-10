/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 20:36:54 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/14 21:34:46 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int				i = 7;
	static unsigned char	c = 0;

	(void)context;
	c <<= 1;
	c |= (signum == SIGUSR2);
	if (i == 0)
	{
		write(1, &c, 1);
		if (!c)
		{
			write(1, "\n", 1);
		}
		c = 0;
		i = 7;
		kill(info->si_pid, SIGUSR1);
		return ;
	}
	i--;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_sigaction = &sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
}
