/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:44:09 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/09/24 11:44:11 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			ch(t_list *list, t_mlx *mlx)
{
	int		i;
	int		i1;

	i = 0;
	i1 = 0;
	while (list != NULL)
	{
		if (ft_strstr(list->content, "camera"))
		{
			get(list, mlx);
			i++;
		}
		if (ft_strstr(list->content, "scene"))
		{
			if (count_li(list, mlx) == -1)
				return (-1);
			get2(list, mlx);
			i1++;
		}
		list = list->next;
	}
	if (i != 1 || i1 != 1)
		return (-1);
	return (0);
}

int			count_ob(t_list *list, t_mlx *mlx)
{
	int a;
	int	l;

	a = 0;
	l = 0;
	while (list)
	{
		if (ft_strstr(list->content, "object"))
			a++;
		if (ft_strstr(list->content, "light"))
			l++;
		list = list->next;
	}
	if (a == 0 || l == 0)
		return (-1);
	mlx->i = (t_vec *)malloc(sizeof(t_vec) * a);
	mlx->l = a;
	return (0);
}

void		flist(t_list *list)
{
	t_list		*tmp;

	while (list != NULL)
	{
		tmp = list;
		free(list->content);
		list = list->next;
		free(tmp);
	}
}

int			read_from_file(char *argv, t_mlx *mlx)
{
	int		fd;
	char	*line;
	t_list	*list;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		ft_lstpushback(&list, line, ft_strlen(line));
		free(line);
	}
	close(fd);
	if (count_ob(list, mlx) == -1 || che_in(mlx, list) == -1 ||
		count_cam(list, mlx) == -1 || ch(list, mlx) == -1 ||
		count_sc(list, mlx))
	{
		flist(list);
		return (-1);
	}
	flist(list);
	return (0);
}
