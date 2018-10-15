/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:44:09 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/09/24 11:44:11 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			count_sc(t_list *list, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (list)
	{
		if (ft_strstr(list->content, "}"))
			i++;
		list = list->next;
	}
	if (i != mlx->l + 3)
		return (-1);
	return (0);
}

int			che_in(t_mlx *mlx, t_list *list)
{
	while (list)
	{
		if (ft_strstr(list->content, "object(sphere)"))
		{
			if (count_i_s(mlx, list) == -1)
				return (-1);
		}
		if (ft_strstr(list->content, "object(plane)"))
		{
			if (count_i_p(mlx, list) == -1)
				return (-1);
		}
		if (ft_strstr(list->content, "object(cone)"))
		{
			if (count_i(mlx, list) == -1)
				return (-1);
		}
		if (ft_strstr(list->content, "object(cylinder)"))
		{
			if (count_i(mlx, list) == -1)
				return (-1);
		}
		list = list->next;
	}
	return (0);
}

void		i_null(t_mlx *mlx)
{
	mlx->ic = 0;
	mlx->is = 0;
	mlx->ip = 0;
	mlx->ir = 0;
	mlx->isp = 0;
}

void		get_light(t_list *list, t_mlx *mlx)
{
	char *str;
	char **str1;

	if (ft_strstr(list->content, "pos"))
	{
		str = find(list->content, '(', ')');
		str1 = ft_strsplit(str, ' ');
		mlx->light.position.x = min_max(ft_atoi(str1[0]), -500, 500);
		mlx->light.position.y = min_max(ft_atoi(str1[1]), -500, 500);
		mlx->light.position.z = min_max(ft_atoi(str1[2]), -500, 500);
		free(str);
		free_list_str(str1);
	}
	else if (ft_strstr(list->content, "power"))
	{
		str = find(list->content, '(', ')');
		if (str)
			mlx->light.intensity = min_max(ft_atoi(str), 1.0, 10.0) / 10;
		free(str);
	}
}

void		name(char *name, t_mlx *mlx, int i)
{
	if (ft_strstr(name, "plane"))
		mlx->i[i].name = "plane";
	else if (ft_strstr(name, "sphere"))
		mlx->i[i].name = "sphere";
	else if (ft_strstr(name, "cylinder"))
		mlx->i[i].name = "cylinder";
	else if (ft_strstr(name, "cone"))
		mlx->i[i].name = "cone";
	else if (ft_strstr(name, "light"))
		mlx->i[i].name = "light";
	free(name);
}
