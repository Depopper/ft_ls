/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:04:38 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 11:08:24 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		*innit_nb_space(void)
{
	int *nb_space;

	if (!(nb_space = (int *)malloc(2 * sizeof(int))))
		exit(EXIT_FAILURE);
	nb_space[0] = 0;
	nb_space[1] = 0;
	return (nb_space);
}

void	reset_nb_space(int *nb_space)
{
	nb_space[0] = 0;
	nb_space[1] = 0;
}

void	check_space(STAT *st1, int *space)
{
	int size;

	size = 0;
	if ((size = ft_getdecade(st1->st_nlink)) > space[0])
		space[0] = size;
	if ((size = ft_getdecade(st1->st_size)) > space[1])
		space[1] = size;
}

int		*count_nbspace(LF *first)
{
	int		*nb_space;
	LF		*curr;
	STAT	st;

	nb_space = innit_nb_space();
	curr = first;
	while (curr)
	{
		lstat(((LI *)curr->content)->name, &st);
		check_space(&st, nb_space);
		curr = curr->next;
	}
	return (nb_space);
}
