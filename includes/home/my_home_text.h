/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_home_text
*/

#ifndef MY_HOME_TEXT_H_
    #define MY_HOME_TEXT_H_
    #include "my_structures.h"

typedef struct home_scene_s home_scene_t;
typedef struct scenes_s scenes_t;

void set_title(home_scene_t *home);
void set_text(home_scene_t *home, char *name, sfVector2f position, int i);
void set_home_text(home_scene_t *home);
void init_setting_text(home_scene_t *home);
void init_credit_text(home_scene_t *home);
void set_help_text(home_scene_t *home);

#endif /* !MY_HOME_TEXT_H_ */
