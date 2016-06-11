/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:45:00 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 19:07:47 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_big_date(char *date)
{
	date++;
	while (*date != ' ')
		date++;
	date++;
	while (*date != ' ')
		ft_putchar(*(date++));
	ft_putchar(' ');
	date++;
	while (*date != ' ')
		ft_putchar(*(date++));
	date++;
	ft_putstr("  ");
	while (*date != ' ')
		date++;
	date++;
	while (*date != '\n')
		ft_putchar(*(date++));
	ft_putchar(' ');
}

static char	*get_date_big(char *t_date)
{
	char	*date;
	int		i;

	i = 1;
	date = (char *)malloc(26 * sizeof(char));
	while (*t_date)
	{
		date[i] = *(t_date++);
		i++;
	}
	date[0] = 'X';
	return (date);
}

static char	*get_good_time(STAT *st)
{
	time_t now;
	time_t mytime;

	mytime = time(&now);
	mytime = mytime - st->st_mtime;
	mytime = mytime < 0 ? -mytime : mytime;
	if (mytime >= T_MONTH)
		return (get_date_big(ctime(&st->st_mtimespec.tv_sec)));
	return (ft_strdup(ctime(&st->st_mtimespec.tv_sec)));
}

static LI	*lst_add_file_info(STAT *st, char *name)
{
	LI *new;

	if (!(new = (LI *)malloc(1 * sizeof(LI))))
		exit(EXIT_FAILURE);
	new->permision = ft_strnew(10);
	get_type(new, st);
	get_right(new->permision, st);
	new->nb_link = st->st_nlink;
	get_usr_group(new, st);
	new->date = get_good_time(st);
	new->size = st->st_size;
	new->minor = minor(st->st_rdev);
	new->major = major(st->st_rdev);
	new->name = name;
	return (new);
}

LF			*lst_add_file(STAT *st, char *name, INF *i)
{
	LF *new;

	if (!(new = (LF *)malloc(1 * sizeof(LF))))
		exit(EXIT_FAILURE);
	if (i->l)
		new->content = lst_add_file_info(st, name);
	else
		new->content = name;
	new->next = NULL;
	return (new);
}
