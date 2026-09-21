NAME		= dungeons

# Folders
SRC_DIR		= src
INC_DIR		= headers
TMP_DIR		= .tmp

# Sources
include Sources.mk
SRC			= $(SRC_MAIN)
OBJS		= $(patsubst %.cpp, $(TMP_DIR)/%.o, $(SRC))
DEPS		= $(OBJS:.o=.d)

# Compiler
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++17 -O3 -MMD -MP \
			  -I $(INC_DIR) -I $(SRC_DIR)
LDFLAGS		= -ldl -pthread -lm

# Colors
GREEN		= \033[1;38;2;0;255;0m
RED			= \033[1;38;2;255;0;0m
DEF_COLOR	= \033[0m

# Rules

all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME) \
		&& printf "%b\n" "$(GREEN)Compilation successful !$(DEF_COLOR)" \
		|| (printf "%b\n" "$(RED)Error during linking!$(DEF_COLOR)" && exit 1)

$(TMP_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@ \
		|| (printf "%b\n" "$(RED)Error compiling $<!$(DEF_COLOR)" && exit 1)

-include $(DEPS)

clean:
	@rm -rf $(TMP_DIR)
	@printf "%b\n" "$(GREEN)Clean successful !$(DEF_COLOR)"

fclean: clean
	@rm -f $(NAME)
	@printf "%b\n" "$(GREEN)Full clean successful !$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
