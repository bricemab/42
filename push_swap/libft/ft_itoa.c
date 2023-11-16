/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmabilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:16:23 by bmabilla          #+#    #+#             */
/*   Updated: 2023/10/25 14:16:25 by bmabilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbr_len(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 9)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static int	ft_div(int len)
{
	int	i;

	i = 1;
	if (len == 1)
		return (1);
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	int		len2;
	char	*result;

	i = 0;
	len = ft_nbr_len(n);
	len2 = len;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
		i++;
		len--;
	}
	while (i < len2)
		result[i++] = ((n / ft_div(len--)) % 10) + 48;
	result[i] = '\0';
	return (result);
}
/*
int main()
{
	printf("%s\n", ft_itoa(-9874));
	printf("%s\n", ft_itoa(543000));
	printf("%s\n", ft_itoa(8124));
	return 0;
}
*/