/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 14:10:44 by HoangPham         #+#    #+#             */
/*   Updated: 2019/11/17 14:24:45 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while (argv[1][i])
            i++;
        i = i - 1;
        while (argv[1][i] && (argv[1][i] == ' ' || argv[1][i] == '\t'))
            i--;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            i--;
        i = i + 1;
        while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
        {
            write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}