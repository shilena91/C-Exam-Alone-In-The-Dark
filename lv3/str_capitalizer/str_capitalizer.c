/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 09:31:05 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/17 09:52:52 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char    ft_toupper(char c)
{
    if (c >= 'a' && c <= 'z')
        c -= 32;
    return (c);
}

char    ft_tolower(char c)
{
    if (c >= 'A' && c <= 'Z')
        c += 32;
    return (c);
}

void    str_capitalizer(char *str)
{
    int i;

    i = 0;
    if (str[i] != ' ' && str[i] != '\t')
    {
        str[i] = ft_toupper(str[i]);
        write(1, &str[i], 1);
        i++;
    }
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z' && (str[i - 1] == ' ' || str[i - 1] == '\t'))
            str[i] = ft_toupper(str[i]);
        if (str[i] >= 'A' && str[i] <= 'Z' && (str[i - 1] != ' ' && str[i - 1] != '\t'))
            str[i] = ft_tolower(str[i]);
        write(1, &str[i], 1);
        i++;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    while (i < ac)
    {
        str_capitalizer(av[i]);
        write(1, "\n", 1);
        i++;
    }
    if (ac == 1)
        write(1, "\n", 1);
    return (0);
}