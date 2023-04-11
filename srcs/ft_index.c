/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:33:20 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/04/11 13:15:46 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_index(const char *str, char c)
{
	char	*s;

	s = ft_strchr(str, c);
	if (s)
		return (s - str);
	return (-1);
}
