/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 00:17:33 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/17 00:29:19 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int max(int *tab, unsigned int len)
{
    int i;
    int a;

    i = 0;
    while (i < len - 1)
    {
        if (tab[i] < tab[i + 1])
        {
            a = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = a;
            i = -1;
        }
        i++;
    }
    return (tab[0]);
}

int main(void)
{
    int tab[5] = {1, 50, 4, 6, 10};

    printf("%i", max(tab, 5));
}
