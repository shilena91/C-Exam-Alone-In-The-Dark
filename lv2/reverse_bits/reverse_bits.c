/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:29:37 by HoangPham         #+#    #+#             */
/*   Updated: 2019/11/16 21:33:23 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

unsigned char    reverse_bits(unsigned char octet)
{
    int i;
    unsigned char result;
    
    i = 8;
    result = 0;
    while (i > 0)
    {
        result = result * 2 + (octet % 2);
        octet = octet / 2;
        i--;
    }
    return (result);
}

int main(void)
{
    unsigned char c;

    c = '.';
    c = reverse_bits(c);
    write(1, &c, 1);
}