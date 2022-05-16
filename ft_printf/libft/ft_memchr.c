/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rovillar <rovillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 17:49:44 by rovillar          #+#    #+#             */
/*   Updated: 2021/12/09 19:38:50 by rovillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	if (!s)
		return (NULL);
	str = s;
	i = 0;
	while (n != 0)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
		n--;
	}
	return (NULL);
}
