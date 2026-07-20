LIB_NAME			:= push_swap.a
LIB_DIRS			:= . bench disorder errors helpers stack strategies utils
LIB_SRCS			:= $(foreach dir,$(LIB_DIRS),$(wildcard $(dir)/*.c))
LIB_OBJS_DIR		:= build
LIB_OBJS_FILES		:= $(addprefix $(LIB_OBJS_DIR)/,$(LIB_SRCS:.c=.o))
CC					:= cc
CFLAGS				:= # -Wall -Wextra -Werror
CINCLUDES			:= -I ./lib
CMD_RM_FLAGS		:= rm -rf
CMD_AR_FLAGS		:= ar rcs

$(LIB_OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling -> $< ..."
	@$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(LIB_NAME): $(LIB_OBJS_FILES)
	@echo "Executing command -> ar rcs $(LIB_NAME) $(LIB_OBJS_FILES)"
	@$(CMD_AR_FLAGS) $(LIB_NAME) $(LIB_OBJS_FILES)
	@echo ""

all: $(LIB_NAME)

clean:
	@echo "Cleaning ..."
	@if [ -n "$$(find $(LIB_OBJS_DIR) -mindepth 1 -print -quit 2>/dev/null)" ]; then \
		echo "Removing -> $(CMD_RM_FLAGS) $(LIB_OBJS_DIR)/* ..."; \
		$(CMD_RM_FLAGS) $(LIB_OBJS_DIR)/*; \
	fi
	@echo ""

fclean: clean
	@echo "Full Cleaning ..."
	@echo "Removing -> $(CMD_RM_FLAGS) $(LIB_NAME) ..."
	@$(CMD_RM_FLAGS) $(LIB_NAME)
	@echo ""

re: fclean all

.PHONY: all clean fclean re