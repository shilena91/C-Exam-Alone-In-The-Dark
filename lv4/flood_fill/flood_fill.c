/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: HoangPham <HoangPham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:15:15 by HoangPham         #+#    #+#             */
/*   Updated: 2020/01/28 11:21:54 by HoangPham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_point.h"

void    actual_flood_fill(char **tab, char color, t_point size, int x, int y)
{
    if (x < 0 || y < 0)
        return ;
    if (x > size.x || y > size.y)
        return ;
    if (tab[y][x] != color)
        return ;
    tab[y][x] = 'F';
    actual_flood_fill(tab, color, size, x + 1, y);
    actual_flood_fill(tab, color, size, x - 1, y);
    actual_flood_fill(tab, color, size, x, y + 1);
    actual_flood_fill(tab, color, size, x, y - 1);
}

void    flood_fill(char **tab, t_point size, t_point begin)
{
    actual_flood_fill(tab, tab[begin.y][begin.x], size, begin.x, begin.y);
}