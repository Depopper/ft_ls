/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:20:25 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 15:11:42 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_file_err(char *name)
{
	ft_putstr("ft_ls:Fichier/file introuvable: ");
	ft_putendl(name);
}

static void	files_error(LA **first)
{
	LA *curr;

	if (!*first)
		return ;
	curr = *first;
	while (curr)
	{
		print_file_err(curr->name);
		curr = curr->next;
	}
	free_path(*first);
	return ;
}

int			fill_files(int i, char **av, INF *inf)
{
	STAT	st;
	int		nb;
	LA		*err;

	err = NULL;
	nb = 0;
	while (av[i])
	{
		if (lstat(av[i], &st) == -1)
			lst_push_arg(&err, av[i]);
		else if (S_ISDIR(st.st_mode) || (!inf->l && S_ISLNK(st.st_mode)))
			lst_push_arg(&inf->dir, av[i]);
		else
			lst_push_file(&inf->file, &st, ft_strdup(av[i]), inf);
		++nb;
		i++;
	}
	q_sort_arg(&err, inf->sort);
	files_error(&err);
	ft_memdel((void**)&err);
	return ((inf->ac = nb));
}
