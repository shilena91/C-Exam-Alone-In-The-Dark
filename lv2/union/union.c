/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 23:28:28 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/16 23:53:56 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int check_double(char *str, char c, int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (ac == 3)
    {
        while (av[1][i])
        {
            if (!check_double(av[1], av[1][i], i))
                write(1, &av[1][i], 1);
            i++;
        }
        while (av[2][j])
        {
            if (!check_double(av[1], av[2][j], i) && !check_double(av[2], av[2][j], j))
                write(1, &av[2][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
