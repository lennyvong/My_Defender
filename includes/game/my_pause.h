/*
** EPITECH PROJECT, 2022
** my_defender
** File description:
** my_pause
*/

#ifndef MY_PAUSE_H_
    #define MY_PAUSE_H_

void unmute_all(scenes_t *scenes);
void mute_all(scenes_t *scenes);
void display_setting_mode(scenes_t *scenes, manager_t *manager);
int event_pause_on(scenes_t *scenes, manager_t *manager);
void set_setting_sprite(game_pause_t *pause);
static void set_setting_elmt_pos(game_pause_t *pause);
static void set_setting_elmt(game_pause_t *pause);

#endif /* !MY_PAUSE_H_ */
