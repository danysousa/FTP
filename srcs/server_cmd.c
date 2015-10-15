/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2014/05/12 19:16:25 by dsousa           ###   ########.fr       */
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
	ft_putendl_fd("[ls, pwd]", i->sock);
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
	if (i->argv[1])
		i->pwd = ch_pwd(i->pwd, i->argv[1]);
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


