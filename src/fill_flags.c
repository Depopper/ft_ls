/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:23:38 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 19:26:02 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		choose_sort(INF *i)
{
	if (i->l)
		i->gnl = &get_content_name;
	else
		i->gnl = &get_name;
	if (i->t && i->r)
		i->sort = &sort_rtime;
	else if (i->t)
		i->sort = &sort_time;
	else if (i->r)
		i->sort = &sort_ralpha;
	else
		i->sort = &sort_alpha;
}

static void		flag_error(char c)
{
	ft_putstr("ft_ls: option invalide -- ");
	ft_putchar(c);
	ft_putchar('\n');
	ft_putendl("Usage : ft_ls [-altrR]");
	exit(EXIT_FAILURE);
}

static int		valid_flag(char *c, char b, INF *inf)
{
	if (g_stop)
		return (0);
	if (c[0] == '-' && c[1] == '-' && !c[2])
	{
		g_stop = 1;
		return (0);
	}
	if (b == 'a')
		return ((inf->a = TRUE));
	if (b == 'l')
		return ((inf->l = TRUE));
	if (b == 't')
		return ((inf->t = TRUE));
	if (b == 'r')
		return ((inf->r = TRUE));
	if (b == 'R')
		return ((inf->r_up = TRUE));
	else
		flag_error(b);
	return (0);
}

int				fill_flags(int ac, char **av, INF *inf)
{
	int c;
	int i;

	c = 1;
	i = 1;
	while (i < ac && *av[i] == '-' && av[i][1] && !g_stop)
	{
		while (av[i][c] && valid_flag(av[i], av[i][c], inf))
			c++;
		c = 1;
		i++;
	}
	choose_sort(inf);
	return (i);
}
