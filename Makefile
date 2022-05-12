# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyaiche <lyaiche@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/11 17:30:02 by lyaiche           #+#    #+#              #
#    Updated: 2022/05/12 14:31:32 by lyaiche          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAIN_SRC = main.c

SRCS_SRC = test.c
				
SRCS_OBJ = ${addprefix ${OBJDIR}, ${SRCS_SRC:%.c=%.o}}

MAIN_OBJ = ${addprefix ${OBJDIR}, ${MAIN_SRC:%.c=%.o}} ${SRCS_OBJ}

#====#
#Tags#
#====#

OBJDIR = ./objs/
SRCDIR = ./main/
COMMONDIR = ./srcs/
INCLUDES = ./includes/
LIBFT = ./libft/
NAME = cub3d
CFLAGS = -Wall -Wextra -Werror ${SANIFLAG}
SANIFLAG = -fsanitize=address -g

#=========#
#Commandes#
#=========#					

${OBJDIR}%.o : ${SRCDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}
${OBJDIR}%.o : ${CHECKDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${OBJDIR}%.o : ${COMMONDIR}%.c
								@gcc ${CFLAGS} -c $< -o $@ -I ${INCLUDES}

${NAME}: 						${OBJDIR} ${MAIN_OBJ}
								@gcc ${CFLAGS} ${MAIN_OBJ} -o ${NAME} -L ${LIBFT} -lft 
								@printf "\e[32;3m$@ successfully built\e[0m\n"

${OBJDIR}:						
								@mkdir -p ${OBJDIR}

all:							${NAME}
								

clean:
								@rm -rf ${OBJDIR}
								@printf "\e[31;3mClean files\e[0m\n"

fclean:							clean
								@rm -f ${NAME}
								@printf "\e[31;3mClean exec\e[0m\n"

re:								fclean all

.PHONY:							all clean fclean re