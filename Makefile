# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 15:27:59 by OrioPrisc         #+#    #+#              #
#    Updated: 2023/09/27 12:58:36 by OrioPrisc        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
SRC = ft_atoi.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isascii.c\
	ft_isdigit.c\
	ft_isprint.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_strlcat.c\
	ft_strlcpy.c\
	ft_strlen.c\
	ft_strnstr.c\
	ft_tolower.c\
	ft_toupper.c\
	ft_strncmp.c\
	ft_strcmp.c\
	ft_strrchr.c\
	ft_strchr.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\
	ft_split.c\
	ft_itoa.c\
	ft_memchrnul.c\
	ft_strnchrnul.c\
	ft_strchrnul.c\
	ft_strnlen.c\
	ft_strcpy.c\
	ft_index.c\
	ft_maxint.c\
	ft_absint.c\
	ft_minint.c\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\
	ft_strncpy.c\
	ft_strtol.c\
	ft_next_non_space.c\
	ft_strtol_check_int.c\
	ft_strtol_check_long.c\
	ft_strtold.c\
	ft_strpbrknul.c\
	ft_isspace.c\
	ft_next_non_match.c\
	ft_strspn.c\
	ft_strcspn.c\
	ft_memswp.c\
	ft_fake_strcoll.c\
	ft_strcmp_custom.c\


LIBS	=	libftprintf.a\
			libgetnextline.a\
			libvector.a\


SRC_FOLDER = srcs/

HEADERS_FOLDER = includes/
OBJ_FOLDER = objs/

OBJS		=	$(patsubst %.c,$(OBJ_FOLDER)%.o,$(SRC))
COMMANDS	=	$(patsubst %.c,$(OBJ_FOLDER)%.cc,$(SRC))
DEPENDS		:=	$(patsubst %.c,$(OBJ_FOLDER)%.d,$(SRC))
SUBMODULES	:= $(patsubst lib%.a,%/.git,$(LIBS))

CFLAGS = -Wall -Wextra -Werror -fPIC

all: $(NAME) compile_commands.json
	
%/.git :
	git submodule update --init $*

lib%.a : %/ %/.git
	make -C $<
	cp $</$@ $@

$(NAME): $(OBJS) $(LIBS)
	ar rcs $(NAME) $(OBJS)

COMP_COMMAND = $(CC) -c $(CFLAGS) $(addprefix -I,$(HEADERS_FOLDER)) -MMD -MP $< -o $@
CONCAT = awk 'FNR==1 && NR!=1 {print ","}{print}'

$(OBJ_FOLDER)%.o $(OBJ_FOLDER)%.cc: $(SRC_FOLDER)%.c Makefile
	$(COMP_COMMAND)
	@printf '{\n\t"directory" : "$(shell pwd)",\n\t"command" : "$(COMP_COMMAND)",\n\t"file" : "$<"\n}' > $(OBJ_FOLDER)$*.cc

compile_commands.json : $(COMMANDS) Makefile
	@echo "Making compile_commands.json"
	@echo "[" > compile_commands.json
	@$(CONCAT) $(COMMANDS) >> compile_commands.json
	@echo "]" >> compile_commands.json

clean:
	rm -f $(OBJS) $(LIBS) $(DEPENDS) $(COMMANDS)
	for lib in $(patsubst lib%.a,%,$(LIBS)) ; do \
		make -C $$lib clean; \
	done

fclean: clean
	rm -f $(NAME) compile_commands.json
	for lib in $(patsubst lib%.a,%,$(LIBS)) ; do \
		make -C $$lib fclean; \
	done

re: fclean all
	
.PHONY: all clean fclean re bonus so
.SUFFIXES:
.PRECIOUS: $(SUBMODULES)
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
