#!/bin/bash

# List of folders
folders=("ex00" "ex01" "ex02" "ex03")

# Loop through each folder
for folder in "${folders[@]}"; do
	mkdir -p "$folder/sources"

	# Create main.cpp
	cat > "$folder/main.cpp" << EOF
int main() {
    return 0;
}
EOF

	# Ask for NAME to use in the Makefile
	read -p "Enter NAME for $folder: " name

	# Create Makefile
	cat > "$folder/Makefile" << EOF
NAME = $name

CXX = c++ #-fsanitize=address -g3
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \\
		\$(wildcard sources/*.cpp)

OBJS = \$(SRCS:.cpp=.o)

all: \$(NAME)

\$(NAME): \$(OBJS)
	\$(CXX) \$(CXXFLAGS) -o \$(NAME) \$(OBJS)

%.o: %.cpp
	\$(CXX) \$(CXXFLAGS) -c \$< -o \$@

clean:
	rm -rf \$(OBJS)

fclean: clean
	rm -rf \$(NAME)

re: fclean all

.PHONY: all clean fclean re
EOF

	echo "Created $folder/Makefile and $folder/main.cpp ✅"
done
