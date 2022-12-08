GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m

SDIR	= ./src
MDIR	= $(SDIR)/main
PDIR	= $(SDIR)/parse
UDIR	= $(SDIR)/utils
FDIR	= $(SDIR)/free_things

MSRCS	= main.c 
PSRCS	= check_map.c cut_strstr.c check_map_errors.c get_map.c
USRCS	= ft_get_all.c __init__.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_strstr.c ft_atoi.c
FSRCS	= free_structs.c handle_error.c

MAIN	= $(addprefix $(MDIR)/,$(MSRCS))
PARSE	= $(addprefix $(PDIR)/,$(PSRCS))
UTILS	= $(addprefix $(UDIR)/,$(USRCS))
FREE	= $(addprefix $(FDIR)/,$(FSRCS))
FILES	= $(MAIN) $(UTILS) $(PARSE) $(FREE)
OBJS	= $(FILES:.c=.o)
CFLAGS	= -Wall -Werror -Wextra 

ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif
NAME	= cub3d
CC		= gcc $(CFLAGS)

all: $(NAME)

%.o: %.c
	@printf "$(YELLOW)Generating cub3d objects... %-43.333s \r" $@
	@$(CC) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)\n\nCompiling cub3d..."
	@$(CC) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Done"

clean:
	@echo "$(RED)\nDeleting objects..."
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Deleting executable..."
	@rm -f $(NAME)

re: fclean all 

.PHONY:	clean fclean all re 
