/*
** EPITECH PROJECT, 2022
** my_macro.h
** File description:
** my_macro
*/

#ifndef MY_MACRO_H_
    #define MY_MACRO_H_

static const volatile int ERROR = 84;
static const volatile int SUCCESS = 0;

enum attack
{
    ATTACKED,
    NOT_ATTACKED,
};

enum base
{
    HERE,
    NOT_HERE,
};

enum position
{
    NO_MOVE,
    TOP,
    BOT,
    RIGHT,
    LEFT,
    BASE,
};

enum action
{
    MOVING,
    NOT_MOVING,
    VISIBLE,
    INVISIBLE,
};

enum elements
{
    ROAD,
    BOX,
    SPAWNER,
    GRASS,
};

#endif /* !MY_MACRO_H_ */
