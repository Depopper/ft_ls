/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:09:24 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 18:50:10 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	read_actions(LF **first, LA *path, char *name, LA **rec)
{
	STAT	st;
	char	*temp;
	INF		*i;

	i = get_infos();
	if (i->a || (name[0] != '.'))
	{
		temp = ft_strjoin(path->name, name);
		lstat(temp, &st);
		if (S_ISDIR(st.st_mode) && i->r_up)
			if ((i->a && (ft_strcmp(name, ".") && ft_strcmp(name, "..")))
			|| name[0] != '.')
				lst_push_arg(rec, temp);
		if (S_ISCHR(st.st_mode))
			i->nb_space[1] = 10;
		if (i->l)
			path->total += st.st_blocks;
		check_space(&st, i->nb_space);
		lst_push_file(first, &st, ft_strdup(name), i);
		ft_memdel((void *)&temp);
	}
}

static void	render_options(LA *path, LF *first, INF *i)
{
	print_path(path, i);
	if (i->l)
	{
		render_lfiles(path->name, first, i->nb_space);
	}
	else
		render_file(first);
}

static void	clean_memory(LF **first, INF *i)
{
	reset_nb_space(i->nb_space);
	free_lst(*first, i);
	ft_memdel((void*)first);
}

static void	read_dir(LA *path, INF *i)
{
	DIR					*dir;
	struct dirent		*sd;
	LF					*first;
	LA					*rec;

	rec = NULL;
	first = NULL;
	if (!(dir = opendir(path->name)))
		return (no_right(path->name));
	while ((sd = readdir(dir)))
		read_actions(&first, path, sd->d_name, &rec);
	q_sort(&first, path->name, i->sort, i->gnl);
	render_options(path, first, i);
	clean_memory(&first, i);
	if (i->r_up)
	{
		q_sort_arg(&rec, i->sort);
		fill_dir(rec);
	}
	free_path(rec);
	ft_memdel((void*)&rec);
	closedir(dir);
}

void		fill_dir(LA *dir)
{
	INF *i;

	i = get_infos();
	while (dir)
	{
		read_dir(dir, i);
		dir = dir->next;
	}
}
