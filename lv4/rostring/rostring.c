/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 20:58:47 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/21 22:12:23 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

int count_words(char *str)
{
    int count;
    int i;

    i = 0;
    while (is_space(str[i]))
        i++;
    if (!str[i])
        return (0);
    count = 1;
    while (str[i])
    {
        if (str[i] == ' ' && !is_space(str[i + 1]) && str[i + 1] != '\0')
            count++;
        i++;
    }
    return (count);
}

void    rostring(char *str)
{
    int     i;
    int     j;
    char    *first_str;

    i = 0;
    while (is_space(str[i]))
        i++;
    if (count_words(str) > 0)
        first_str = (char*)malloc(sizeof(char) * 1000);
    else
        return ;
    j = 0;
    while (!is_space(str[i]))
    {
        first_str[j] = str[i];
        j++;
        i++;
    }
    first_str[j] = '\0';
    while (is_space(str[i]))
        i++;
    while (str[i])
    {
        if (!is_space(str[i]))
            write(1, &str[i], 1);
        else if (is_space(str[i]) && !is_space(str[i + 1]) && str[i + 1] != '\0')
            write(1, " ", 1);
        i++;
    }
    if (count_words(str) > 1)
        write(1, " ", 1);
    j = 0;
    while (first_str[j])
    {
        write(1, &first_str[j], 1);
        j++;
    }
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac > 1)
    {
        while (i < ac && av[i])
        {
            rostring(av[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write (1, "\n", 1);
    return (0);
}
