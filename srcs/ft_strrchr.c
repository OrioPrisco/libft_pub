/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:41:35 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:48 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, char c)
{
	size_t	len;

	len = ft_strlen(s) + 1;
	while (len--)
	{
		if (*(s + len) == c)
			return ((char *)(s + len));
	}
	return (0);
}
