/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:57:53 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 18:17:46 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_size(LI *infos, int space)
{
	ft_putchar(' ');
	if (infos->color == 4 || infos->color == 4)
	{
		print_space(infos->major, ((space - 2) / 2) + 1);
		ft_putchar(',');
		print_space(infos->minor, (space - 2) / 2);
	}
	else
		print_space(infos->size, space);
	ft_putchar(' ');
}

static void	render_lfile(char *path, LF *curr, int *space)
{
	LI *content;

	content = (LI *)curr->content;
	ft_putstr(content->permision);
	ft_putchar(' ');
	print_space(content->nb_link, space[0]);
	ft_putchar(' ');
	ft_putstr(content->user);
	ft_putchar(' ');
	ft_putstr(content->team);
	print_size(content, space[1]);
	ft_putchar(' ');
	print_date(content->date);
	if (content->color == 2)
		print_link(path, content->name);
	else
		ft_putstr_color(content->name, content->color);
	ft_putendl("");
}

void		render_file(LF *first)
{
	LF *curr;

	curr = first;
	while (curr)
	{
		ft_putendl((char *)curr->content);
		curr = curr->next;
	}
	ft_putstr("\n");
}

void		render_lfiles(char *path, LF *first, int *space)
{
	LF		*curr;
	char	*temp;

	curr = first;
	while (curr)
	{
		temp = ft_strjoin(path, ((LI *)curr->content)->name);
		render_lfile(temp, curr, space);
		curr = curr->next;
		ft_memdel((void *)&temp);
	}
	ft_putstr("\n");
}

void		render_files(LF *first, INF *i)
{
	int *nb;

	if (i->l)
	{
		nb = count_nbspace(first);
		render_lfiles("", first, nb);
		ft_memdel((void *)&nb);
	}
	else
		render_file(first);
}
