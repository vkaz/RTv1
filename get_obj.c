/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaznodi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:48:01 by vkaznodi          #+#    #+#             */
/*   Updated: 2018/10/04 11:48:02 by vkaznodi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_vec(char *vec, int i, t_mlx *mlx, int o)
{
	char	**vector;

	if (o == 0)
	{
		vector = ft_strsplit(vec, ' ');
		digit(vector);
		mlx->i[i].vec.x = min_max(ft_atoi(vector[0]), -5001.0, 5001.0);
		mlx->i[i].vec.y = min_max(ft_atoi(vector[1]), -5001.0, 5001.0);
		mlx->i[i].vec.z = min_max(ft_atoi(vector[2]), -5001.0, 5001.0);
	}
	else
	{
		vector = ft_strsplit(vec, ' ');
		digit(vector);
		mlx->i[i].rot.x = (min_max(atoi(vector[0]), -50, 50) / 10);
		mlx->i[i].rot.y = (min_max(atoi(vector[1]), -50, 50) / 10);
		mlx->i[i].rot.z = (min_max(atoi(vector[2]), -50, 50) / 10);
	}
	free(vec);
	free_list_str(vector);
}

void	get_col(char *color, int i, t_mlx *mlx)
{
	char	**color1;

	color1 = ft_strsplit(color, ' ');
	digit(color1);
	mlx->i[i].color.r = min_max(ft_atoi(color1[0]), 0, 255);
	mlx->i[i].color.g = min_max(ft_atoi(color1[1]), 0, 255);
	mlx->i[i].color.b = min_max(ft_atoi(color1[2]), 0, 255);
	free(color);
	free_list_str(color1);
}

void	getd(char *str, int type, int i, t_mlx *mlx)
{
	if (type == 0)
		mlx->i[i].rad = min_max(ft_atoi(str), 1.0, 50000.0);
	else if (type == 1)
		mlx->light.intensity = min_max(ft_atoi(str), 1.0, 10.0) / 10;
	else if (type == 2)
		mlx->i[i].spec = min_max(ft_atoi(str), 1.0, 1000);
	free(str);
}

void	get_object(t_list *list, int i, t_mlx *mlx)
{
	if (ft_strstr(list->content, "color"))
		get_col(find(list->content, '(', ')'), i, mlx);
	else if (ft_strstr(list->content, "size"))
		getd(find(list->content, '(', ')'), 0, i, mlx);
	else if (ft_strstr(list->content, "pos"))
		get_vec(find(list->content, '(', ')'), i, mlx, 0);
	else if (ft_strstr(list->content, "rot"))
		get_vec(find(list->content, '(', ')'), i, mlx, 1);
	else if (ft_strstr(list->content, "spec"))
		getd(find(list->content, '(', ')'), 2, i, mlx);
}

void	get2(t_list *list, t_mlx *mlx)
{
	int i = 0;
	spaces(list);
	while (list && !ft_strstr(list->content, "}"))
	{
		if (ft_strstr(list->content, "light"))
		{
			spaces(list);
			while (list && !ft_strstr(list->content, "}"))
			{
				get_light(list, mlx, i);
				list = list->next;
			}
			i++;
		}
		else if (ft_strstr(list->content, "object"))
		{
			name(find(list->content, '(', ')'), mlx, mlx->i1);
			spaces(list);
			while (list && !ft_strstr(list->content, "}"))
			{
				get_object(list, mlx->i1, mlx);
				list = list->next;
			}
			mlx->i1++;
		}
		list = list->next;
	}
}
