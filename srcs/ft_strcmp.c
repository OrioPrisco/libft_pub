/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:11:24 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:48 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	len1;

	len1 = ft_strlen(s1);
	len1 = ft_strnlen(s2, len1);
	return (ft_memcmp(s1, s2, len1 + 1));
}
