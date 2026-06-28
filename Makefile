CC = cc

CFLAGS = -Wall -Wextra -Werror -std=c11 -g

SOURCES = my_tools.c             \
          my_ls.c                \
          my_tools_directory.c   \
          my_tools_arguments.c   \
          my_options_refractor.c \
          my_display_tools.c     \
          my_tools_sort.c

HEADERS = my_tools.h             \
          my_ls.h                \
          my_tools_directory.h   \
          my_tools_arguments.h   \
          my_options_refractor.h \
          my_display_tools.h     \
          my_tools_sort.h

OBJ = $(SOURCES:.c=.o)

OUTPUT = my_ls

all: $(OUTPUT)

$(OUTPUT): $(OBJ)
	$(CC) $(CFLAGS) -o $(OUTPUT) $(OBJ)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(OUTPUT)

re: fclean all

.PHONY: all clean fclean re
