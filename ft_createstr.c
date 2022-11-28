/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:39:52 by lmarquar          #+#    #+#             */
/*   Updated: 2021/07/14 11:43:34 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*nbtostr(long long n)
{
	char	*res;
	long	i;

	if (!n)
		return (ft_strdup("0"));
	i = 0;
	if (n < 0)
		i++;
	i = i + dividecount(n);
	res = ft_calloc(i + 1, 1);
	if (n < 0)
	{
		n = n * -1;
		res[0] = '-';
	}
	while (n)
	{
		res[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}

static
char	*tobighex(unsigned long decnum)
{
	char	*res;
	long	i;
	long	temp;

	i = 0;
	temp = decnum;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	res = ft_calloc(i + 1, 1);
	if (!res)
		return (NULL);
	if (decnum == 0)
		res[0] = '0';
	while (decnum != 0 && --i >= 0)
	{
		temp = decnum % 16;
		res[i] = 'A' + (temp - 10);
		if (temp < 10)
			res[i] = '0' + temp;
		decnum = decnum / 16;
	}
	return (res);
}

static
char	*tosmallhex(unsigned long decnum)
{
	char	*res;
	long	i;
	long	temp;

	i = 0;
	temp = decnum;
	while (temp != 0)
	{
		temp = temp / 16;
		i++;
	}
	res = ft_calloc(i + 2, 1);
	if (!res)
		return (NULL);
	if (decnum == 0)
		res[0] = '0';
	while (decnum != 0 && --i >= 0)
	{
		temp = decnum % 16;
		res[i] = 'a' + (temp - 10);
		if (temp < 10)
			res[i] = '0' + temp;
		decnum = decnum / 16;
	}
	return (res);
}

static
char	*ptostr(char *s)
{
	int		i;
	char	*res;

	i = 0;
	s = tosmallhex((unsigned long) s);
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	res = (char *)ft_calloc (i + 3, 1);
	if (!res)
		return (NULL);
	res[0] = '0';
	res[1] = 'x';
	i = 0;
	while (s[i])
	{
		res[i + 2] = s[i];
		i++;
	}
	free (s);
	return (res);
}

char	*createstr(va_list args, char c)
{
	char	*s;

	if (c == 'c' || c == '%')
		s = ft_calloc(2, 1);
	if (c == 'd' || c == 'i')
		s = nbtostr(va_arg(args, int));
	else if (c == 'u')
		s = nbtostr(va_arg(args, unsigned));
	else if (c == 's')
		s = ft_strdup(va_arg(args, char *));
	else if (c == 'p')
		s = ptostr(va_arg(args, char *));
	else if (c == 'x')
		s = tosmallhex(va_arg(args, unsigned));
	else if (c == 'X')
		s = tobighex(va_arg(args, unsigned));
	else if (c == 'c')
		s[0] = va_arg(args, int);
	else if (c == '%')
		s[0] = c;
	else
		return (NULL);
	if (s == NULL)
		s = ft_strdup("(null)");
	return (s);
}
