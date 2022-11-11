

NAME = fdf

MLX = minilibx_macos/libmlx.a 

SRC = src/fdf.c src/parse.c src/design.c \
	  src/utils/ft_atoi.c \
	  src/utils/ft_strdup.c \
	  src/utils/ft_strlen.c \
	  src/utils/ft_split.c \
	  src/utils/word_counter.c \
	  src/utils/ft_substr.c \
	  src/utils/get_next_line.c \
	  src/utils/get_next_line_utils.c \
	  src/utils/utils.c

CC = gcc 

all	:	$(NAME)

$(MLX) :
	@make -C minilibx_macos/  
	@make clean -C minilibx_macos/

$(NAME) :	$(SRC) $(MLX)
	$(CC) -o $(NAME) $(SRC) -Iincludes $(MLX) -framework OpenGL -framework AppKit 

clean : 
	rm fdf
	
re : clean all
