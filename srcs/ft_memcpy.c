/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:13:24 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/07/01 22:46:21 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

static void	*ft_memcpy_byte(void *dest, const void *src, size_t n)
{
	const BYTE	*source;
	BYTE		*destin;

	source = src;
	destin = dest;
	while (n--)
		*destin++ = *source++;
	return (dest);
}

static void	*ft_memcpy_word(WORD_TYPE *dest, const WORD_TYPE *src, size_t n)
{
	const WORD_TYPE	*source;
	WORD_TYPE		*destin;

	source = src;
	destin = dest;
	while (n >= sizeof(WORD_TYPE))
	{
		*destin++ = *source++;
		n -= sizeof(WORD_TYPE);
	}
	if (n)
		return (ft_memcpy_byte(destin, source, n));
	return (dest);
}

//first try to align memory, then do full words copies
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const BYTE	*destin;
	const BYTE	*source;
	size_t		shift;

	shift = (intptr_t)dest % sizeof(WORD_TYPE);
	if (shift != ((intptr_t)src % sizeof(WORD_TYPE))
		|| n < shift + sizeof(WORD_TYPE))
		return (ft_memcpy_byte(dest, src, n));
	ft_memcpy_byte(dest, src, shift);
	destin = dest;
	source = src;
	destin += shift;
	source += shift;
	n -= shift;
	return (ft_memcpy_word((WORD_TYPE *)destin, (const WORD_TYPE *)source, n));
}
