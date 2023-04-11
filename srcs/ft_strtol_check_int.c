/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol_check_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:49:33 by OrioPriscc        #+#    #+#             */
/*   Updated: 2023/04/11 13:15:49 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

_Bool	ft_strtol_check_int(const char *str, const char *endptr, long parsed)
{
	str = ft_next_non_space(str);
	if (*str == '+' || *str == '-')
		str++;
	if (endptr && str - endptr > 10)
		return (1);
	if (parsed > INT_MAX || parsed < INT_MIN)
		return (1);
	return (0);
}
