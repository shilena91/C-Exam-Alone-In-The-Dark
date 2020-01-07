/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:25:39 by HoangPham         #+#    #+#             */
/*   Updated: 2020/01/07 11:32:53 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int  get_len(int num, int base)
{
    int len;

    len = 0;
    while (num)
    {
        num = num / base;
        len++;
    }
    return (len);
}

char    *ft_strnew(int len)
{
    char    *str;

    str = (char*)malloc(sizeof(char) * len);
    while (len >= 0)
    {
        str[len] = '\0';
        len--;
    }
    return (str);
}

char    ft_calculate_char(int mod)
{
    char    return_char;

    return_char = '0';
    while (mod)
    {
        return_char++;
        mod--;
        if (return_char == ':')
            return_char = 'A';
    }
    return (return_char);
}

char    *ft_itoa_base(int num, int base)
{
    char    *str;
    int     len;
    int     mod;
    int     minus_sign;

    if (num == 0)
    {
        str = ft_strnew(1);
        *str = '0';
        return (str);
    }
    minus_sign = 1;
    if (base == 10 && num < 0)
        minus_sign = -1;
    if (minus_sign == -1)
        len = get_len(num, base) + 1;
    else
        len = get_len(num, base);
    num = num * minus_sign;
    str = ft_strnew(len);
    if (minus_sign == -1)
        str[0] = '-';
    len--;
    while (num)
    {
        mod = num % base;
        num = num / base;
        str[len] = ft_calculate_char(mod);
        len--;
    }
    return (str);
}

int main(void)
{
    printf("%s", ft_itoa_base(1000, 16));
}