/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmarquar <leon.marquardt@gmx.de>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 13:40:14 by lmarquar          #+#    #+#             */
/*   Updated: 2021/07/10 23:02:37 by lmarquar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	char			*set;
	char			*setnocp;
	char			*setnb;
	char			*sraw;
	char			*s;
	char			type;
	int				minus;
	int				nul;
	int				nbr;
	int				precision;
	struct s_list	*next;
}		t_list;

int		ft_printf(const char *format, ...);
t_list	*emptylist(void);
int		filllist(t_list *list, const char *format, va_list args);
char	*ft_strdup(const char *s);
int		strtonb(const char *s, int *i);
int		findchr(const char *s, int i, char *set);
int		findchrchr(char c, char *set);
char	*createstr(va_list args, char c);
char	*nbtostr(long long n);
void	*ft_calloc(size_t nmemb, size_t size);
int		completelist(t_list *list);
int		dividecount(long long nb);

#endif