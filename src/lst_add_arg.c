/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_add_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:42:00 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 11:44:34 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	*normed_path(char *name)
{
	int i;

	i = 0;
	while (name[i])
		i++;
	if (name[i - 1] != '/')
		return (ft_strjoin(name, "/"));
	return (ft_strdup(name));
}

LA			*lst_add_arg(char *name)
{
	LA *new;

	if (!(new = (LA *)malloc(1 * sizeof(LA))))
		exit(EXIT_FAILURE);
	new->name = normed_path(name);
	new->total = 0;
	new->next = NULL;
	return (new);
}
