/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:36:11 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 11:37:00 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

INF	*get_infos(void)
{
	static INF *infos;

	if (!infos)
	{
		if (!(infos = (INF*)malloc(1 * sizeof(INF))))
			exit(EXIT_FAILURE);
		return (infos);
	}
	return (infos);
}
