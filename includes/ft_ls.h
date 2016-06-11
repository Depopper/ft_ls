/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschafer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 13:28:02 by aschafer          #+#    #+#             */
/*   Updated: 2016/02/27 18:46:14 by aschafer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define LF t_list_file
# define LA t_list_arg
# define LI t_file_infos
# define INF t_infos
# define STAT struct stat
# define TRUE  1
# define FALSE 2
# define T_MONTH 15778800

# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include "libft.h"

extern int g_stop;
typedef struct s_file_infos	t_file_infos;
struct						s_file_infos
{
	char	*permision;
	int		nb_link;
	char	*user;
	char	*team;
	int		size;
	int		major;
	int		minor;
	char	*date;
	char	*name;
	int		color;
};

typedef struct s_list_arg	t_list_arg;
struct						s_list_arg
{
	char	*name;
	int		total;
	LA		*next;
};

typedef struct s_list_file	t_list_file;
struct						s_list_file
{
	void	*content;
	LF		*next;
};

typedef struct				s_infos
{
	int		ac;
	int		a;
	int		l;
	int		t;
	int		r;
	int		r_up;
	int		mt_files;
	int		*nb_space;
	int		(*sort)(char *, char *);
	char	*(*gnl)(LF *);
	LF		*file;
	LA		*dir;

}							t_infos;

void						init_infos(int ac, char **av);
INF							*get_infos(void);
int							fill_flags(int ac, char **av, INF *inf);
int							fill_files(int i, char **av, INF *inf);
LA							*lst_add_arg(char *name);
void						print_big_date(char *date);
LA							*lst_push_arg(LA **first, char *name);
LF							*lst_add_file(STAT *st, char *name, INF *i);
LF							*lst_push_file(LF **first,
STAT *st, char *name, INF *i);
int							free_temp(char ***temp);
int							sort_alpha(char *one, char *two);
int							sort_ralpha(char *one, char *two);
int							sort_time(char *one, char *two);
int							sort_rtime(char *one, char *two);
char						*get_name(LF *curr);
char						*get_content_name(LF *curr);
void						render_files(LF *first, INF *i);
void						render_file(LF *first);
void						render_lfiles(char *path, LF *first, int *space);
int							*innit_nb_space(void);
int							*count_nbspace(LF *first);
void						reset_nb_space(int *nb_space);
void						check_space(STAT *st1, int *space);
void						print_space(int value, int nb_link);
void						print_link(char *path, char *name);
void						print_path(LA *path, INF *i);
void						no_right(char *name);
void						print_date(char *date);
void						get_type(LI *new, STAT *st);
void						get_right(char *perm, STAT *st);
void						get_usr_group(LI *new, STAT *st);
void						fill_dir(LA *dir);
void						free_infos(INF *i);
void						free_path(LA *curr);
void						free_lst(LF *first, INF *i);
int							q_sort(LF **list, char *path,
int (*cmp)(char *, char *), char *(*gnl)(LF *));
int							q_sort_arg(LA **list, int (*cmp)(char *, char *));
#endif
