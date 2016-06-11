/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_infos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:37:38 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 11:41:47 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init(INF *inf)
{
	inf->ac = 0;
	inf->a = 0;
	inf->l = 0;
	inf->t = 0;
	inf->r = 0;
	inf->r_up = 0;
	inf->mt_files = 0;
	inf->nb_space = innit_nb_space();
	inf->dir = NULL;
	inf->file = NULL;
}

static void	check_options(INF *i)
{
	if (i->r_up)
		i->mt_files = 1;
	else if ((i->file && i->file->next) || (i->dir && i->dir->next))
		i->mt_files = 1;
	else if (i->file && i->dir)
		i->mt_files = 1;
}

void		init_infos(int ac, char **av)
{
	INF	*inf;
	int	i;

	if (!(inf = get_infos()))
		exit(EXIT_FAILURE);
	init(inf);
	i = fill_flags(ac, av, inf);
	if (!fill_files(i, av, inf))
		lst_push_arg(&inf->dir, "./");
	if (inf->dir == NULL && inf->file == NULL)
		exit(EXIT_FAILURE);
	q_sort_arg(&inf->dir, inf->sort);
	q_sort(&inf->file, "", inf->sort, inf->gnl);
	check_options(inf);
	if (inf->file)
		render_files(inf->file, inf);
	fill_dir(inf->dir);
}
