/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 08:51:50 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/17 09:15:52 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int i;
    int nb;

    i = 0;
    nb = 0;
    if (str[0] == '-')
        return (0);
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return (nb);
}

int is_prime(int nb)
{
    int i;

    i = 2;
    while (i < nb)
    {
        if (nb % i == 0)
            return (0);
        i++;
    }
    return (1);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb > 9)
        ft_putnbr(nb / 10);
    ft_putchar(nb % 10 + '0');
}

int main(int ac, char **av)
{
    int i;
    int sum;

    i = ft_atoi(av[1]);
    sum = 0;
    if (ac == 2 && i != 0)
    {
        while (i > 1)
        {
            if (is_prime(i))
                sum += i;
            i--;
        }
        ft_putnbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}