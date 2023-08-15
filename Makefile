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
CHECKS_PATH =		checks
WIND =			mlx_util
EXIT =			exit
PLAYER =		player_handle
MAP =			map_handle

#src functions
MANDATORY_FILES =	${CHECKS_PATH}/00_errors.c			\
					${CHECKS_PATH}/01_check_args.c		\
					${PLAYER}/player_moves.c			\
					${MAP}/mini_map.c					\
					${WIND}/window.c					\
					${WIND}/click_handler.c				\
					${WIND}/key_handler.c				\
					${WIND}/image.c						\
					${WIND}/draw.c						\
					${WIND}/draw_line.c					\
					${WIND}/temp.c						\
					${EXIT}/exit.c						\
					calculate.c							\
					start_cub.c							\
					mainfer.c							\
					# main.c								\

#headers
HEADER =			header/cub3d.h						\
					header/defs.h						\
					header/buttons.h					\

#directories
OBJPATH =			temps
VPATH =				sources
LIBFT_PATH =		./libft
LIBFT =				$(LIBFT_PATH)/libft.a
MLX_PATH =		./minilibx-linux
MLX	 = $(MLX_PATH)/libmlx.a

#header to libft.h
INCLUDE =	-I ./header -I $(LIBFT_PATH)
################################################################################
##                                    RULES                                   ##
################################################################################

#make
all: $(OBJPATH) $(NAME)

#make bonus
bonus: $(OBJPATH) $(B_NAME)

##folder for temporary objects
$(OBJPATH):
		@$(LOG) "Creating objects directory..."
		@mkdir -p $(OBJPATH)

##make libft
$(LIBFT):
		@make -C $(LIBFT_PATH) --no-print-directory

#make mlx
$(MLX):
		make -C $(MLX_PATH)

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

#make val -> mcheck
val:
		$(VAL) ./$(NAME)

#make clean -> remove objects
clean:
		@make clean -C $(LIBFT_PATH) --no-print-directory
		@$(LOG) "Removing objects..."
		@$(RM) $(OBJ_MANDATORY)

#make fclean -> remove all
fclean: clean
		@make fclean -C $(LIBFT_PATH) --no-print-directory
		@$(LOG) "Removing executable..."
		@$(RM) $(NAME) $(B_NAME)
		@$(RM_DIR) $(OBJPATH)
		@$(LOG_SUC) "Cleaned project!"

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
