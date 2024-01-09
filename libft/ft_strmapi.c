/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:32:19 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/04 16:17:17 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char  *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		l;
	int		i;

	l = ft_strlen((char *)s);
	i = 0;
	str = (char *)malloc((l + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (i < l)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
