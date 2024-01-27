# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 14:14:55 by roglopes          #+#    #+#              #
#    Updated: 2024/01/25 15:00:22 by roglopes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

S_NAME			:= server
C_NAME			:= client

S_NAME_BONUS	:= server_bonus
C_NAME_BONUS	:= client_bonus

S_SOURCES		:= sources/mandatory/server.c
C_SOURCES		:= sources/mandatory/client.c

S_SOURCES_BONUS	:= sources/bonus/server_bonus.c
C_SOURCES_BONUS	:= sources/bonus/client_bonus.c

OBJECTS			= ./objects/
OBJECTS_BONUS	= ./objects_bonus/

HEADERS			:= -I ./includes/mandatory/ -I ./libft/include/
HEADERS_BONUS	:= -I ./includes/bonus/ -I ./libft/include/

OBJS_S			:= ${S_SOURCES:sources/mandatory/%.c=$(OBJECTS)%.o}
OBJS_C			:= ${C_SOURCES:sources/mandatory/%.c=$(OBJECTS)%.o}

OBJS_S_BONUS	:= ${S_SOURCES_BONUS:sources/bonus/%.c=$(OBJECTS_BONUS)%.o}
OBJS_C_BONUS	:= ${C_SOURCES_BONUS:sources/bonus/%.c=$(OBJECTS_BONUS)%.o}

LIBFT			:= ./libft/library/libft.a

CFLAGS			:= -Wextra -Wall -Werror -g3
CC				:= cc

COUNT			:= 0
RED				= \033[0;31m
GREEN			= \033[0;32m
MAGENTA			= \033[0;35m
RESET			= \033[0m
CYAN			= \033[1;36m
YELLOW			= \033[0;33m

all: libft $(OBJECTS) $(S_NAME) $(C_NAME)

$(OBJECTS):
	@mkdir -p $(OBJECTS)

$(OBJECTS)%.o: ./sources/mandatory/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(S_NAME): $(OBJS_S) 
	$(CC) $(OBJS_S) $(HEADERS) $(LIBFT) -o $(S_NAME)

$(C_NAME): $(OBJS_C)
	$(CC) $(OBJS_C) $(HEADERS) $(LIBFT) -o $(C_NAME)

bonus: libft $(OBJECTS_BONUS) $(S_NAME_BONUS) $(C_NAME_BONUS)

$(OBJECTS_BONUS):
	@mkdir -p $(OBJECTS_BONUS)

$(OBJECTS_BONUS)%.o: ./sources/bonus/%.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS_BONUS)

$(S_NAME_BONUS): $(OBJS_S_BONUS) 
	$(CC) $(OBJS_S_BONUS) $(HEADERS_BONUS) $(LIBFT) -o $(S_NAME_BONUS)

$(C_NAME_BONUS): $(OBJS_C_BONUS)
	$(CC) $(OBJS_C_BONUS) $(HEADERS_BONUS) $(LIBFT) -o $(C_NAME_BONUS)

libft:
	@make -C ./libft --no-print-directory

clean:
	@make clean -C ./libft --no-print-directory
	@rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	@printf "$(RED)Deleted objects Minitalk$(RESET)\n"

fclean: clean
	@echo "Cleaning all... 🧹"
	@rm -rf $(S_NAME) $(C_NAME) $(S_NAME_BONUS) $(C_NAME_BONUS)
	@make fclean -C ./libft --no-print-directory
	@printf "$(RED)Project is deleted Minitalk$(RESET)\n"
	@echo "✨ Cleaning complete! ✨"

norm:
	@norminette -R CheckForbiddenSource
	@echo "$(CYAN)NORMINETTE OK $(RESET)"

re: fclean all
	@echo "$(BLUE) $(NAME) Cleaned and rebuilt everything!$(DEF_COLOR)"

.PHONY: all clean fclean re libft bonus norm