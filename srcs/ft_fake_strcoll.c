/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fake_strcoll.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:21:13 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/09/21 12:41:56 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fake_strcoll(const char *s1, const char *s2)
{
	int	a;

	a = ft_strcmp_custom(s1, s2, ft_case_comp, ft_isalnum);
	if (a)
		return (a);
	return (ft_strcmp_custom(s1, s2, ft_lcase_comp, NULL));
}
