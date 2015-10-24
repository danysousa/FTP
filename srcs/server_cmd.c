/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/24 11:13:44 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <server.h>

void		ft_ls(t_info *i)
{
	struct dirent*		elem;

	i->folder = opendir(i->pwd);
	if (i->folder == NULL)
	{
		ft_putendl_fd("Permission denied\4", i->sock);
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
	ft_putendl_fd("Goodbye !\4", i->sock);
	i->end = 1;
}

void		ft_cd(t_info *i)
{
	char	*tmp;

	if (i->argv[1])
	{
		tmp = ch_pwd(i->pwd, i->argv[1]);
		if ( chdir(tmp) == -1 )
		{
			ft_putendl_fd("cd: no such file or directory\4", i->sock);
			chdir(i->pwd);
			free(tmp);
			return ;
		}
		free(i->pwd);
		i->pwd = tmp;
	}
	ft_putendl_fd(i->pwd, i->sock);
}

void		ft_get(t_info *i)
{
	char			*path;
	struct stat		s;
	char			buff[513];
	int				fd;
	int				count;

	if (!i->argv[1])
		return ;
	if (i->argv[1] && i->argv[1][0] != '/')
		path = ft_trunc("%s/%s", i->pwd, i->argv[1]);
	else
		path = ft_strdup(i->argv[1]);
	if (ft_is_dir(path))
	{
		free(path);
		ft_putendl_fd("ERROR: can't get directory\4", i->sock);
		return ;
	}
	if ((fd = open(path, O_RDONLY)) == -1)
	{
		free(path);
		ft_putendl_fd("ERROR: no such file or permission denied\4", i->sock);
		return ;
	}
	free(path);
	ft_bzero(buff, 512);
	send(i->sock, "ERROR: NULL\n", 12, 0);
	fstat(fd, &s);
	count = 0;
	if (s.st_blocks <= 0)
	{
		close(fd);
		return ;
	}
	path = ft_trunc("SIZE: %d", s.st_blocks * 512);
	ft_putendl_fd(path, i->sock);
	ft_putendl_fd(path, 1);
	free(path);
	while (count < s.st_blocks)
	{
		read(fd, buff, 512);
		send(i->sock, buff, 512, 0);
		ft_bzero(buff, 512);
		count++;
	}
	close(fd);
}

void		control_cmd(t_info *i)
{
	int				j;
	static t_cmd	pt[7] =
	{
		{"ls", ft_ls},
		{"pwd",ft_pwd},
		{"help",ft_help},
		{"quit",ft_exit},
		{"cd",ft_cd},
		{"get",ft_get},
		{NULL, NULL}
	};

	j = 0;
	while (j < 6)
	{
		if (ft_strncmp(i->cmd, pt[j].cmd, ft_strlen(pt[j].cmd)) == 0)
		{
			pt[j].f(i);
			ft_putstr_fd("\4", i->sock);
			return ;
		}
		j++;
	}
	ft_putendl_fd("Command not found : use help\n\4", i->sock);

}


