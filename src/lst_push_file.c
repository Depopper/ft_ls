/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:48:56 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 12:23:07 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

LF	*lst_push_file(LF **first, STAT *st, char *name, INF *i)
{
	LF *curr;

	if (!*first)
		return ((*first = lst_add_file(st, name, i)));
	curr = *first;
	while (curr->next)
		curr = curr->next;
	return ((curr->next = lst_add_file(st, name, i)));
}
