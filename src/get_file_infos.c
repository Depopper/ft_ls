/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:31:43 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 18:49:05 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_type(LI *new, STAT *st)
{
	static int	tab[] = {'-', 'd', 'l', 'p', 'c', 'b', 's'};
	int			nb;

	nb = 0;
	if (S_ISREG(st->st_mode))
		nb = 0;
	else if (S_ISDIR(st->st_mode))
		nb = 1;
	else if (S_ISLNK(st->st_mode))
		nb = 2;
	else if (S_ISFIFO(st->st_mode))
		nb = 3;
	else if (S_ISCHR(st->st_mode))
		nb = 4;
	else if (S_ISBLK(st->st_mode))
		nb = 5;
	else if (S_ISSOCK(st->st_mode))
		nb = 6;
	new->permision[0] = tab[nb];
	new->color = nb;
}

void	get_right(char *perm, STAT *st)
{
	perm[1] = (st->st_mode & S_IRUSR) ? 'r' : '-';
	perm[2] = (st->st_mode & S_IWUSR) ? 'w' : '-';
	perm[3] = (st->st_mode & S_IXUSR) ? 'x' : '-';
	if (st->st_mode & S_ISUID)
		perm[3] = (perm[3] == 'x') ? 's' : 'S';
	perm[4] = (st->st_mode & S_IRGRP) ? 'r' : '-';
	perm[5] = (st->st_mode & S_IWGRP) ? 'w' : '-';
	perm[6] = (st->st_mode & S_IXGRP) ? 'x' : '-';
	if (st->st_mode & S_ISGID)
		perm[6] = (perm[6] == 'x') ? 's' : 'S';
	perm[7] = (st->st_mode & S_IROTH) ? 'r' : '-';
	perm[8] = (st->st_mode & S_IWOTH) ? 'w' : '-';
	perm[9] = (st->st_mode & S_IXOTH) ? 'x' : '-';
	if (st->st_mode & S_ISVTX)
		perm[9] = (perm[9] == 'x') ? 't' : 'T';
}

void	get_usr_group(LI *new, STAT *st)
{
	struct passwd	*user;
	struct group	*team;

	user = getpwuid(st->st_uid);
	team = getgrgid(st->st_gid);
	if (user == NULL)
		new->user = ft_itoa(st->st_uid);
	else
		new->user = user->pw_name;
	new->team = team->gr_name;
}
