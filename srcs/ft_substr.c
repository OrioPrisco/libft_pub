/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 11:57:12 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/09/22 15:37:07 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//possible optimization : strnstr(s, 0, start + len);
//use strcpy instead of strlcpy
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	lens;

	if (!len)
		return (ft_strdup(""));
	lens = ft_strnlen(s, start + len - 1);
	if (start > lens)
		return (ft_strdup(""));
	lens = lens - start;
	str = malloc(lens + 2);
	if (!str)
		return (0);
	ft_memcpy(str, s + start, lens + 1);
	str[lens + 1] = '\0';
	return (str);
}
