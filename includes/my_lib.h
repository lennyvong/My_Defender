/*
** EPITECH PROJECT, 2022
** my_lib.H
** File description:
** my_lib
*/

#ifndef MY_LIB_H_
    #define MY_LIB_H_

char *my_strcat(char *str1, char *str2);
char **my_str_to_word_array(char *str, char p_break);
void move_rect(sfIntRect *rect, int offset, int max_value, int min);
void add_tab_int(int *tab, int value);
sfIntRect get_rect(int top, int left, int width, int height);
void set_texture(sfSprite **sprite, sfTexture *texture);
void move_rect_minus(sfIntRect *rect, int offset, int max_value);
#endif /* !MY_LIB_H_ */
