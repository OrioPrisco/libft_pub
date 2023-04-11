/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:35:33 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:47 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

//a pretty standar memcmp
static int	ft_memcmp_byte(const BYTE *s1, const BYTE *s2, size_t n)
{
	while (n)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n)
		return (*s1 - *s2);
	return (0);
}

//do word comparisons. If a diference is found, use byte comparisons to get
//the difference. once n is smalled than a word, do byte comparisons
static int	ft_memcmp_word(const WORD_TYPE *s1, const WORD_TYPE *s2, size_t n)
{
	while (n >= sizeof(WORD_TYPE))
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n -= sizeof(WORD_TYPE);
	}
	return (ft_memcmp_byte((const BYTE *)s1, (const BYTE *)s2, n));
}

//first try to align memory, then do full words comparisons
int	ft_memcmp(const void *i1, const void *i2, size_t n)
{
	const BYTE	*s1;
	const BYTE	*s2;
	int			res;
	size_t		shift;

	shift = (intptr_t)i1 % sizeof(WORD_TYPE);
	if (shift != ((intptr_t)i2 % sizeof(WORD_TYPE))
		|| n < shift + sizeof(WORD_TYPE))
		return (ft_memcmp_byte(i1, i2, n));
	res = ft_memcmp_byte(i1, i2, shift);
	if (res)
		return (res);
	s1 = i1;
	s2 = i2;
	s1 += shift;
	s2 += shift;
	n -= shift;
	return (ft_memcmp_word((const WORD_TYPE *)s1, (const WORD_TYPE *)s2, n));
}
