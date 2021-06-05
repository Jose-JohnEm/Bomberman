/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** InGame
*/

#include "XRay.hpp"

void XRay::displayPlayersPanels(void)
{
    ;
}

void XRay::displayInGameScene(void)
{
    // Set scene
    _scene = IN_GAME;

    // Draw scene
    beginDrawing();

    displayPlayersPanels();
    // Some code

    endDrawing();
}