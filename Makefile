
NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NO_PRINT = --no-print-directory

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS_SRC = src/main.c src/init_process.c src/error.c src/get_commands.c \
	src/forks.c

OBJS_SRC = $(SRCS_SRC:.c=.o)

#----------------------------------------------------------------------
#				PIPEX
#----------------------------------------------------------------------
all: $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT)
	@echo "$(ORANGE)Linking...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_SRC) $(LIBFT)
	@echo "$(GREEN)Executable built: $(NAME)$(RESET)"

%.o: %.c
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_SRC)
	@echo "$(GREEN)All object files removed.$(RESET)"

fclean: clean
	$(RM) $(NAME)

re: fclean all
#----------------------------------------------------------------------
#				LIBFT
#----------------------------------------------------------------------
libft: $(LIBFT)

$(LIBFT):
	@echo "$(ORANGE)Building libft...$(RESET)"
	@make $(NO_PRINT) -C $(LIBFT_DIR)
	@echo "$(GREEN)Executable built: libft.a$(RESET)"

clean_libft:
	@make $(NO_PRINT) -C $(LIBFT_DIR) clean
	@echo "$(GREEN)Libft cleaned.$(RESET)"

fclean_libft:
	@make $(NO_PRINT) -C $(LIBFT_DIR) fclean
	@echo "$(GREEN)libft.a executable removed.$(RESET)"

#----------------------------------------------------------------------
.PHONY: all clean fclean re