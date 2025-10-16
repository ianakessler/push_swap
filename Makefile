# --- NOME DO EXECUTÁVEL ---
NAME = push_swap

# --- COMPILADOR E FLAGS ---
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

# --- CAMINHOS E ARQUIVOS ---
# Lista de arquivos fonte .c do seu projeto
SRCS =	push_swap.c\
		params_validator.c\
		create_node.c\
		add_node_front.c\
		fill_stack.c\
		free_stack.c\
		stack_utils.c\
		rotate.c\

# Correção 1: Removido o espaço na conversão de .c para .o
OBJS = $(SRCS:.c=.o)

# Caminho e nome do arquivo da libft
LIBFT_PATH = ./libft
LIBFT_A = $(LIBFT_PATH)/libft.a

# Onde procurar por arquivos de cabeçalho (.h)
INCLUDES = -I$(LIBFT_PATH)

# --- REGRAS ---
.PHONY: all clean fclean re

all: $(NAME)

# Correção 2: Corrigida a linha de ligação para incluir os objetos e usar as variáveis corretas
$(NAME): $(OBJS) $(LIBFT_A)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) -o $(NAME)
	@echo "✅ push_swap compilado com sucesso!"

# Correção 3: A única responsabilidade desta regra é compilar a libft
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_PATH)

# Correção 4: Adicionada a regra que faltava para compilar os .c do push_swap em .o
%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@$(RM) $(NAME)

re: fclean all
