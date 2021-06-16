/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** KeyboardPlayerInput
*/

#include "KeyboardPlayerInput.hpp"

KeyboardPlayerInput::KeyboardPlayerInput()
{
}

KeyboardPlayerInput::~KeyboardPlayerInput()
{
}

bool KeyboardPlayerInput::shouldGoToEast(void) const
{
    return Raylib::Keyboard::isKeyPressed(262);
}

bool KeyboardPlayerInput::shouldGoToWest(void) const
{
    return Raylib::Keyboard::isKeyPressed(263);
}

bool KeyboardPlayerInput::shouldGoToNorth(void) const
{
    return Raylib::Keyboard::isKeyDown(265);
}

bool KeyboardPlayerInput::shouldGoToSouth(void) const
{
    return Raylib::Keyboard::isKeyDown(264);
}

bool KeyboardPlayerInput::shouldChangeToPrev(void) const
{
    return Raylib::Keyboard::isKeyPressed(263);
}

bool KeyboardPlayerInput::shouldChangeToNext(void) const
{
    return Raylib::Keyboard::isKeyPressed(262);
}

bool KeyboardPlayerInput::shouldSimulateAClick(void) const
{
    return Raylib::Keyboard::isKeyPressed(32);
}
