/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 12:23:39 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 12:26:06 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

LA	*lst_push_arg(LA **first, char *name)
{
	LA *curr;

	if (!*first)
		return ((*first = lst_add_arg(name)));
	curr = *first;
	while (curr->next)
		curr = curr->next;
	return ((curr->next = lst_add_arg(name)));
}
