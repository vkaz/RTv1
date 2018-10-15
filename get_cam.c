/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:45:44 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/04 11:45:46 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		min_max(double x, double min, double max)
{
	if (x <= -5002)
		x = -5;
	if (x >= 5002)
		x = 5;
	if (x < min)
		x = min;
	else if (x > max)
		x = max;
	return (x);
}

char		*find(char *str, char start, char end)
{
	int		i;
	int		s;
	char	*res;

	s = 0;
	i = 0;
	if (!str || !start || !end || start == end)
		return (NULL);
	while (str[s] && str[s] != start)
		s++;
	if (!str[s])
		errore();
	while (str[s + i] && str[s + i] != end)
	{
		if (!str[s + i])
			return (NULL);
		i++;
	}
	res = ft_strsub(str, s + 1, i - 1);
	return (res);
}

void		scree_size(char *screen, t_mlx *mlx)
{
	char	**s_size;

	s_size = ft_strsplit(screen, ' ');
	mlx->vw = min_max(ft_atoi(s_size[0]), 100, 2000);
	mlx->vh = min_max(ft_atoi(s_size[1]), 100, 2000);
	free(screen);
	free_list_str(s_size);
}

void		get_cam(char *cam, int type, t_mlx *mlx)
{
	char	**cam_str;

	cam_str = ft_strsplit(cam, ' ');
	if (type == 0)
	{
		mlx->origin.x = min_max(ft_atoi(cam_str[0]), -500.0, 500.0);
		mlx->origin.y = min_max(ft_atoi(cam_str[1]), -500.0, 500.0);
		mlx->origin.z = min_max(ft_atoi(cam_str[2]), -500.0, 500.0);
	}
	else if (type == 1)
	{
		mlx->cam_rot.x = min_max(((float)ft_atoi(cam_str[0]) / 10), -50, 50);
		mlx->cam_rot.y = min_max(((float)ft_atoi(cam_str[1]) / 10), -50, 50);
		mlx->cam_rot.z = min_max(((float)ft_atoi(cam_str[2]) / 10), -50, 50);
	}
	free(cam);
	free_list_str(cam_str);
}

void		get(t_list *list, t_mlx *mlx)
{
	while (list && !ft_strstr(list->content, "{"))
		list = list->next;
	while (list && !ft_strstr(list->content, "}"))
	{
		if (strstr(list->content, "cam_pos"))
			get_cam(find(list->content, '(', ')'), 0, mlx);
		else if (strstr(list->content, "cam_dir"))
			get_cam(find(list->content, '(', ')'), 1, mlx);
		else if (strstr(list->content, "display_size"))
			scree_size(find(list->content, '(', ')'), mlx);
		list = list->next;
	}
}
