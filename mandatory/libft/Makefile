################################################################################
##                                 42 LIBFT                                   ##
################################################################################

#header source
HEADER = libft.h

#static library's name
NAME = libft.a

#colors
RESET 		:= \033[0m
YELLOW		=	\e[033m
BLUE		=	\e[34m
WHITE		=	\e[00m

#printing
LOG   		:= printf "[$(BLUE)LIBFT_INFO$(RESET)] %s\n"

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

#directories
OBJPATH =		temps
SRC_PATH =		original_functions
BONUS_PATH =	bonus_functions
MORE_PATH =		more_functions
GNL_PATH =		getnextline
PRINTF_PATH =	printf

#libft source files original
SRC_FILES = 	ft_atoi.c						\
				ft_bzero.c						\
				ft_calloc.c						\
				ft_isalnum.c					\
				ft_isalpha.c					\
				ft_isascii.c					\
				ft_isdigit.c					\
				ft_isprint.c					\
				ft_itoa.c						\
				ft_memchr.c						\
				ft_memcmp.c						\
				ft_memcpy.c						\
				ft_memmove.c					\
				ft_memset.c						\
				ft_putchar_fd.c					\
				ft_putendl_fd.c					\
				ft_putnbr_fd.c					\
				ft_putstr_fd.c					\
				ft_split.c						\
				ft_strchr.c						\
				ft_strdup.c						\
				ft_striteri.c					\
				ft_strjoin.c					\
				ft_strlcat.c					\
				ft_strlcpy.c					\
				ft_strlen.c						\
				ft_strmapi.c					\
				ft_strncmp.c					\
				ft_strnstr.c					\
				ft_strrchr.c					\
				ft_strtrim.c					\
				ft_substr.c						\
				ft_tolower.c					\
				ft_toupper.c					\

#source files bonus
BONUS_FILES =	ft_lstadd_back.c				\
				ft_lstadd_front.c				\
				ft_lstlast.c					\
				ft_lstnew.c						\
				ft_lstsize.c					\

#source files MORE functions
MORE_FILES =	ft_hex_itoa.c					\
				ft_pointer_itoa.c				\
				ft_uitoa.c						\
				ft_strlen_char.c				\
				ft_printf_array.c				\
				ft_strtrim_mod.c				\
				ft_free_array.c					\
				ft_free_int_array.c				\
				ft_free_int.c					\
				ft_atoi_mod.c					\
				ft_strisdigit.c					\
				ft_strjoin_free.c				\
				ft_strtrim_whitespaces.c		\

#source files gnl
GNL_FILES =	get_next_line.c						\
			get_next_line_utils.c				\

#source files ft_printf
PRINTF_FILES =	ft_printf.c						\
				auxiliar_functions.c			\
				auxiliar_functions_more.c		\

################################################################################
##                                 COMPILATION                                ##
################################################################################

#header to libft.h
INCLUDE = -I ./

#tranform into .o
OBJ =			$(SRC_FILES:%.c=$(OBJPATH)/%.o)
OBJ_BONUS =		$(BONUS_FILES:%.c=$(OBJPATH)/%.o)
OBJ_MORE =		$(MORE_FILES:%.c=$(OBJPATH)/%.o)
OBJ_GNL =		$(GNL_FILES:%.c=$(OBJPATH)/%.o)
OBJ_PRINTF =	$(PRINTF_FILES:%.c=$(OBJPATH)/%.o)

#for compliling
FLAGS = -Wall -Wextra -Werror -g3

GDB = gdb
VAL = valgrind --trace-children=yes --leak-check=full --track-origins=yes ./$(NAME)

#remove
RM = rm -f
RM_DIR = rm -Rf

#compiling bar
NUMBER_OF_FILES	=	$(words $(SRC_FILES))
PROGRESS			=	0

################################################################################
##                                    RULES                                   ##
################################################################################

#make libft.a
all: $(OBJPATH) $(NAME)

##make folder for temps
$(OBJPATH):
		@mkdir -p $(OBJPATH)

##compile libft
$(OBJPATH)/%.o: $(SRC_PATH)/%.c $(HEADER)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)
		@echo -n "$(YELLOW)Compiling $(NAME) $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_FILES)))%\r"
		$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

##compile bonus
$(OBJPATH)/%.o: $(BONUS_PATH)/%.c $(HEADER)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)

##compile MORE functions
$(OBJPATH)/%.o: $(MORE_PATH)/%.c $(HEADER)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)

##compile gnl
$(OBJPATH)/%.o: $(GNL_PATH)/%.c $(HEADER)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)

##compile ft_printf
$(OBJPATH)/%.o: $(PRINTF_PATH)/%.c $(HEADER)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)

##rule name - make library
$(NAME): $(OBJ) $(OBJ_GNL) $(OBJ_PRINTF) $(OBJ_MORE) $(OBJ_BONUS)
		@ar -rcs $(NAME) $(OBJ) $(OBJ_GNL) $(OBJ_PRINTF) $(OBJ_MORE) $(OBJ_BONUS)
		@$(LOG) "Libft created!"

#tester
main:
		@cc $(FLAGS) main.c $(NAME) && clear && ./a.out

#remove objects
clean:
		@$(RM) $(OBJ) $(OBJ_GNL) $(OBJ_PRINTF) $(OBJ_MORE) $(OBJ_BONUS)

#remove all
fclean: clean
		@$(RM) $(NAME) $(RM_DIR) $(OBJPATH)
		@$(LOG) "All files from Libft cleaned!"

#clear all
re:		fclean all
		@$(LOG) "Recompiled!"

#avoids double inclusion
.PHONY: all clean fclean re
