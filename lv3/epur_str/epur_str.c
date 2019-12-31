/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:53:01 by HoangPham         #+#    #+#             */
/*   Updated: 2019/11/18 23:10:18 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i] == ' ' || argv[1][i] == '\t')
            i++;
        while (argv[1][i])
        {
            if (argv[1][i] != ' ' && argv[1][i] != '\t')
                write(1, &argv[1][i], 1);
            else if (argv[1][i] == ' ' || argv[1][i] == '\t')
            {
                if (argv[1][i + 1] > 32 && argv[1][i + 1])
                    write(1, " ", 1);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}