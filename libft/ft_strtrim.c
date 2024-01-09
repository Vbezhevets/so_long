/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:05:28 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/04 16:17:17 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim( char  *src, char *set)
{
	size_t		i;

	while (ft_strchr(set, *src) && *src)
		src++;
	i = ft_strlen(src);
	while (ft_strchr(set, src[i - 1]))
		i--;
	return (ft_substr(src, 0, i));
}
