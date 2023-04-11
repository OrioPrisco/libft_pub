/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:45:58 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:49 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	strtol_impl(const char *nptr, char **endptr, int base, int sign)
{
	long	result;
	long	temp;

	result = 0;
	while (*nptr)
	{
		if (base < 10 && (*nptr >= '0' && *nptr <= '0' + base - 1))
			temp = *nptr - '0';
		else if (base >= 10 && (*nptr >= '0' && *nptr <= '9'))
			temp = *nptr - '0';
		else if (base > 10 && (*nptr >= 'a' && *nptr < 'a' + base - 10))
			temp = *nptr - 'a' + 10;
		else if (base > 10 && (*nptr >= 'A' && *nptr < 'A' + base - 10))
			temp = *nptr - 'A' + 10;
		else
			break ;
		result *= base;
		result += temp;
		nptr++;
	}
	if (endptr)
		*endptr = (char *)nptr;
	return (result * sign);
}

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	int	sign;

	if (base != 0 && (base < 2 || base > 36))
	{
		if (endptr)
			return (*endptr = (char *)nptr, 0L);
		return (0L);
	}
	nptr = ft_next_non_space(nptr);
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	if (base && base != 16)
		return (strtol_impl(nptr, endptr, base, sign));
	if ((base == 0 || base == 16))
	{
		if (!ft_strncmp(nptr, "0x", 2) || !ft_strncmp(nptr, "0X", 2))
			return (strtol_impl(nptr + 2, endptr, 16, sign));
		if (base)
			return (strtol_impl(nptr, endptr, 16, sign));
	}
	if (*nptr == '0')
		return (strtol_impl(nptr, endptr, 8, sign));
	return (strtol_impl(nptr, endptr, 10, sign));
}
