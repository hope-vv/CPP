NAME = form

CXX = c++ #-fsanitize=address -g3
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		sources/Bureaucrat.cpp sources/Form.cpp \

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
