/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** GamepadPlayerInput
*/

#include "GamepadPlayerInput.hpp"

GamepadPlayerInput::GamepadPlayerInput(size_t pos)
{
    _pos = pos;
}

GamepadPlayerInput::~GamepadPlayerInput()
{
}

bool GamepadPlayerInput::shouldGoToEast(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 2);
}

bool GamepadPlayerInput::shouldGoToWest(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 4);
}

bool GamepadPlayerInput::shouldGoToNorth(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 1);
}

bool GamepadPlayerInput::shouldGoToSouth(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 3);
}

bool GamepadPlayerInput::shouldChangeToPrev(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 4);
}

bool GamepadPlayerInput::shouldChangeToNext(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 2);
}

bool GamepadPlayerInput::shouldSimulateAClick(void) const
{
    return Raylib::Gamepad::isGamepadButtonPressed(_pos, 7);
}
