/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:02:28 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 12:26:34 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_alpha(char *one, char *two)
{
	return (ft_strcmp(one, two) > 0 ? 1 : 0);
}

int	sort_time(char *one, char *two)
{
	STAT st1;
	STAT st2;

	lstat(one, &st1);
	lstat(two, &st2);
	return (st1.st_mtimespec.tv_sec <= st2.st_mtimespec.tv_sec);
}

int	sort_rtime(char *one, char *two)
{
	return (!sort_time(one, two) ? 1 : 0);
}

int	sort_ralpha(char *one, char *two)
{
	return (ft_strcmp(one, two) < 0 ? 1 : 0);
}
