# 20204946 이규성

NAME = a.exe
SRCS = ./srcs/main.cpp ./srcs/student.cpp ./srcs/database.cpp
OBJS = $(SRCS:.cpp=.o)
SRC_DIR = ./srcs
INCLUDE = -I./includes/
HEADER = ./includes/database.h ./includes/student.h
GC = g++ -Wall -Wextra -Werror -std=c++11

all : $(NAME)

$(NAME) : $(OBJS)
	$(GC) -o $@ $^

$(SRC_DIR)/%.o : $(SRC_DIR)/%.cpp $(HEADER)
	$(GC) -o $@ -c $< $(INCLUDE)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

test :
	make all
	./$(NAME)

readme :
	cat README.txt

.PHONY: all clean fclean re test readme
