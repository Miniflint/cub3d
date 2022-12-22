GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m

SDIR	= ./src
MDIR	= $(SDIR)/main
PDIR	= $(SDIR)/parse
UDIR	= $(SDIR)/utils
FDIR	= $(SDIR)/free_things
MLXDIR	= minilib

MSRCS	= main.c setup.c movements.c raycast.c draw_minimap.c draw_cube.c new_ray_cast.c
PSRCS	= read_map.c cut_strstr.c check_map_errors.c get_map.c check_map_valid.c check_utils.c
USRCS	= ft_get_all.c __init__.c ft_strjoin.c ft_strlen.c ft_strdup.c ft_strstr.c ft_atoi.c __init__txtr.c
FSRCS	= free_structs.c handle_error.c nully.c

MAIN	= $(addprefix $(MDIR)/,$(MSRCS))
PARSE	= $(addprefix $(PDIR)/,$(PSRCS))
UTILS	= $(addprefix $(UDIR)/,$(USRCS))
FREE	= $(addprefix $(FDIR)/,$(FSRCS))
FILES	= $(MAIN) $(UTILS) $(PARSE) $(FREE)
OBJS	= $(FILES:.c=.o)
CFLAGS	= -Wall -Werror -Wextra 

# find os
UNAME_S = $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLXDIR= ./mlx-linux
	MLIB= $(MLXDIR)/libmlx.a
	OFLAGS=-L${MLXDIR} -lmlx -lXext -lX11 -lm -lz $(OBJS)
endif
# OFLAGS=-L${DIR_LIB_MLX} -lmlx  -I${DIR_LIB_MLX} -lXext -lX11 -lm -lz

ifeq ($(UNAME_S),Darwin)
	MLIB= $(MLXDIR)/libmlx.a
	OFLAGS=-L${MLXDIR} -lmlx -framework OpenGL -framework AppKit $(OBJS) 
endif

#lancer avec DEBUG=debug pour avoir le mode fsanitize etc
#ex:
#	make re DEBUG=debug
ifeq ($(DEBUG), debug)
	CFLAGS += -fsanitize=address -g3
endif
NAME	= cub3d
CC		= gcc $(CFLAGS)

all: $(NAME)

%.o: %.c
	@printf "$(YELLOW)Generating cub3d objects... %-43.333s \r" $@
	@$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)\n\nCompiling cub3d..."
	make -C $(MLXDIR)
	@$(CC) -I$(MLXDIR) $(OFLAGS) -o $(NAME) $(MLIB)
	@echo "$(GREEN)Done"

clean:
	@echo "$(RED)\nDeleting objects..."
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Deleting executable..."
	@rm -f $(NAME)

re: fclean all 

.PHONY:	clean fclean all re 
