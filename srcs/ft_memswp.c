/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:09:07 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/07/26 16:11:36 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswp(void *foo, void *bar, size_t size)
{
	unsigned char	*a;
	unsigned char	*b;
	unsigned char	tmp;

	a = foo;
	b = bar;
	while (size--)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}
