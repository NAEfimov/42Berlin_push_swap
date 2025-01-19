NAME        := push_swap

#------------------------------------------------#
#   INGREDIENTS                                  #
#------------------------------------------------#
# LIBS			libraries to be used
# LIBS_TARGET	libraries to be built
#
# INCS			header file locations
#
# SRCS			source files
#
# OBJS			object files
# DEPS			dependency files
#
# CC			compiler
# CFLAGS		compiler flags
# CPPFLAGS		preprocessor flags
# IFLAGS		Include flags
# LDFLAGS		linker flags
# LDLIBS		libraries name

LIBS        := ft
LIBS_TARGET := libft/libft.a

INCS        := . libft

SRCS		:=		\
	main.c			\
	read_lst.c		\
	print_lst.c		\
	utils_lst.c		\
	sort_opr_r.c	\
	sort_opr_sp.c	\
	sort_utl.c		\
	sort_lst.c		\
	cmd_lst.c		\
	sort_three.c	\
	div_lst_a.c		\
	div_lst_b.c		\
	div_lst_init.c

OBJS		:= $(SRCS:%.c=%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP
IFLAGS		:= $(addprefix -I,$(INCS))
LDFLAGS     := $(addprefix -L,$(dir $(LIBS_TARGET)))
LDLIBS      := $(addprefix -l,$(LIBS))

#------------------------------------------------#
#   UTENSILS                                     #
#------------------------------------------------#
# RM		force remove
# MAKEFLAGS	make flags

RM			= rm -f
MAKEFLAGS	+= --no-print-directory

#------------------------------------------------#
#   RECIPES                                      #
#------------------------------------------------#
# all		default goal
# $(NAME)	link .o -> library
# %.o		compilation .c -> .o
# clean		remove .o
# fclean	remove .o + binary
# re		remake default goal

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(IFLAGS) -o $@ $(OBJS) $(LDLIBS)
	$(info CREATED $(NAME))

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(IFLAGS) -c -o $@ $< $(LDLIBS)
	$(info CREATED $@)

-include $(DEPS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)
fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all
