/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_custom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:08:08 by OrioPrisc         #+#    #+#             */
/*   Updated: 2023/08/30 17:22:49 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_case_comp(char a, char b)
{
	return (ft_tolower(a) - ft_tolower(b));
}

//switch case and compare
int	ft_lcase_comp(char a, char b)
{
	if (a == ft_tolower(a))
		a = ft_toupper(a);
	else if (a == ft_toupper(a))
		a = ft_tolower(a);
	if (b == ft_tolower(b))
		b = ft_toupper(b);
	else if (b == ft_toupper(b))
		b = ft_tolower(b);
	return (a - b);
}

int	ft_strcmp_custom(const char *s1, const char *s2, int (*f)(char, char))
{
	while (*s1 && *s2)
	{
		if (f(*s1, *s2))
			return (f(*s1, *s2));
		s1++;
		s2++;
	}
	return (f(*s1, *s2));
}
