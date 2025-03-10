NAME 				= 			fract-ol

LIBFT				=			includes/libft/libft.a

HEAD 				=			fract-ol.h

OBJ_DIR				=			obj/

CC					=			cc

CFLAGS				=		-Wall -Werror -MMD -MP -g3

SRCS				=			$(addprefix $(SRCS_DIR), $(SRC_ACC))

SRCS_DIR			=			srcs/

MAIN_SRCS			=			main

SRC_ACC				+=			$(addsuffix .c, $(MAIN_SRCS))


OBJ			=			$(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

DEP			=			$(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)%.d,$(SRCS))

MLX			:=	libmlx.a

MLX_D		:=	includes/minilibx-linux/

MLX_F		:=	-L$(MLX_D) -lmlx -lXext -lX11 -lm -lz

MLX_H		:=	$(MLX_D)mlx.h

MLX_A		:=	$(addprefix $(MLX_D), $(MLX))

all:					$(NAME)

$(NAME):				$(OBJ) $(LIBFT) $(MLX)
							$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_F) -o $@

$(OBJ_DIR)%.o: $(SRCS_DIR)%.c Makefile
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@

$(MLX): FORCE
	@$(MAKE) -C $(MLX_D)

$(LIBFT): FORCE
	$(MAKE) -C includes/libft

clean:
						make clean -C includes/libft
						@rm -rf $(OBJ_DIR)
						@rm -rf $(MLX_D)obj
						@echo "Deleting $(OBJ_DIR)"


fclean:					clean
							make fclean -C includes/libft
							make clean -C $(MLX_D)
							@rm -rf $(NAME)
							@echo "Deleting $(NAME)"


re: 					fclean
						$(MAKE) all

FORCE:

.PHONY: 				re all clean fclean FORCE

-include $(DEP)
