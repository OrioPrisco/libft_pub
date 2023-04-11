/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 18:08:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:47 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int nb)
{
	int	sign;

	sign = 1;
	if (nb < 0)
		sign = -1;
	if ((nb / (10 * sign)) > 0)
		return (1 + ft_itoa_len(nb / 10));
	else if (sign == -1)
		return (2);
	return (1);
}

static void	ft_itoa_recursive(int nb, char **str)
{
	int	sign;

	sign = 1;
	if (nb < 0)
		sign = -1;
	if ((nb / (10 * sign)) > 0)
		ft_itoa_recursive(nb / 10, str);
	else if (sign == -1)
		*(*str)++ = '-';
	*(*str)++ = ((nb % 10) * sign) + '0';
	**str = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*str2;

	str = malloc(ft_itoa_len(n) + 1);
	if (!str)
		return (0);
	str2 = str;
	ft_itoa_recursive(n, &str2);
	return (str);
}
