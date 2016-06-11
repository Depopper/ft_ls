NAME = ft_ls

SRC = main.c init_infos.c get_infos.c fill_flags.c fill_files.c \
			lst_add_arg.c lst_add_file.c lst_push_file.c lst_push_arg.c \
			free_memory.c sort.c render_files.c count.c \
			print_infos.c get_file_infos.c fill_dir.c qsort.c

FLAGS = -Wextra -Wall -Werror  -Iincludes -Ilibft/includes

OBJ_DIR = objs
SRC_DIR = src

VPATH = $(SRC_DIR)

OBJS = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@gcc  $(OBJS) $(FLAGS) -Llibft -lft -o $(NAME)
	@echo "ft_ls built !"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make -C libft clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean all
	@make -C libft re
