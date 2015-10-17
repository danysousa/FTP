/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danysousa <danysousa@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 18:53:22 by dsousa            #+#    #+#             */
/*   Updated: 2015/10/17 16:54:09 by danysousa        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "struct.h"
# include <stdlib.h>
# include <sys/socket.h>
# include <netdb.h>
# include <unistd.h>
# include <fcntl.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <libft.h>

void		control_cmd(t_info *i);
void		new_client(int sock, char *pwd);
void		ft_error(char *str);
char		*ch_pwd(char *old, char *new);
int			ft_is_dir(char *path);

#endif
