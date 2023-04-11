/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:41:32 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:48 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//TODO : advance big by number of matched characters
//i double checked and it should work in theory
//worst thing is i know i asked myself this question before
//but can't remeber where, maybe it was in a zach like ?
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	lil_len;

	if (!*little)
		return ((char *)big);
	lil_len = ft_strlen(little);
	if (lil_len > len)
		return (0);
	while (*big && len - (lil_len - 1))
	{
		if (!ft_memcmp(big, little, lil_len))
			return ((char *)big);
		big++;
		len--;
	}
	return (0);
}
