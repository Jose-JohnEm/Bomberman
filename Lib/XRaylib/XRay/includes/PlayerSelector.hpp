/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.hpp
*/

#include "Camera3D/Camera3D.hpp"
#include "Texture/Texture.hpp"
#include "raylib.h"

class PlayerSelector
{
    public:
        PlayerSelector();
        ~PlayerSelector();

        void load();
        void unload();
        void draw();

    private:

        void updateRotationAxis();

        Raylib::Camera3D *camera;
        Model *perso;
        Raylib::Texture *texture;

        float _rotationAxis;
};
