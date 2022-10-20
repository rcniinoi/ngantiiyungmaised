# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/01 15:09:02 by rchiewli          #+#    #+#              #
#    Updated: 2022/10/19 17:19:49 by rchiewli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
CFLAGS	= -Wall -Wextra -Werror
CC		= gcc
FILES	= pswmain.c \
			quicksort.c\
			./instruc/core_ins.c\
			./instruc/core_ins2.c\
			./instruc/pswinst1.c\
			./instruc/pswinst2.c\
			./instruc/pswinst3.c\
			./solve/pswsolve.c\
			./pushutil/pswlstmanager.c\
			./pushutil/pswlstmanager2.c\
			./pushutil/util1.c\
			./pushutil/util2.c\
			./errorhandlor/errorhand1.c\
			./dt_dpf/util.c \
			./dt_dpf/ft_printf.c \
			./dt_dpf/libftmodified.c\

# MLX_FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit


OBJ	= $(FILES:%.c=%.o)

all:  $(NAME)

# ft_pf:
# 	@make -C ft_pf/

$(NAME): $(OBJ)
	# @say -v kyoko こんにちは マクドナルド ミルク バス ビール スターバックス
	@make -C dt_dpf/
	@make -C libftfinal/
	$(CC) $(CFLAGS) $(OBJ) dt_dpf/libftprintf.a libftfinal/libft.a -o $(NAME)

debug:
	@make -C dt_dpf/
	@make -C libftfinal/
	$(CC) -g $(CFLAGS) $(FILES) dt_dpf/libftprintf.a libftfinal/libft.a -o debug


love:
	@printf "No one to \e[1;31m make love \e[0m with you."

cheer:
	@say -v kanya หนึ่ง สอง /
	@say -v kanya หนึ่งสองสาม /
	@say -v kanya หนึ่งสอง /
	@say -v kanya หนึ่งสอง /
	@say -v kanya หนึ่ง /

badvoice:
	@say -v kanya ยายมอยเลี้ยงหมี และยายมีเลี้ยงหอย/
	@say -v kanya ส่วนนางลีขายหอย และนางมอยขายหมี/
	@say -v kanya ยานัตถุ์ของหมอมีแก้ฝีแก้หิด แต่การแพทย์ของหมอชิดแก้หิดแก้ฝี/
	@say -v kanya เอาหูหมีมาใส่ในหูหมู หนูเอาหูหมูมาใส่หูหมี หูหมู หูหนี เอาหูหมีมาใส่หูหมู/
	@say -v kanya แต่ถ้าเธอเอาไปผัดเห็ดมันจะเป็นเห็ดหูหนู/

norm:
	@say -v kanya เช็คนอม หน่อยนะค่ะ /
	norminette -R checkforbiddensourceheader $(FILES)
	norminette -R checkdefine pushswap.h

clean:
	# @say -v kanya อาบฟอกตัว ขัดทั่วกาย งามพริ้งพรายง่ายดายเหลือใจ /
	@rm -f $(OBJ)
	@make clean -C dt_dpf/
	@make clean -C libftfinal/
	@rm -rf debug

fclean: clean
	@rm -f $(NAME)
	@make fclean -C dt_dpf/

re: fclean all

re2: clean debug

.PHONY: clean fclean all re norm love cheer badvoice
