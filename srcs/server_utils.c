/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 16:54:02 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(-1);
}

int			ft_is_dir(char *path)
{
	DIR		*fd;

	if ((fd = opendir(path)) == NULL)
		return (0);
	closedir(fd);
	return (1);
}

t_list		*path_to_list(char *path)
{
	char	**array;
	t_list	*result;
	size_t	i;

	array = ft_strsplit(path, '/');
	result = new_list();
	i = 0;
	while (array[i])
	{
		add_elem(result, array[i]);
		i++;
	}

	return (result);
}

char		*list_to_path(t_list *list)
{
	char	*result;

	result = ft_strdup("");
	t_elem	*elem;
	elem = list->first;
	while (elem)
	{
		result = ft_strjoin(result, "/");
		result = ft_strjoin(result, elem->data);
		elem = elem->next;
	}
	return (result);
}

char		*ch_pwd(char *old, char *new)
{
	t_list	*l_old;
	t_list	*l_new;
	t_elem	*e;
	char	*result;

	if (!new || !old)
	{
		result = old ? new : old;
		return (result);
	}
	if (new[0] == '/')
		return (ft_strdup(new));
	l_old = path_to_list(old);
	l_new = path_to_list(new);
	e = l_new->first;
	while (e)
	{
		if (ft_strlen(e->data) == 1 && ((char *)e->data)[0] == '.')
		{
			e = e->next;
			continue;
		}
		else if (ft_strlen(e->data) == 2 && ft_strcmp(e->data, "..") == 0)
		{
			if (l_old->size != 0)
				l_old->first = del_elem(l_old, l_old->size - 1);
		}
		else
			add_elem(l_old, e->data);
		e = e->next;
	}

	return (list_to_path(l_old));
}
