/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:49:58 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 19:10:25 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int g_stop;
int g_file_stop;

int	main(int ac, char **av)
{
	INF *i;

	g_stop = 0;
	g_file_stop = 0;
	init_infos(ac, av);
	i = get_infos();
	free_infos(i);
	return (0);
}
