/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 10:25:39 by HoangPham         #+#    #+#             */
/*   Updated: 2020/01/21 13:34:20 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		get_len(int value, int base)
{
	int	i;

	i = 0;
	while (value)
	{
		value = value / base;
		i++;
	}
	return (i);
}

char	*ft_strnew(int len)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * len);
	len--;
	while (len >= 0)
	{
		str[len] = '\0';
		len--;
	}
	return (str);
}

char	ft_calculate_char(int mod)
{
	char	return_char;

	return_char = '0';
	while (mod)
	{
		return_char++;
		mod--;
		if (return_char == ':')
			return_char == 'A';
	}
	return (return_char);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		mod;
	int		minus_sign;
	int		len;

	if (value == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	minus_sign = 1;
	if (value < 0 && base == 10)
		minus_sign = -1;
	value = value * minus_sign;
	len = get_len(value, base);
	if (value < 0 && base == 10)
		str = ft_strnew(len) + 1;
	else
		str = ft_strnew(len);
	if (minus_sign == -1)
		str[0] = '-';
	len--;
	while (value > 0)
	{
		mod = value % base;
		value = value / base;
		str[len] = ft_caculate_char(mod);
		len--;
	}
	return (str);
}

int			main(void)
{
    printf("%s", ft_itoa_base(1000, 16));
}
