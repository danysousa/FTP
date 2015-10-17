/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 15:35:32 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void		ft_ls(t_info *i)
{
	struct dirent*		elem;

	i->folder = opendir(i->pwd);
	if (i->folder == NULL)
	{
		ft_putendl_fd("Permission denied", i->sock);
		return ;
	}

	while ((elem = readdir(i->folder)) != NULL)
		ft_putendl_fd(elem->d_name, i->sock);
	closedir(i->folder);
}

void		ft_help(t_info *i)
{
	ft_putendl_fd("Allowed command :", i->sock);
	ft_putendl_fd("[ls, pwd, cd, quit]", i->sock);
}

void		ft_pwd(t_info *i)
{
	ft_putendl_fd(i->pwd, i->sock);
}

void		ft_exit(t_info *i)
{
	ft_putendl_fd("Goodbye !", i->sock);
	i->end = 1;
}

void		ft_cd(t_info *i)
{
	char	*tmp;

	if (i->argv[1])
	{
		tmp = ch_pwd(i->pwd, i->argv[1]);
		free(i->pwd);
		i->pwd = tmp;
	}
	ft_putendl_fd(i->pwd, i->sock);
}

void		control_cmd(t_info *i)
{
	int				j;
	static t_cmd	pt[6] =
	{
		{"ls", ft_ls},
		{"pwd",ft_pwd},
		{"help",ft_help},
		{"quit",ft_exit},
		{"cd",ft_cd},
		{NULL, NULL}
	};

	j = 0;
	while (j < 5)
	{
		if (ft_strncmp(i->cmd, pt[j].cmd, ft_strlen(pt[j].cmd)) == 0)
		{
			pt[j].f(i);
			return ;
		}
		j++;
	}
}


