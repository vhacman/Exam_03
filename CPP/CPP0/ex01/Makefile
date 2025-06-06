NAME		= My_Awesome_PhoneBook

CXX			= c++
CXX_FLAGS	= -Wall -Wextra -Werror -std=c++98

CXX_DIR		= src/
HPP_DIR		= includes

CXX_FILES	= Contact.cpp PhoneBook.cpp main.cpp addContact.cpp searchContact.cpp
SRCS		= $(addprefix $(CXX_DIR), $(CXX_FILES))
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXX_FLAGS) $^ -o $@

%.o:%.cpp $(HPP_DIR)/*
	$(CXX) $(CXX_FLAGS) -c $< -o $@

clean:
	rm -rf $(CXX_DIR)/*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
