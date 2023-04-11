/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchrnul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:09:29 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:47 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchrnul(const void *s, unsigned char c, size_t n)
{
	unsigned char	*addr;

	addr = (unsigned char *)s;
	while (n--)
	{
		if (*addr == c)
			return (addr);
		addr++;
	}
	return (addr);
}
