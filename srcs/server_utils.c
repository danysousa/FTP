/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/12 19:16:25 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void		ft_error(char *str)
{
	ft_putendl(str);
	exit(-1);
}

void		del_last(char **array)
{
	int		i;

	i = 0;
	while (array[i] && array[i + 1])
		i++;

	if (array[i])
	{
		free(array[i]);
		array[i] = NULL;
	}
}

char		**add_last(char **array, char *elem)
{
	char	**result;
	int		i;

	i = 0;
	while (array[i])
		i++;

	result = malloc(sizeof(char *) * i + 2);
	i = 0;
	while (array[i])
	{
		result[i] = ft_strdup(array[i]);
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	result[i] = ft_strdup(elem);
	result[i + 1] = NULL;
	free(array);
	return (result);
}

char		*ch_pwd(char *old, char *new)
{
	char	*result;
	char	**a_old;
	char	**a_new;
	int		i;

	i = 0;
	if (new == NULL || old == NULL)
	{
		result = new == NULL ? old : new;
		return (result);
	}
	if (new[0] == '/')
		return (new);

	a_old = ft_strsplit(old, '/');
	a_new = ft_strsplit(new, '/');
	while (a_new[i])
	{
		if (ft_strlen(a_new[i]) == 2 && ft_strcmp(a_new[i], "..") == 0)
			del_last(a_old);
		else if (ft_strlen(a_new[i]) == 1 && ft_strcmp(a_new[i], ".") == 0)
		{
			i++;
			continue;
		}
		else
			a_old = add_last(a_old, a_new[i]);
		i++;
	}

	i = 1;
	result = ft_strjoin(a_old[0], "/");
	while (a_old[i])
	{
		result = ft_strjoin(result, a_old[i]);
		result = ft_strjoin(result, "/");
		i++;
	}

	return (result);
}
