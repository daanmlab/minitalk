/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 11:52:32 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/03 17:02:13 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void sent_char(char c, int pid)
{
    int i;

    i = 8;
    while (i > 0)
    {
        ft_putchar_fd((c & 128) ? '1' : '0', 1);
        if (!(c & 128))
            kill(pid, SIGUSR1); // 0
        else
            kill(pid, SIGUSR2); // 1
        c = c << 1;
        i--;
        usleep(42);
    }
}

void send_string(char *str, int pid)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        sent_char(str[i], pid);
        ft_putchar_fd('\n', 1);
        i++;
    }
    sent_char('\0', pid);
    kill(pid, SIGUSR2);
}

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 0;
    send_string(argv[2], ft_atoi(argv[1]));
}

