/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:13:24 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:47 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*backward_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destin;

	source = src;
	destin = dest;
	source += n;
	destin += n;
	while (n--)
		*--destin = *--source;
	return (dest);
}

static void	*forward_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destin;

	source = src;
	destin = dest;
	while (n--)
		*destin++ = *source++;
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
		return (backward_memcpy(dest, src, n));
	return (forward_memcpy(dest, src, n));
}
