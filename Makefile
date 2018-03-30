# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/14 18:04:02 by tferrari          #+#    #+#              #
#    Updated: 2018/03/30 11:33:19 by tferrari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = computerv1

SRC_DIR = src

SRC_FILE =	main.cpp computerv1.cpp sqrt.cpp lib.cpp

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJS_DIR = obj

OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_FILE:.cpp=.o))

INC = -Iinclude

FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJS)
	@g++ -o $(NAME) $(OBJS)
	@echo "\033[32mexecutable computerv1 créé\033[0m"

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJS_DIR)
	@g++ $(INC) -o $@ -c $<
	@echo "Fichier" $< "recompilé."

clean:
	@rm -rf $(OBJS_DIR)
	@echo "\033[31mFichier objet de computerv1 supprimé\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[31mcomputerv1 supprimé\033[0m"

re: fclean all
