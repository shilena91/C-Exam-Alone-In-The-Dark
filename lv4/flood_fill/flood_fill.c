/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 10:35:37 by HoangPham         #+#    #+#             */
/*   Updated: 2020/01/14 11:10:20 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void    actual_flood_fill(char **tab, char colour, t_point size, int x, int y)
{
    if (x < 0 || y < 0)
        return ;
    if (x > size.x || y > size.y)
        return ;
    if (tab[y][x] != colour)
        return ;
    tab[y][x] = 'F';
    actual_flood_fill(tab, colour, size, x + 1, y);
    actual_flood_fill(tab, colour, size, x - 1, y);
    actual_flood_fill(tab, colour, size, x, y + 1);
    actual_flood_fill(tab, colour, size, x, y - 1);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
    actual_flood_fill(tab, tab[begin.y][begin.x], size, begin.x, begin.y);
}