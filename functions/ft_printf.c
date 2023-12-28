/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalerii <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 19:01:02 by bvalerii          #+#    #+#             */
/*   Updated: 2023/10/10 19:01:09 by bvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */\
#include "functlib.h" 


char	*ft_strchr(const char *str, int c)

{
	c = (unsigned char)c;
	while (*str && *str != c)
		str++;
	if (*str == c)
		return ((char *)str);
	return (NULL);
}
void	ft_strcpy(char *dst, char *src)
{
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
}


void	format(const char str, va_list *args, int *count)
{
	char	c;

	if (str == 'c')
		ft_putchr(va_arg(*args, int), count);
	if (str == 's')
		ft_putstr(va_arg(*args, char *), count);
	if (str == 'p')
		ft_putpntr(va_arg(*args, void *), count);
	if (str == 'd')
		ft_putnbr(va_arg(*args, int), count);
	if (str == 'i')
		ft_putnbr(va_arg(*args, int), count);
	if (str == 'u')
		ft_putunbr(va_arg(*args, unsigned int), count);
	if (str == 'x')
		ft_putx(va_arg(*args, int), count);
	if (str == 'X')
		ft_put_x(va_arg(*args, int), count);
	if (str == '%')
	{
		c = '%';
		write(1, &c, 1);
		*count = *count + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		i;
	va_list	args;
	char	*flags;

	flags = "%Xxuidpsc";
	i = 0;
	count = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr(flags, str[i + 1]))
			format(str[i++ + 1], &args, &count);
		else
		{
			write(1, &str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

