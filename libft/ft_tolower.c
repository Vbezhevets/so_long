/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: v <v@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:15:26 by bvalerii          #+#    #+#             */
/*   Updated: 2024/01/04 16:28:52 by v                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int ch)
{
	if (ch < 91 && ch > 64)
		return (ch + 32);
	return (ch);
}
