NAME        := push_swap
BONUS		:= checker

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

SRCS		:=			\
	main.c				\
	ps_read_lst.c		\
	ps_print_lst.c		\
	ps_utils_lst.c		\
	ps_sort_opr_r.c		\
	ps_sort_opr_rr.c	\
	ps_sort_opr_sp.c	\
	ps_sort_utl.c		\
	ps_sort_lst.c		\
	ps_cmd_lst.c		\
	ps_sort_three.c		\
	ps_div_lst_a.c		\
	ps_div_lst_b.c		\
	ps_div_lst_init.c

SRCS_BONUS	:=			\
	_bonus_checker.c	\
	_bonus_str.c		\
	_bonus_opr.c		\
	ps_read_lst.c		\
	ps_print_lst.c		\
	ps_utils_lst.c		\
	ps_sort_opr_r.c		\
	ps_sort_opr_rr.c	\
	ps_sort_opr_sp.c	\
	ps_sort_utl.c		\
	ps_sort_lst.c		\
	ps_cmd_lst.c		\
	ps_sort_three.c		\
	ps_div_lst_a.c		\
	ps_div_lst_b.c		\
	ps_div_lst_init.c

OBJS		:= $(SRCS:%.c=%.o)
OBJS_BONUS	:= $(SRCS_BONUS:%.c=%.o)
DEPS		:= $(OBJS:.o=.d)
DEPS_BONUS	:= $(OBJS_BONUS:.o=.d)

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

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS) $(LIBS_TARGET)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(IFLAGS) -o $@ $(OBJS_BONUS) $(LDLIBS)
	$(info CREATED $(BONUS))

#$(LIBS_TARGET):
#	$(MAKE) -C $(@D)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(IFLAGS) -c -o $@ $< $(LDLIBS)
	$(info CREATED $@)

-include $(DEPS_BONUS)

clean:
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
fclean: clean
	for f in $(dir $(LIBS_TARGET)); do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME) $(BONUS)

re:
	$(MAKE) fclean
	$(MAKE) all
