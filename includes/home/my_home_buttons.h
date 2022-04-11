/*
** EPITECH PROJECT, 2022
** my_home_buttons.h
** File description:
** my_home_buttons
*/

#ifndef MY_HOME_BUTTONS_H_
    #define MY_HOME_BUTTONS_H_
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/System/Vector3.h>
    #include <SFML/System/InputStream.h>
    #include <SFML/Audio/Export.h>
    #include <SFML/Audio/Types.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Audio/SoundStatus.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct scenes_s scenes_t;
typedef struct manager_s manager_t;
typedef struct home_scene_s home_scene_t;
typedef struct button_s button_t;

void display_buttons(manager_t *manager, home_scene_t *home);
void manage_button_rect(sfVector2f position, home_scene_t *home,
sfEvent event, int i);
void set_home_button(home_scene_t *home);
void button_is_clicked(button_t *button, scenes_t *scenes, sfVector2f click_position, int i);

#endif /* !MY_HOME_BUTTONS_H_ */
