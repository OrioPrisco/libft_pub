/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_check_long.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:49:33 by OrioPriscc        #+#    #+#             */
/*   Updated: 2023/09/27 12:46:35 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_buff(long nb, char **buffer)
{
	int	sign;

	sign = 1;
	if (nb < 0)
		sign = -1;
	if ((nb / (10 * sign)) > 0)
		ft_putnbr_buff(nb / 10, buffer);
	else if (sign == -1)
		buffer[0]++[0] = '-';
	buffer[0]++[0] = "0123456789"[(nb % 10) * sign];
	buffer[0][0] = 0;
}

_Bool	ft_strtol_check_long(const char *str, const char *endptr, long parsed)
{
	char	buffer[21];
	char	*buff2;

	buff2 = buffer;
	ft_putnbr_buff(parsed, &buff2);
	buff2 = buffer;
	str = ft_next_non_space(str);
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		if (parsed > 0)
			return (0);
		str++;
		if (parsed)
			buff2++;
	}
	while (*str == '0' && str[1])
		str++;
	return (!ft_strncmp(buff2, str, endptr - str));
}
