/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 22:07:37 by HoangPham         #+#    #+#             */
/*   Updated: 2019/12/30 23:42:37 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    fprime(unsigned int nb)
{
    int prime;

    if (nb == 1)
        printf("1");
    else
    {
        prime = 2;
        while (nb > 1)
        {
            if (nb % prime == 0)
            {
                printf("%d", prime);
                nb = nb / prime;
                if (nb > 1)
                    printf("*");
                prime--;
            }
            prime++;
        }
    }

}

int     main(int ac, char **av)
{
    if (ac == 2)
        fprime(atoi(av[1]));
    printf("\n");
    return (0);
}
