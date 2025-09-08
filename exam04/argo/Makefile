# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igilani <igilani@student.42firenze.it>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/08 19:12:30 by igilani           #+#    #+#              #
#    Updated: 2025/06/09 19:08:47 by igilani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile migliorato — correzioni per targhetta `clean` che non funzionava
.DEFAULT_GOAL := silent

# Configurazioni principali
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g
NAME    = argo
SRC     = main.c argo.c given_code.c
OBJ_DIR = obj
OBJ     = $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))
BUILD   = 0

# Variabili opzionali per evitare avvisi
HEADERS ?=
THA_LIB ?=

# Colori ANSI
RED     = \033[31m
ERROR   = $$(RED)✗
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
RESET   = \033[0m

all: $(NAME)
	@if [ $(BUILD) -eq 1 ]; then \
		echo "$(GREEN)✔ Build completato$(RESET)"; \
	else \
		echo "$(GREEN)✔ Già tutto compilato$(RESET)"; \
	fi

$(OBJ_DIR)/%.o: %.c $(HEADERS) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ || { \
		echo "$(ERROR) Errore nella compilazione di $<$(RESET)"; \
		exit 1; \
	}

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(THA_LIB)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) || { \
		echo "$(ERROR) Errore durante il linking finale$(RESET)"; \
		exit 1; \
	}
	@$(eval BUILD = 1)
	@echo "$(BLUE)➜ Creazione eseguibile $(NAME)...$(RESET)"
	@echo "$(GREEN)✔ Eseguibile $(NAME) generato$(RESET)"

# --- Clean/fclean corretti (rimosse chiamate ricorsive a make) ---
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(BLUE)➜ Directory oggetto $(YELLOW)$(OBJ_DIR)$(RESET) $(BLUE)rimossa$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(BLUE)➜ Eseguibile $(YELLOW)$(NAME)$(RESET) $(BLUE)rimosso$(RESET)"

re: fclean all

silent:
	@$(MAKE) all 2>&1 | grep -v '^make\[.*\]:'

.PHONY: all clean fclean re silent

