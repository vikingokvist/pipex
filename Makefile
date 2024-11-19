#NAMES-----------------------------------------------------------------

NAME = pipex
NAME_BONUS = pipex_bonus

#FLAGS------------------------------------------------------------------

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NO_PRINT = --no-print-directory

#LIBFT-DIR--------------------------------------------------------------

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#FILES------------------------------------------------------------------

SRCS_SRC = src/main.c src/init_process.c src/error.c \
	src/get_commands.c src/forks.c \

SRCS_BONUS = bonus/main_bonus.c bonus/init_process_bonus.c \
	bonus/error_bonus.c bonus/get_commands_bonus.c bonus/forks_bonus.c \
	bonus/init_struct_bonus.c

OBJS_SRC = $(SRCS_SRC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#COLOURS----------------------------------------------------------------

ORANGE = \033[38;5;214m
GREEN = \033[38;5;82m
RESET = \033[0m

#PIPEX COMPILATION-------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS_SRC) $(LIBFT)
	@echo "$(ORANGE)Linking...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS_SRC) $(LIBFT)
	@echo "$(GREEN)Executable built: $(NAME)$(RESET)"

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT)
	@echo "$(ORANGE)Linking...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT)
	@echo "$(GREEN)Executable built: $(NAME_BONUS)$(RESET)"

%.o: %.c
	@echo "$(ORANGE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJS_SRC)
	@$(RM) $(OBJS_BONUS)
	@echo "$(GREEN)All object files removed.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo "$(GREEN)Executable removed.$(RESET)"

re: fclean all

#LIBFT COMPILATION-----------------------------------------------------

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