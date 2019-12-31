/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 23:06:05 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/16 23:27:34 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int main(int ac, char **av)
{
    int i;
    int j;
    int len;

    i = 0;
    j = 0;
    len = 0;
    if (ac == 3)
    {
        while (av[1][i])
        {
            while (av[2][j])
            {
                if (av[1][i] == av[2][j])
                {
                    len++;
                    break ;
                }
                j++;
            }
            i++;
        }
        if (len == ft_strlen(av[1]))
            write(1, av[1], len);
    }
    write(1, "\n", 1);
    return (0);
}
