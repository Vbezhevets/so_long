/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 14:46:46 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/04 16:17:17 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( char *str1,  char *str2, size_t n)
{
	int	res;

	res = 0;
	while (n > 0 && res == 0)
	{
		res = (unsigned char) *str1 - (unsigned char) *str2;
		if (*str1 == '\0' || *str2 == '\0')
			break ;
		str1++;
		str2++;
		n--;
	}
	return (res);
}
