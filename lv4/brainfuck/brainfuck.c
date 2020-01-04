/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 22:06:55 by HoangPham         #+#    #+#             */
/*   Updated: 2020/01/05 01:16:05 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int    go_marching(char *input, int curr)
{
    int balance;

    balance = 0;
    if (input[curr] == ']')
    {
        curr--;
        while (input[curr])
        {
            if (input[curr] == ']')
                balance++;
            if (input[curr] == '[' && balance != 0)
                balance--;
            else if (input[curr] == '[' && balance == 0)
                break ;
            curr--;
        }
    }
    else if (input[curr] == '[')
    {
        curr++;
        while (input[curr])
        {
            if (input[curr] == '[')
                balance++;
            if (input[curr] == ']' && balance != 0)
                balance--;
            else if (input[curr] == ']' && balance == 0)
                break ;
            curr++;
        }
    }
    return (curr);
}

void    brain_fuck(char *input)
{
    char    bytes[2048];
    int     curr;
    int     pointer;

    curr = 0;
    while (curr < 2048)
        bytes[curr++] = 0;
    pointer = 0;
    curr = 0;
    while (input[curr])
    {
        if (input[curr] == '>')
            pointer++;
        else if (input[curr] == '<')
            pointer--;
        else if (input[curr] == '+')
            bytes[pointer]++;
        else if (input[curr] == '-')
            bytes[pointer]--;
        else if (input[curr] == '.')
            write(1, &bytes[pointer], 1);
        else if (input[curr] == '[')
        {
            if (bytes[pointer] == 0)
                curr = go_marching(input, curr);
        }
        else if (input[curr] == ']')
        {
            if (bytes[pointer] != 0)
                curr = go_marching(input, curr);
        }
        curr++;
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        brain_fuck(av[1]);
    else
        write(1, "\n", 1);
    return (0);
}
