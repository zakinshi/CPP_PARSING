NAME		= PARSING

CC			= c++
FLAGS		= -Wall -Wextra -Werror
CPP-VER		= -std=c++98

REMOVE		= @rm -rf

CP_FILES	= DateParsser.cpp LineParsser.cpp ValueParser.cpp main.cpp
OBJ_FILES	= $(CP_FILES:.cpp=.o)

HEADERS		= DateParsser.hpp LineParsser.hpp ValueParser.hpp

all	: $(NAME)

$(NAME) : $(OBJ_FILES) $(HEADERS)
	$(CC) $(OBJ_FILES) -o $(NAME)

%.o : %.cpp $(HEADERS)
	$(CC) $(FLAGS) $(CPP-VER) -c $< -o $@

clean :
	$(REMOVE) $(OBJ_FILES)

fclean : clean
	$(REMOVE) $(NAME)

re : fclean all

rec : all clean