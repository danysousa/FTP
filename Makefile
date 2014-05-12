# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/26 13:13:47 by rbenjami          #+#    #+#              #
#    Updated: 2014/05/12 19:21:56 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include		libft/Makefile.sources

export	CC		=	cc

export	INC		=	-I $(PWD)/libft

NAME			=	serveur

CLIENT			=	client

CFLAGS			= -Wall -Wextra -Werror -g

INC				+=	-I includes

INC_DIR			=	includes/

INC_FILES		=	ftp.h\
					struct.h

INC_SRC			=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR			=	srcs/

FILES_SERV		=	serveur.c

FILES_CLIENT	=	client.c

SRC_SERV		=	$(addprefix $(SRC_DIR), $(FILES_SERV))

OBJ_SERV		=	$(SRC_SERV:.c=.o)

SRC_CLIENT		=	$(addprefix $(SRC_DIR), $(FILES_CLIENT))

OBJ_CLIENT		=	$(SRC_CLIENT:.c=.o)

LIB				=	-L./ -lft -ltermcap

OBJ_LIB			=	$(libft/SRC_LIB:.c=.o)

HEAD_LIB		=	libft/libft.h

all:			libft.a $(NAME) $(CLIENT)

libft.a:		libft/$(OBJ_LIB) $(HEAD_LIB)
	@make -C libft

$(NAME):		$(OBJ_SERV)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ_SERV) $(LIB)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(CLIENT):		$(OBJ_CLIENT)
	@$(CC) $(CFLAGS) -o $(CLIENT) $(OBJ_CLIENT) $(LIB)
	@echo ""
	@echo "\033[33m"compilation of $(CLIENT) : "\033[32m"Success"\033[0m"

$(OBJ_SERV):			$(INC_SRC) libft.a

$(OBJ_CLIENT:			$(INC_SRC) libft.a

%.o:			%.c $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@rm -f $(OBJ_SERV)
	@rm -f $(OBJ_CLIENT)
	@echo "\033[31m"Objects of $(NAME) and $(CLIENT) : deleted"\033[0m"

fclean:			clean
	@rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
	@rm -f $(CLIENT)
	@echo "\033[31m"$(CLIENT) : deleted"\033[0m"
	@make fclean -C libft

re:				fclean all

.PHONY:			all clean fclean re
