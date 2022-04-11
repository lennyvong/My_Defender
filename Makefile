##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC = gcc

SRC	=	sources/my_main.c	\
		sources/my_defender.c	\
		sources/menu/home_menu.c	\
		sources/menu/elements/book.c	\
		sources/menu/elements/smoke.c	\
		sources/menu/elements/speaker.c \
		sources/menu/elements/buttons.c	\
		sources/menu/elements/home_text.c	\
		sources/menu/elements/button_is_clicked.c	\
		sources/menu/sprite/init_home_sprite.c	\
		sources/menu/display_event/display_home.c	\
		sources/menu/display_event/display_level.c 	\
		sources/menu/display_event/display_setting.c	\
		sources/menu/display_event/display_credit.c	\
		sources/menu/display_event/display_help.c	\
		sources/menu/sound/init_sound.c	\
		sources/game/game.c	\
		sources/game/display/display_after_enemies.c	\
		sources/game/display/display_enemies.c	\
		sources/game/maps/get_map.c	\
		sources/game/maps/get_info_map.c	\
		sources/game/decor/decor.c	\
		sources/game/decor/elements/malloc_elements.c	\
		sources/game/decor/elements/grass.c	\
		sources/game/decor/elements/road.c	\
		sources/game/decor/elements/boxes.c	\
		sources/game/decor/elements/rock.c	\
		sources/game/decor/elements/spawner.c	\
		sources/game/enemies/deplacements/which_move.c	\
		sources/game/enemies/deplacements/move.c	\
		sources/game/enemies/elements/soldier/soldier_move.c	\
		sources/game/enemies/elements/soldier/soldier.c	\
		sources/game/enemies/elements/tank/tank.c	\
		sources/game/enemies/elements/tank/tank_move.c	\
		sources/game/enemies/elements/generator/generator.c	\
		sources/game/enemies/set/set_enemies.c	\
		sources/end_game/end_game.c	\
		sources/game/menu_game/pause_menu.c	\
		sources/game/menu_game/display_setting_mode.c	\
		sources/game/menu_game/event_pause_on.c	\
		sources/game/menu_game/sprite/set_sprite.c	\
		sources/game/inventory/set_inventory.c	\
		sources/game/inventory/my_inventory.c	\
		sources/structures/set_struct.c	\
		sources/set_window.c	\
		sources/manage_sound.c	\
		sources/game/towers/set_towers.c	\
		sources/game/towers/my_towers.c	\
		sources/game/towers/display_towers.c	\
		sources/game/towers/shot.c	\
		sources/game/shop/my_shop.c	\
		sources/game/shop/buy_towers.c	\
		sources/game/decor/elements/money.c	\
		sources/game/inventory/inventory_event.c	\
		sources/menu/elements/my_music.c	\
		sources/game/enemies/deplacements/all_move.c	\
		sources/game/inventory/tower_func.c	\
		sources/game/menu_game/manage_setting.c	\
		sources/game/display/display_all.c	\

OBJ	=	$(SRC:.c=.o)

NAME = my_defender

EXTRACT	=	tar xf assets.tar.xz

NAME_DEBUG = my_defender_debug

CFLAGS =

CPPFLAGS = -I includes -L lib -lmy

CSFMl_FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio

DEBUG = -g

all: $(NAME)

$(NAME): $(OBJ)
	make re -C lib/
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(CSFMl_FLAGS)
	$(EXTRACT)

debug: $(NAME_DEBUG)

$(NAME_DEBUG): $(OBJ)
	make re -C lib/
	$(CC) -o $(NAME_DEBUG) $(OBJ) $(CPPFLAGS) $(CFLAGS) $(CSFMl_FLAGS) $(DEBUG)

clean:
	make clean -C lib
	$(RM) $(OBJ)

fclean: clean
	make fclean -C lib
	$(RM) $(NAME)
	$(RM) $(NAME_DEBUG)

re: fclean all

.PHONY: all clean fclean re debug
