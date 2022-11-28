/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <lmarquar@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:40:05 by lmarquar          #+#    #+#             */
/*   Updated: 2021/07/14 15:48:09 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static
int	printlist(t_list *list)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (list)
	{
		while (list->s[i])
		{
			write(1, &list->s[i], 1);
			i++;
			size++;
		}
		if (list->type == 'c' && !list->sraw[0])
		{
			write(1, "", 1);
			size++;
		}
		list = list->next;
		i = 0;
	}
	return (size);
}

static
int	cleanlist(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		free(list->set);
		free(list->setnocp);
		free(list->setnb);
		if (!((list->nbr - (int)ft_strlen(list->sraw)) <= 0))
			free(list->s);
		free(list->sraw);
		temp = list->next;
		free(list);
		list = temp;
	}
	return (1);
}

static
int	checksraw(t_list *list)
{
	while (list)
	{
		if (!list->sraw)
			return (0);
		if (!list->sraw[0] && list->type == 'c')
			list->nbr--;
		list = list->next;
	}
	return (1);
}
/*ft_printf:
**1(emptylist):     creates 1 empty list element
**2(filllist):      fills the list element and creates new ones if needed
**                  no modifications are made yet
**3:(completelist): modifies the list so s is now the correct output for
**                  every element
*/

int	ft_printf(const char *format, ...)
{
	t_list	*list;
	va_list	args;
	int		res;

	list = emptylist();
	if (!list)
		return (0);
	va_start(args, format);
	if (!filllist(list, format, args))
		return (0);
	va_end(args);
	if (!checksraw(list))
		return (0);
	if (!completelist(list))
		return (0);
	res = printlist(list);
	cleanlist(list);
	return (res);
}
