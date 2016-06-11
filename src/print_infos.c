/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_infos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:50:29 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 18:17:16 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ls.h"

void	print_space(int value, int nb_link)
{
	int nb_space;

	nb_space = (nb_link) - ft_getdecade(value);
	if (nb_space == nb_link)
		nb_space--;
	while (nb_space-- > 0)
		ft_putchar(' ');
	ft_putnbr(value);
}

void	print_date(char *date)
{
	if (*date == 'X')
		return (print_big_date(date));
	while (*date != ' ')
		++date;
	++date;
	while (*date != ':')
		ft_putchar(*(date++));
	ft_putchar(*(date++));
	while (*date != ':')
		ft_putchar(*(date++));
	ft_putchar(' ');
}

void	print_link(char *path, char *name)
{
	char *buf;

	buf = ft_strnew(256);
	readlink(path, buf, 256);
	ft_putstr_color(name, 6);
	ft_putstr(" -> ");
	ft_putstr(buf);
	ft_memdel((void *)&buf);
}

void	no_right(char *name)
{
	ft_putstr("ft_ls: imposible d'ouvrir le repertoire ");
	ft_putstr(name);
	ft_putstr(": Permission non accordee\n\n");
}

void	print_path(LA *path, INF *i)
{
	if (i->mt_files)
	{
		ft_putstr(path->name);
		ft_putendl(":");
	}
	if (i->l)
	{
		ft_putstr("total: ");
		ft_putnbr(path->total);
		ft_putendl("");
	}
}
