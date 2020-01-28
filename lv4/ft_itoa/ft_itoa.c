/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hopham <hopham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 13:23:23 by hopham            #+#    #+#             */
/*   Updated: 2020/01/28 13:41:18 by hopham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		get_len(int nb)
{
	int	len;

	len = 0;
	while (nb > 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*ft_strnew(int len)
{
	char	*str;

	len++;
	str = (char*)malloc(sizeof(char) * len);
	while (len-- >= 0)
		str[len] = '\0';
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	int		len;
	int		minus_sign;

	minus_sign = 1;
	if (nb < 0)
		minus_sign = -minus_sign;
	nb = nb * minus_sign;
	len = get_len(nb);
	if (minus_sign < 0)
	{
		str = ft_strnew(len + 1);
		str[0] = '-';
	}
	else
		str = ft_strnew(len);
	len--;
	printf("%i\n", len);
	while (nb > 0)
	{
		str[len--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

int	main(void)
{
	printf("%s\n", ft_itoa(23));
	return (0);
}
