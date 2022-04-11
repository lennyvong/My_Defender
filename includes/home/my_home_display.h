/*
** EPITECH PROJECT, 2022
** B-MUL-200-PAR-2-1-mydefender-lenny.vongphouthone
** File description:
** my_home_display
*/

#ifndef MY_HOME_DISPLAY_H_
    #define MY_HOME_DISPLAY_H_

typedef struct home_scene_s home_scene_t;
typedef struct scenes_s scenes_t;
typedef struct manager_s manager_t;

/* main display */
void display_home(scenes_t *scenes);
void display_level(scenes_t *scenes);
void display_credit(scenes_t *scenes);
void display_help(scenes_t *scenes);
void display_book(scenes_t *scenes_s, float speed);
void display_smoke(scenes_t *scenes);
void display_buttons(manager_t *manager, home_scene_t *home);
void display_speaker(scenes_t *scenes, speaker_t *speaker);

/* display event */
void display_home_settings(scenes_t *scenes);
void display_home_event1(scenes_t *scenes, int i);
void display_level_event(scenes_t *scenes, int i);
void display_setting_event(scenes_t *scenes, int i);
void display_credit_event(scenes_t *scenes, int i);
void display_help_event(scenes_t *scenes, int i);

#endif /* !MY_HOME_DISPLAY_H_ */
