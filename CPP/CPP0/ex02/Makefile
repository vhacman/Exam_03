NAME		= ACCOUNT
CXX			= c++
CXX_FLAGS	= -Wall -Wextra -Werror -std=c++98

CXX_FILES	= Account.cpp tests.cpp
OBJS		= $(CXX_FILES:.o=.cpp)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

%.o: %.cpp Account.hpp
	$(CXX) $(CXX_FLAGS) $< -c $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: clean fclean

.PHONY: all clean fclean re
