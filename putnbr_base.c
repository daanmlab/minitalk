/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabalm <dabalm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:27:23 by dabalm            #+#    #+#             */
/*   Updated: 2023/11/02 17:26:53 by dabalm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int get_int_len(long n, char *base)
{
    int baselen;
    int len;

    baselen = 0;
    while (base[baselen])
        baselen++;
    len = 0;
    while (n != 0)
    {
        n /= baselen;
        len++;
    }
    return (len);
}

int putnbr_base(long n, char *base)
{
    char *str;
    long long nb;
    int num_len;
    int base_len;
    int i;

    nb = n;
    if (nb == 0)
    {
        write(1, &"0", 1);
        return (1);
    }
    base_len = 0;
    if (nb < 0)
    {
        write(1, &"-", 1);
        nb = -nb;
    }
    while (base[base_len])
        base_len++;
    num_len = get_int_len(nb, base);
    str = ft_calloc(num_len, sizeof(char));
    i = 0;
    while (nb != 0) 
    {
        str[i] = base[nb % base_len];
        nb /= base_len;
        i++;
    }
    i--;
    while (i >= 0)
    {
        write(1, &str[i], 1);
        i--;
    }
    free(str);
    return(num_len + (n < 0));
}

// #include <limits.h>
// int	main(void)
// {
// 	char *base = "0123456789";
// 	long test = LONG_MIN;
// 	// printf("%d", get_int_len(test, base));
// 	// putnbr_base(test, base);
// 	printf("%li", test);
// }