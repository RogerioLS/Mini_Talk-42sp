# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 22:11:31 by roglopes          #+#    #+#              #
#    Updated: 2024/01/27 17:52:22 by roglopes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ./sources/libft.a

SOURCES		= ft_isalpha.c \
			ft_isdigit.c   \
			ft_isalnum.c   \
			ft_isascii.c   \
			ft_isprint.c   \
			ft_strlen.c    \
			ft_memset.c    \
			ft_bzero.c     \
			ft_memcpy.c    \
			ft_memmove.c   \
			ft_strlcpy.c   \
			ft_strlcat.c   \
			ft_toupper.c   \
			ft_tolower.c   \
			ft_strchr.c    \
			ft_strrchr.c   \
			ft_strncmp.c   \
			ft_memchr.c    \
			ft_memcmp.c    \
			ft_strnstr.c   \
			ft_atoi.c      \
			ft_calloc.c    \
			ft_strdup.c    \
			ft_substr.c    \
			ft_strjoin.c   \
			ft_strtrim.c   \
			ft_split.c     \
			ft_itoa.c      \
			ft_strmapi.c   \
			ft_striteri.c  \
			ft_putchar_fd.c\
			ft_putstr_fd.c \
			ft_putendl_fd.c\
			ft_putnbr_fd.c \
			ft_printf.c    \
			ft_putchar.c   \
			ft_puthex.c    \
			ft_putnbr.c    \
			ft_putptr.c    \
			ft_putstr.c    \
			ft_putunsign.c \

SOURCES_B	= ft_lstnew_bonus.c    \
			ft_lstadd_front_bonus.c\
			ft_lstsize_bonus.c     \
			ft_lstlast_bonus.c     \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c   \
			ft_lstclear_bonus.c    \
			ft_lstiter_bonus.c     \
			ft_lstmap_bonus.c      \

INCLUDES	= ./include/

SOURCES		:= $(addprefix ./sources/,$(SOURCES))
OBJECTS		= $(SOURCES:./sources/%.c=./sources/%.o)

SOURCES_B	:= $(addprefix ./sources/,$(SOURCES_B))
OBJECTS_B	= $(SOURCES_B:./sources/%.c=./sources/%.o)

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

COUNT		:= 0
RED			= \033[0;31m
GREEN		= \033[0;32m
MAGENTA		= \033[0;35m
RESET		= \033[0m
CYAN		= \033[1;36m
YELLOW		=\033[0;33m

all: $(NAME)

$(NAME): $(OBJECTS)

bonus: $(OBJECTS_B)

./sources/%.o: ./sources/%.c
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)
	@ar rcs $(NAME) $@
	@printf "$(GREEN)Compiling Libft %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(SOURCES)))))

clean:
	@$(RM) $(OBJECTS) $(OBJECTS_B)
	@printf "$(RED)Deleted objects Libft$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(RED)Project is deleted Libft$(RESET)\n"

re: fclean all

norm:
	@norminette -R CheckForbiddenSource
	@echo "$(CYAN)NORMINETTE OK $(RESET)"

.PHONY: all clean fclean re bonus norm