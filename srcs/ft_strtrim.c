/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:28:44 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/09/22 15:37:37 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

//use strncpy instead of strlcpy
char	*ft_strtrim(const char *s, const char *set)
{
	size_t	begin;
	size_t	end;
	char	*str;

	begin = 0;
	end = ft_strlen(s);
	while (s[begin] && ft_strchr(set, s[begin]))
		begin++;
	if (begin == end)
		return (ft_strdup(""));
	while (ft_strchr(set, s[--end]))
		;
	str = malloc (end - begin + 2);
	if (!str)
		return (0);
	ft_memcpy(str, s + begin, end - begin + 1);
	str[end - begin + 1] = '\0';
	return (str);
}
