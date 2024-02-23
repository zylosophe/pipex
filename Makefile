# The interesting part
NAME = pipex
SRCS = src/
INCLUDES = include/ libtf/
CODE = main error1 error2 execsubprocess execcommand execfrompath heredoc
LIBRARIES_DIRS = libtf/
LIBRARIES_FILES = libtf/libtf.a

# It works and I probably won't change it for the rest of my life
C_FILES = $(addsuffix .c,$(addprefix $(SRCS),$(CODE)))
O_FILES = $(addsuffix .o,$(addprefix $(SRCS),$(CODE)))
CC = cc -Wall -Wextra -Werror -g

all : $(NAME)

bonus : all

$(NAME) : $(O_FILES) $(LIBRARIES_FILES)
	$(CC) -o $(NAME) $(O_FILES) $(LIBRARIES_FILES)

$(LIBRARIES_FILES) :
	true $(addprefix && make -C ,$(LIBRARIES_DIRS))

%.o : %.c
	$(CC) $(addprefix -I ,$(INCLUDES)) -c $< -o $@

clean :
	rm -f $(O_FILES)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
