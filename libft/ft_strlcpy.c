/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:16:38 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/04 16:17:17 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst,  char *src, size_t n)
{
	size_t	src_size;

	src_size = ft_strlen(src);
	if (n == 0)
		return (src_size);
	while (*src != '\0' && n - 1 > 0)
	{
		*dst = *src;
		dst++;
		src++;
		n--;
	}
	*dst = '\0';
	return (src_size);
}
