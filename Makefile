# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pokpalae <pokpalae@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/17 16:07:24 by pokpalae          #+#    #+#              #
#    Updated: 2024/04/22 11:31:47 by pokpalae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME				= client
SVR					= server
CLNBN				= client_bonus
SVRBN				= server_bonus

LIBFT				= ./libft/libft.a
INC					= includes/
SRC_DIR				= src/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

SRCCL 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(NAME)))
SRCSV 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVR)))
SRCCLB 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(CLNBN)))
SRCSVB 				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SVRBN)))

OBJCL 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(NAME)))
OBJSV 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVR)))
OBJCLB				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(CLNBN)))
OBJSVB 				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SVRBN)))

start:				
					@make all
					@make bonus

$(LIBFT):
					@make -C ./libft

all:				$(NAME) $(SVR)		

$(NAME):			$(OBJCL) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJCL) $(LIBFT) -o $(NAME)

$(SVR):				$(OBJSV) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJSV) $(LIBFT) -o $(SVR)
					
bonus:				$(CLNBN) $(SVRBN)

$(CLNBN):			$(OBJCLB) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJCLB) $(LIBFT) -o $(CLNBN)

$(SVRBN):			$(OBJSVB) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJSVB) $(LIBFT) -o $(SVRBN)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft
			
fclean:				clean
					@$(RM) $(NAME) $(SVR) $(CLNBN) $(SVRBN)
					@$(RM) $(LIBFT)

re:					fclean all

.PHONY:				start all clean fclean re bonus