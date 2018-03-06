NAME	= arcade

CC	= g++

RM	= rm -f

SRCS	= ./src/main.cpp \
	  ./src/core/core.cpp

OBJS	= $(SRCS:.cpp=.o)


LDFLAGS = -ldl
CPPFLAGS = -I./interfaces -I./templates
CPPFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
