GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m

SDIR	= ./src
MDIR	= $(SDIR)/main
PDIR	= $(SDIR)/parse
UDIR	= $(SDIR)/utils
FDIR	= $(SDIR)/free_things
MLXDIR	= minilib

MSRCS	= main.c 
PSRCS	= check_map.c cut_strstr.c check_map_errors.c
USRCS	= ft_get_all.c __init__.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_strstr.c
FSRCS	= free_structs.c handle_error.c

MAIN	= $(addprefix $(MDIR)/,$(MSRCS))
PARSE	= $(addprefix $(PDIR)/,$(PSRCS))
UTILS	= $(addprefix $(UDIR)/,$(USRCS))
FREE	= $(addprefix $(FDIR)/,$(FSRCS))
FILES	= $(MAIN) $(UTILS) $(PARSE) $(FREE)
OBJS	= $(FILES:.c=.o)
MLIB	= $(MLXDIR)/libmlx.a
CFLAGS	= -Wall -Werror -Wextra 

ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif
NAME	= cub3d
CC		= gcc $(CFLAGS)

all: $(NAME)

%.o: %.c
	@printf "$(YELLOW)Generating cub3d objects... %-43.333s \r" $@
	@$(CC) -Imlx -c $< -o $@

minilibmake:
	@echo "$(GREEN)\n\nCompiling minilib..."
	@make -C $(MLXDIR)
	@echo "$(GREEN)Done"

$(NAME): $(OBJS) minilibmake
	@echo "$(GREEN)\n\nCompiling cub3d..."
	@$(CC) -I$(MLXDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit $(OBJS) -o $(NAME) $(MLIB)
	@echo "$(GREEN)Done"


clean:
	@echo "$(RED)\nDeleting objects..."
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Deleting executable..."
	@rm -f $(NAME)

re: fclean all 

.PHONY:	clean fclean all re minilibmake