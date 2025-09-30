# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/21 14:30:24 by abetemps          #+#    #+#              #
#    Updated: 2025/09/21 14:31:36 by abetemps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL SETTINGS ====================================================================
NAME = megaphone
.SILENT:

# DIRECTORIES==========================================================================
DIR_SRC		:= source/
DIR_BUILD	:= .build/

# FLAGS & COMPILATOR SETTINGS =========================================================
CXX			:= c++
WARN_FLAGS	:= -Wall -Werror -Wextra 
CXX_FLAGS	:= $(WARN_FLAGS) -std=c++98

COMP 		:= $(CXX) $(CXX_FLAGS)

ANTI_RELINK	:= Makefile

# FILES ===============================================================================
F_MAIN 		:=	megaphone.cpp

OBJS 		:= $(DIR_BUILD)megaphone.o

# COMPILATION =========================================================================
$(NAME) : $(OBJS)
	$(COMP) $^ -o $@ 
	@echo ✨ $(NAME) compiled ✨

$(DIR_BUILD) :
	@mkdir -p $(DIR_BUILD)

$(DIR_BUILD)%.o : $(DIR_SRC)%.cpp $(ANTI_RELINK) | $(DIR_BUILD)
	@mkdir -p $(dir $@)
	$(COMP) -c $< -o $@

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
