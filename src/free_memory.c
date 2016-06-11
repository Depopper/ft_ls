/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:28:01 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 19:05:19 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_path(LA *curr)
{
	if (curr)
	{
		if (curr->next)
			free_path(curr->next);
		ft_memdel((void *)&curr->name);
		ft_memdel((void *)&curr->next);
	}
}

static void	free_lst_infos(LF *first)
{
	LI *infos;

	infos = first->content;
	ft_memdel((void **)&infos->permision);
	ft_memdel((void **)&infos->date);
	ft_memdel((void **)&infos->name);
	ft_memdel((void **)&infos);
}

void		free_lst(LF *first, INF *i)
{
	if (first)
	{
		if (first->next)
			free_lst(first->next, i);
		if (i->l)
			free_lst_infos(first);
		else
			ft_memdel(&first->content);
		ft_memdel((void *)&first->next);
	}
}

int			free_temp(char ***temp)
{
	free(*temp);
	return (1);
}

void		free_infos(INF *i)
{
	if (i->file)
	{
		free_lst(i->file, i);
		ft_memdel((void *)&i->file);
	}
	if (i->dir)
	{
		free_path(i->dir);
		ft_memdel((void *)&i->dir);
	}
	ft_memdel((void *)&i->nb_space);
	ft_memdel((void *)&i);
}
