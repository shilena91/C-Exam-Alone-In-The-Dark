/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:09:41 by HoangPham         #+#    #+#             */
/*   Updated: 2019/11/17 15:23:18 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    unsigned int i;

    i = 2;
    while (i < n)
        i *= 2;
    if (i == n)
        return (1);
    return (0);
}

int main(void)
{
    int n = 32;

    printf("%i\n", is_power_of_2(n));
}