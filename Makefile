PUSH_SWAP_LIB_NAME	:= push_swap.a
PUSH_SWAP_LIB_DIRS	:= . bench errors helpers utils
PUSH_SWAP_LIB_SRCS	:= $(foreach dir,$(PUSH_SWAP_LIB_DIRS),$(wildcard $(dir)/*.c))
OBJ_DIR := build
PUSH_SWAP_LIB_OBJS := $(addprefix $(OBJ_DIR)/,$(PUSH_SWAP_LIB_SRCS:.c=.o))
CC					:= cc
CFLAGS				:= # -Wall -Wextra -Werror
CINCLUDES			:= -I ./includes
CMD_AR_RCS_FLAG 	:= ar rcs
CMD_RM_F_FLAG		:= rm -f


$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo "Compiling -> $< ..."
	@$(CC) $(CFLAGS) $(CINCLUDES) -c $< -o $@

$(PUSH_SWAP_LIB_NAME): $(PUSH_SWAP_LIB_OBJS)
	@echo "Executing command -> ar rcs $(PUSH_SWAP_LIB_NAME) $(PUSH_SWAP_LIB_OBJS)"
	@$(CMD_AR_RCS_FLAG) $(PUSH_SWAP_LIB_NAME) $(PUSH_SWAP_LIB_OBJS)

all: $(PUSH_SWAP_LIB_NAME)

clean:
	@echo "Doing Clean ..."
	@$(CMD_RM_F_FLAG) $(PUSH_SWAP_LIB_OBJS)

fclean: clean
	@echo "Doing fclean ..."
	@$(CMD_RM_F_FLAG) $(PUSH_SWAP_LIB_NAME) $(PUSH_SWAP_LIB_OBJS)

re: fclean all

.PHONY: all clean fclean re