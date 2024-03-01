# The interesting part
NAME = libtf
SRCS = src/
INCLUDES = ./ include/
CODE = \
		mem mem_utils str1 str2 str3 str_stream str_char1 \
		str_char2 str_stream_more str_streamstr print \
		list1 list2 error data read_line read_line_utils
PRINTF_CODE = \
		conversions1 conversions2 do_conversion ft_itoa tf_printf \
		ft_strjoin stream1 stream2 utils1 utils2
PRINTF_SRCS = tf_printf/src/
PRINTF_INCLUDES = ./ tf_printf/include/
WHAT = LIBTF v4.2
USED = malloc() free() write()

# It works and I probably won't change it for the rest of my life
C_FILES = $(addsuffix .c,$(addprefix $(SRCS),$(CODE)))
O_FILES = $(addsuffix .o,$(addprefix $(SRCS),$(CODE)))
PRINTF_C_FILES = $(addsuffix .c,$(addprefix $(PRINTF_SRCS),$(PRINTF_CODE)))
PRINTF_O_FILES = $(addsuffix .o,$(addprefix $(PRINTF_SRCS),$(PRINTF_CODE)))
ifdef DEBUG
	CC = cc -Wall -Wextra -Werror -g
	FINISH_MSG = "\e[7;33m  $(WHAT) compiled! (debug)  \e[0m"
else
	CC = cc -Wall -Wextra -Werror
	FINISH_MSG = "\e[7;36m  $(WHAT) compiled!  \e[0m"
endif
AR = ar rcs

all : $(NAME)
	@echo ""
	@echo $(FINISH_MSG)
	@echo "\e[36mFunctions used: $(USED) \e[0m"
	@echo ""

debug :
	make DEBUG=yes

$(NAME) : $(O_FILES) $(PRINTF_O_FILES)
	$(AR) $(addsuffix .a, $(NAME)) $(O_FILES) $(PRINTF_O_FILES)

$(O_FILES) : %.o : %.c
	$(CC) $(addprefix -I ,$(INCLUDES)) -c $< -o $@

clean :
	rm -f $(O_FILES) $(PRINTF_O_FILES)

fclean : clean
	rm -f $(addsuffix .a, $(NAME))

re : fclean all

printf : $(PRINTF_O_FILES)
	$(AR) $(addsuffix .a, $(NAME)) $(PRINTF_O_FILES)

$(PRINTF_O_FILES) : %.o : %.c
	$(CC) $(addprefix -I ,$(PRINTF_INCLUDES)) -c $< -o $@

.PHONY : all clean fclean re printf
