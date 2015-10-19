/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 16:54:02 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <client.h>

void		receive_msg(int sock)
{
	int		c;
	char	buff[1024];

	ft_bzero(buff, 1024);
	while ((c = read(sock, buff, 1023)) > 0)
	{
		ft_putstr(buff);
		if ( buff[ft_strlen(buff) - 1] == 4 )
			break;
		ft_bzero(buff, 1024);
	}
}

void		control_cmd(char *buff, int sock)
{
	char	**arg;

	arg = ft_strsplit(buff, ' ');
	if (arg && arg[1] && ft_strncmp("get", arg[0], 3) == 0)
	{
		if (arg[1][ft_strlen(arg[1]) - 1] == '\n')
			arg[1][ft_strlen(arg[1]) - 1] = '\0';
		client_get_file(arg[1], sock);
	}
	else if (arg && arg[1] && ft_strncmp("put", arg[0], 3) == 0)
	{
		if (arg[1][ft_strlen(arg[1]) - 1] == '\n')
			arg[1][ft_strlen(arg[1]) - 1] = '\0';
		client_put_file(arg[1], sock);
	}
	else
		receive_msg(sock);
}

void		send_cmd(int sock)
{
	int		c;
	char	buff[1024];

	ft_bzero(buff, 1024);
	ft_putstr("\033[32mFTP\033[33m $> \033[0m");
	while ((c = read(0, buff, 1023)) > 0)
	{
		if (buff[0] == '\n')
		{
			ft_putstr("\033[32mFTP\033[33m $> \033[0m");
			continue;
		}
		write(sock, buff, c);
		control_cmd(buff, sock);
		ft_bzero(buff, 1024);
		ft_putstr("\033[32mFTP\033[33m $> \033[0m");
	}
}

