/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 11:53:14 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 14:07:07 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		*get_content_name(LF *curr)
{
	return (((LI *)curr->content)->name);
}

char		*get_name(LF *curr)
{
	return (((char *)curr->content));
}

static int	check_comp(LF *curr, LF *head, int (*cmp)(char *, char *),
char **temp)
{
	char *temp1;
	char *temp2;

	temp1 = temp[0];
	temp2 = temp[1];
	if (cmp(temp1, temp2))
	{
		ft_memdel((void**)&temp1);
		ft_memdel((void**)&temp2);
		swap((void *)&curr->content, (void *)&curr->next->content);
		if (curr != head)
			return (1);
	}
	free(temp1);
	free(temp2);
	return (0);
}

int			q_sort(LF **list, char *path, int (*cmp)(char *, char *),
char *(*gnl)(LF *))
{
	static LF	*head = NULL;
	LF			*curr;
	char		**temp;

	if (!head)
		head = *list;
	if (!(curr = *list) || !curr->next)
	{
		head = NULL;
		return (1);
	}
	temp = (char **)malloc(2 * sizeof(char *));
	while (1)
	{
		temp[0] = ft_strjoin(path, gnl(curr));
		temp[1] = ft_strjoin(path, gnl(curr->next));
		if (check_comp(curr, head, cmp, temp))
		{
			free(temp);
			return (0);
		}
		if (q_sort(&curr->next, path, cmp, gnl))
			return (free_temp(&temp));
	}
}

int			q_sort_arg(LA **list, int (*cmp)(char *, char *))
{
	static LA	*head = NULL;
	LA			*curr;

	if (!head)
		head = *list;
	if (!(curr = *list) || !curr->next)
	{
		head = NULL;
		return (1);
	}
	while (1)
	{
		if (cmp(curr->name, curr->next->name))
		{
			swap((void *)&curr->name, (void *)&curr->next->name);
			if (curr != head)
				return (0);
		}
		if (q_sort_arg(&curr->next, cmp))
			return (1);
	}
}
