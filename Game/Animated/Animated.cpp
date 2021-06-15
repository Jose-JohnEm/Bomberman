/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Animated.cpp
*/

#include "Animated.hpp"

Game::Animated::Animated(const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
    : _positions(positions),
    _model(obj_path, texture_path, getAnimator(animation_path)),
    _scalable(scalable),
    _color(color)
{
}

Animator Game::Animated::getAnimator(const std::vector<std::string> &animation_path)
{
    for (auto p : animation_path)
        std::cout << p << std::endl;
    if (animation_path.size() == 3)
        return Animator({animation_path[0], animation_path[1], animation_path[2]});
    else
        return Animator({"null", "null", "null"});
}

void Game::Animated::setModel(const std::string &model)
{
    bool ok = false;
    std::string obj_path = "null";
    std::string texture_path = "null";

    if (model == "Blue" || model == "Green" || model == "Yellow" || model == "Red")
    {
        _model = Modeler("resources/players/3D/Bombermans/white_tpose.glb",
            "resources/players/3D/Bombermans/texture.png",
            {
                "resources/players/3D/Bombermans/animations/white_walking.glb",
                "resources/players/3D/Bombermans/animations/white_bomb.glb",
                "resources/players/3D/Bombermans/animations/white_emote.glb"
            }
        );
    }
    else
    {
        for (const auto & file : std::filesystem::directory_iterator("resources/players/3D/" + model))
        {
            if (file.path().extension() == ".obj")
                obj_path = file.path().string();
            if (file.path().filename() == "texture.png")
                texture_path = file.path().string();
        }
        if (obj_path != "null" && texture_path != "null")
        {
            _model = Modeler(obj_path, texture_path, {"null", "null", "null"});
        }
    }
    std::cout << "MODELER " << _model.getObjPath() << " " << _model.getTexturePath() << " " << _model.getAnimationPath().WALK << std::endl;
}