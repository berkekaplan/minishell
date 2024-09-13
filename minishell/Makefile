# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkaplan     <@student.42kocaeli.com.tr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/21 18:44:22 by mkaplan           #+#    #+#              #
#    Updated: 2023/11/21 18:44:22 by mkaplan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minishell

CC		:= gcc
INCLUDE	:= ./libraries
CFLAGS	:= -ggdb -I $(INCLUDE) -I ./libft
LIBFT	= libft
FLAGS	= -Wall -Wextra -Werror

SRCDIR	:= src
SRC		:= src/check_utils/ft_fill_env.c \
			src/check_utils/check_input.c \
			src/parser/ft_trim_quotes.c \
			src/parser/parser_utils.c \
			src/parser/parser.c \
			src/parser/subsplit.c \
			src/init_and_terminate/free_functs.c \
			src/init_and_terminate/ft_banner.c \
			src/init_and_terminate/ft_error.c \
			src/init_and_terminate/ft_exit.c \
			src/init_and_terminate/ft_signal.c \
			src/fill_block/fill_block.c \
			src/fill_block/fill_blocks_utils.c \
			src/fill_block/fill_blocks_utils2.c \
			src/fill_block/heredocfile.c \
			src/expander/expander.c \
			src/expander/expander_utils.c \
			src/expander/expander_extras.c \
			src/executer/ft_exe_util.c \
			src/executer/ft_execute.c \
			src/executer/get_path.c \
			src/built_in_funcs/ft_cd.c \
			src/built_in_funcs/ft_echo.c \
			src/built_in_funcs/ft_env.c \
			src/built_in_funcs/ft_export.c \
			src/built_in_funcs/ft_pwd.c \
			src/built_in_funcs/ft_unset.c \
			src/built_in_funcs/ft_exit_b.c \
			src/built_in_funcs/built_in_utils.c \
			src/main.c

OBJDIR	:= ./objectives
OBJ		:= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	cp libft/libft.a .
	@$(CC) -L /usr/local/Cellar/readline/8.2.1/include -I /usr/local/Cellar/readline/8.2.1/include $(FLAGS) $(CFLAGS) $(OBJ) libft.a -lreadline -o $@

$(OBJDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -I ~/.brew/opt/readline/include -I /usr/local/Cellar/readline/8.2.1/include $(FLAGS) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT)
	rm -rf libft.a
	@rm -rf $(OBJDIR)

fclean:
	make fclean -C $(LIBFT)
	rm -rf libft.a
	@rm -rf $(OBJDIR)
	@rm -f $(NAME)

valgrind:
	valgrind --leak-check=full --show-leak-kinds=definite ./$(NAME)

norm:
	norminette libft
	norminette src

re:	fclean all

.PHONY: all clean fclean valgrind norm re