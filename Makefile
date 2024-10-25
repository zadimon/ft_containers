NAME			=	ft_container

SRC				=	tests/main.cpp\
					tests/stack.cpp\
					tests/vector.cpp\
					tests/map.cpp\
					tests/set.cpp

HDR				=	main.hpp\
					stack.hpp\
					vector.hpp\
					vector_iterator.hpp\
					iterator_traits.hpp\
					is_integral.hpp\
					enable_if.hpp\
					pair.hpp\
					set.hpp\
					red_black_tree.hpp\
					red_black_tree_iterator.hpp\
					map.hpp

OBJ_DIR			=	./objs/
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

FLAGS			=	-Wall -Wextra -Werror -g -std=c++98
CC				=	c++
RM				=	rm -rf

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(HDR) $(OBJ) Makefile
				$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:	%.cpp $(HDR)
				mkdir -p $(dir $@)
				$(CC) $(FLAGS) -o $@ -c $<

clean:
				$(RM) $(OBJ_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all
