/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:39:01 by HoangPham         #+#    #+#             */
/*   Updated: 2019/11/18 22:49:15 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int nb;

    i = 0;
    nb = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    print_hex(int nb)
{
    if (nb > 16)
    {
        print_hex(nb / 16);
        print_hex(nb % 16);
    }
    if (nb < 10)
        ft_putchar(nb + 48);
    else if (nb < 16)
        ft_putchar(nb + 87);
}

int main(int argc, char **argv)
{
    if (argc == 2)
        print_hex(ft_atoi(argv[1]));
    write(1, "\n", 1);
    return (0);
}
