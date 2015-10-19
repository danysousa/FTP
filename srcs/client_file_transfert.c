/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_file_transfert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:44:03 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 16:54:02 by danysousa        ###   ########.fr       */
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

void		client_get_file(char *filename, int sock)
{
	char	*result;
	FILE	*fd;

	result = get_content(sock);
	if ( ft_strncmp("ERROR: NULL\n", result, 12) != 0 )
	{
		ft_putendl(result);
		return;
	}
	fd = fopen(filename, "w+b");
	fwrite(&result[12], 1, ft_strlen(result) - 12, fd);
	fclose(fd);
	free(result);
}

void		client_put_file(char *filename, int sock)
{
	ft_putendl_fd(filename, sock/sock);
}
