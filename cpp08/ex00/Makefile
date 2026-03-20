# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 10:31:00 by abetemps          #+#    #+#              #
#    Updated: 2026/03/17 16:56:59 by abetemps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL SETTINGS ====================================================================
NAME = easyfind

# DIRECTORIES==========================================================================
DIR_SRC		:= sources/
DIR_INC 	:= includes/
DIR_TEMPL 	:= templates/
DIR_BUILD	:= .build/

# FLAGS & COMPILATOR SETTINGS =========================================================
CXX			:= c++
DEPS_FLAGS  := -MD -MP
WARN_FLAGS	:= -Wall -Werror -Wextra -Wshadow -g3
CXX_FLAGS	:= $(WARN_FLAGS) $(DEPS_FLAGS) -std=c++98
INC_FLAGS 	:= -I$(DIR_TEMPL) -I$(DIR_INC)

COMP 		:= $(CXX) $(CXX_FLAGS) $(INC_FLAGS)

ANTI_RELINK	:= Makefile $(DIR_TEMPL) $(DIR_INC)

# FILES ===============================================================================
F_MAIN		:=	main.cpp


# VARS GENERATION =====================================================================
OBJS := $(DIR_BUILD)main.o

DEPS := $(DIR_BUILD)main.d

# COMPILATION =========================================================================
$(NAME) : $(OBJS)
	$(COMP) $^ -o $@ 
	@echo ✨ $(NAME) compiled ✨

$(DIR_BUILD) :
	@mkdir -p $(DIR_BUILD)

$(DIR_BUILD)%.o : $(DIR_SRC)%.cpp $(ANTI_RELINK) | $(DIR_BUILD)
	@mkdir -p $(dir $@)
	$(COMP) -c $< -o $@

-include $(DEPS)

# RULES ===============================================================================
# build -------------------------------------------------------------------------------
all : $(NAME)

# clean -------------------------------------------------------------------------------
clean:
	@rm -rf $(DIR_BUILD)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.DEFAULT_GOAL = all

# debug -------------------------------------------------------------------------------
print-%:
	@echo $($(patsubst print-%,%,$@))

.PHONY: all clean fclean re print-%
