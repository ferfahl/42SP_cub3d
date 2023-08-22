################################################################################
##                                 42 CUB3D                                   ##
################################################################################

#static library's name
NAME =		cub3D

ARGS = 		./assets/maps/minimalist.cub

#colors
RESET 			:= \033[0m
GREEN			=	\e[32m
CYAN  			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m

################################################################################
##                                 COMPILATION                                ##
################################################################################

#compiling
CC =	cc
FLAGS =	-Wall -Werror -Wextra -g3
MLXFLAGS =	-lm -lXext -lX11
GDB =	gdb
VAL =	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --tool=memcheck
# --track-fds=yes --trace-children=yes

# clean
RM =		-rm -f
RM_DIR =	rm -rf

#tranform into .o
OBJ_MANDATORY = $(MANDATORY_FILES:%.c=$(OBJPATH)/%.o)

#printing
LOG   			:= printf "[$(GREEN)PROJECT_INFO$(RESET)] %s\n"
LOG_SUC			:= printf "[$(CYAN)COMPILING_INFO$(RESET)] %s\n"

#compiling bar
NUMBER_OF_FILES	=	$(words $(MANDATORY_FILES))
PROGRESS			=	0

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

#src paths
CHECKS =		checks
WIND =			mlx_util
EXIT =			exit
PLAYER =		player_handle
MAP =			map_handle
RAY =			rays
3D =			3d_rendering

#src functions
MANDATORY_FILES =	${3D}/background.c					\
					$(3D)/nbr_adjustments.c				\
					$(3D)/render_walls.c				\
					${CHECKS}/01_check_args.c			\
					${CHECKS}/02_read_input.c			\
					${CHECKS}/03_check_colors.c			\
					${CHECKS}/04_check_textures.c		\
					${EXIT}/errors.c					\
					${EXIT}/exit.c						\
					${EXIT}/free_all.c					\
					${EXIT}/free_cub.c					\
					${MAP}/check_map.c					\
					${MAP}/check_path.c					\
					${MAP}/draw_minimap.c				\
					${MAP}/map_limit.c					\
					${MAP}/print_map.c					\
					${MAP}/read_map.c					\
					${WIND}/click_handler.c				\
					${WIND}/draw_line.c					\
					${WIND}/draw.c						\
					${WIND}/key_handler.c				\
					${WIND}/load_textures.c				\
					${WIND}/render.c					\
					${WIND}/window.c					\
					${PLAYER}/player_moves.c			\
					${RAY}/cast_rays.c					\
					${RAY}/find_hit_horz.c				\
					${RAY}/find_hit_vert.c				\
					${RAY}/ray_check.c					\
					${RAY}/ray_utils.c					\
					calculate.c							\
					start_cub.c							\
					main.c								\

#headers
HEADER =			header/cub3d.h						\
					header/defs.h						\
					header/buttons.h					\
					header/structs.h					\

#directories
OBJPATH =			temps
VPATH =				sources
LIBFT_PATH =		./../libft
LIBFT =				$(LIBFT_PATH)/libft.a
MLX_PATH =			./../minilibx-linux
MLX	 =				$(MLX_PATH)/libmlx.a

#header to libft.h
INCLUDE =	-I ./header -I $(LIBFT_PATH)

################################################################################
##                                    RULES                                   ##
################################################################################

#make
all: $(OBJPATH) $(NAME)

#make bonus
bonus:
		@make -C ../bonus --no-print-directory
		@$(LOG) "Compiling bonus"

##folder for temporary objects
$(OBJPATH):
		@$(LOG) "Creating objects directory..."
		@mkdir -p $(OBJPATH)

##make libft
$(LIBFT):
		@make -C $(LIBFT_PATH) --no-print-directory

#make mlx
$(MLX):
		@make -C $(MLX_PATH)
		@$(LOG) "Compiling MLX"

##rule name - make cub3D
$(NAME): $(LIBFT) $(MLX) $(OBJ_MANDATORY)
		@cc $(FLAGS) -o $(NAME) $(OBJ_MANDATORY) $(LIBFT) $(MLX) $(MLXFLAGS)
		@$(LOG_SUC) "$(NAME) succesfully compiled!"

##compile MANDATORY
$(OBJPATH)/%.o: $(VPATH)/%.c $(HEADER)
		@mkdir -p $(dir $@)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)
		@echo -n "$(YELLOW)Compiling ${NAME} $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_FILES)))%\r"
		$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

#make clean -> remove objects
clean:
		@make clean -C $(LIBFT_PATH) --no-print-directory
		@make clean -C ../bonus --no-print-directory
		@$(LOG) "Removing objects..."
		@$(RM) $(OBJ_MANDATORY)

#make fclean -> remove all
fclean: clean
		@make fclean -C $(LIBFT_PATH) --no-print-directory
		@make fclean -C ../bonus --no-print-directory
		@$(LOG) "Removing executable..."
		@$(RM) $(NAME)
		@$(RM) $(NAME)_bonus
		@$(RM_DIR) $(OBJPATH)
		@$(LOG_SUC) "Cleaned project!"
		@$(RM) 

#make re -> clear all and recompliles
re:		fclean all
		@$(LOG_SUC) "Recompiled succesfully!"

##avoids double inclusion
.PHONY: all clean fclean re bonus

#make git m="message" -> commit to git
git:
		git add .
		git commit -m "$(m)"
		git push

norm:
		clear
		@norminette ${VPATH} | grep -v "OK!" || echo "All srcs ok!"
		@norminette ${HEADER} | grep -v "OK!" || echo "All headers ok!"

norm_CI:
		norminette ${addprefix ${VPATH}/, ${MANDATORY_FILES}}

#make val -> mcheck
val:
		$(VAL) ./$(NAME) ./assets/maps/simple.cub

run:
	./$(NAME) ./assets/maps/simple.cub