/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_file_transfert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/24 11:14:24 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <client.h>

char		*get_content(int sock)
{
	int		c;
	char	buff[1024];
	char	*result;
	char	*tmp;

	ft_bzero(buff, 1024);
	result = ft_strdup("");
	while ((c = recv(sock, buff, 1023, 0)) >= 0)
	{
		tmp = ft_strjoin(result, buff);
		free(result);
		result = ft_strdup(tmp);
		free(tmp);
		if ( buff[ft_strlen(buff) - 1] == 4 )
			break;
		ft_bzero(buff, 1024);
	}

	return (result);
}

char		*ft_line(int sock)
{
	char	buff[2];
	char	*result;
	char	*tmp;

	ft_bzero(buff, 2);
	result = ft_strdup("");
	while (1)
	{
		recv(sock, buff, 1, 0);
		tmp = ft_strjoin(result, buff);
		free(result);
		result = ft_strdup(tmp);
		free(tmp);
		if (buff[0] == '\n')
			return(result);
		ft_bzero(buff, 2);
	}

	return (result);
}

void		client_get_file(char *filename, int sock)
{
	char	*result;
	int		fd;
	int		size;

	result = ft_line(sock);
	if ( ft_strncmp("ERROR: NULL\n", result, 12) != 0 )
	{
		ft_putendl(result);
		return;
	}
	free(result);
	result = ft_line(sock);
	size = ft_atoi(&result[6]);
	(void) filename;
	fd = open(filename, O_WRONLY | O_CREAT);
	free(result);
	result = malloc(sizeof(char) * (size + 1));
	ft_bzero(result, size + 1);
	while (size > 0)
	{
		recv(sock, result, 512, 0);
		write(fd, result, 512);
		size -= 512;
	}
	close(fd);
	free(result);
}

void		client_put_file(char *filename, int sock)
{
	ft_putendl_fd(filename, sock/sock);
}
