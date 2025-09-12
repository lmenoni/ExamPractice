# **************************************************************************** #
#                                    Makefile                                  #
# **************************************************************************** #

# Nome dell'eseguibile
NAME = polyset

# Compilatore e flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -g

# Sorgenti
SRC = main.cpp array_bag.cpp tree_bag.cpp searchable_array_bag.cpp searchable_tree_bag.cpp set.cpp

# Regola di default
all: $(NAME)

# Link e compilazione
$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)

# Pulizia (opzionale, qui non ci sono oggetti ma utile se ne aggiungi)
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re