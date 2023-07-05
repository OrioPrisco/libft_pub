/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users.nor  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:16:34 by OrioPrisco        #+#    #+#             */
/*   Updated: 2023/07/05 16:21:41 by OrioPrisco       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *str, const char *reject)
{
	const char	*og;

	og = str;
	while (*str && !ft_strchr(reject, *str))
		str++;
	return (str - og);
}
