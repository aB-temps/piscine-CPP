# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/25 19:29:03 by abetemps          #+#    #+#              #
#    Updated: 2025/09/27 23:10:42 by abetemps         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# GENERAL SETTINGS ====================================================================
NAME = phonebook
.SILENT:

# DIRECTORIES==========================================================================
DIR_SRC		:= sources/
DIR_INC 	:= includes/
DIR_BUILD	:= .build/

# FLAGS & COMPILATOR SETTINGS =========================================================
CXX			:= c++
DEPS_FLAGS  := -MMD -MP
WARN_FLAGS	:= -Wall -Werror -Wextra 
CXX_FLAGS	:= $(WARN_FLAGS) $(DEPS_FLAGS) -std=c++98
INC_FLAGS 	:= -I$(DIR_INC)h/ -I$(DIR_INC)hpp/

COMP 		:= $(CXX) $(CXX_FLAGS) $(INC_FLAGS)

ANTI_RELINK	:= Makefile $(DIR_INC) 

# FUNCTIONS ===========================================================================
define generate_var_sources_dir
DIR_$(1) = $(addprefix $(DIR_SRC), $(shell echo $(1) | tr '[:upper:]' '[:lower:]')/)
endef

define generate_var_sources
SRC_$(1) = $(addprefix $(DIR_$(1)),$(F_$(1)))
endef

define generate_var_objects
OBJS_$(1) = $(patsubst $(DIR_SRC)%.cpp,$(DIR_BUILD)%.o,$(SRC_$(1)))
endef

define generate_var_deps
DEPS_$(1) = $(patsubst $(DIR_SRC)%.cpp,$(DIR_BUILD)%.d,$(SRC_$(1)))
endef

# COMPONENTS ==========================================================================
COMPONENTS :=	CLASSES		\
				UTILS		\

# FILES ===============================================================================
F_MAIN		:=	main.cpp

F_CLASSES	:=	Contact.cpp				\
				PhoneBook.cpp			\

F_UTILS		:=	ask_confirmation.cpp	\
				str_is.cpp				\

# VARS GENERATION =====================================================================
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_sources_dir,$(comp))))
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_sources,$(comp))))
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_objects,$(comp))))
$(foreach comp,$(COMPONENTS),$(eval $(call generate_var_deps,$(comp))))

OBJS := $(foreach comp, $(COMPONENTS), $(OBJS_$(comp))) \
		$(DIR_BUILD)main.o

DEPS := $(foreach comp, $(COMPONENTS), $(DEPS_$(comp))) \
		$(DIR_BUILD)main.d

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
