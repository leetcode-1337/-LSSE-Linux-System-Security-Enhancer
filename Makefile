
INCLUDES		= -Iinclude
OBJ_DIR 		= obj
CFLAGS			= -Wall -Wextra -Werror
NAME			= lsse
SRC				= $(shell find src/ -type f -name "*.c")
CC				= gcc
OBJ				= $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS			= $(patsubst %.c, $(OBJ_DIR)/%.d, $(SRC))
DEPSFLAGS		= -MMD -MP
HBLU			= '\e[1;94m'
NC				= '\e[0m'

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o : %.c include/ 
	mkdir -p $(dir $@)
	printf $(HBLU)"[%-37s] 🕝 \r"$(NC) "Compiling $(notdir $@)"
	$(CC) $(CFLAGS) $(DEPSFLAGS) ${INCLUDES} -c $< -o $@

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean all  bonus

-include : $(DEPS)

.SILENT : $(NAME) clean fclean all ${OBJ}