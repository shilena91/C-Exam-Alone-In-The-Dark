/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:12:22 by HoangPham         #+#    #+#             */
/*   Updated: 2019/11/16 14:20:19 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    print_bits(unsigned char octet)
{
    int i;

    i = 128;
    while (i > 0)
    {
        if (octet >= i)
        {
            write(1, "1", 1);
            octet = octet % i;
            i = i / 2;
        }
        else
        {
            write(1, "0", 1);
            i = i / 2;
        }
    }
}

int main(void)
{
    print_bits(2);
}