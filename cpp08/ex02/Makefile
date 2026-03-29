# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/29 10:31:00 by abetemps          #+#    #+#              #
#    Updated: 2026/03/21 17:02:29 by abetemps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL SETTINGS ====================================================================
NAME = mutantStack

# DIRECTORIES==========================================================================
DIR_SRC		= sources/
DIR_INC 	= includes/
DIR_TMPL 	= templates/
DIR_BUILD	= .build/

# FLAGS & COMPILATOR SETTINGS =========================================================
CXX			= c++
DEPS_FLAGS  = -MD -MP
WARN_FLAGS	= -Wall -Werror -Wextra -g3
CXX_FLAGS	= $(WARN_FLAGS) $(DEPS_FLAGS) -std=c++98
INC_FLAGS 	= -I$(DIR_INC) -I$(DIR_TMPL)

COMP 		= $(CXX) $(CXX_FLAGS) $(INC_FLAGS)

ANTI_RELINK	= Makefile $(DIR_INC) $(DIR_TMPL)

# FILES ===============================================================================
F_MAIN		:=	main.cpp

# VARS GENERATION =====================================================================
OBJS := $(DIR_BUILD)main.o

DEPS :=	$(DIR_BUILD)main.d

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
