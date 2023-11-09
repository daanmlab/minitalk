/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:35 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/03 16:48:18 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"


void test(int n, struct __siginfo *siginfo, void *context)
{
    static int i = 8;
    static unsigned char c = 0;
    (void) siginfo;
    (void) context;
    c <<= 1;
    if (n == SIGUSR2)
        c |= 1;
    i--;
    if(i == 0)
    {
        if (c)
            ft_putchar_fd(c, 1);
        i = 8;
        c = 0;
    }
}
int main(void)
{
    struct sigaction sa;

    ft_putnbr_fd(getpid(), 1);
    ft_putchar_fd('\n', 1);
    
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sa.sa_sigaction = test;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    
}