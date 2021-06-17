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
    _color(color),
    _moving(false)
{
}

Game::Bomb::Bomb(const Raylib::Vector3 &positions, const int &fire)
    : Animated(positions, "resources/assets/3D/Bombs/Animated/bomb.glb", "resources/assets/3D/Bombs/Animated/texture.png", {"resources/assets/3D/Bombs/Animated/bomb.glb", "resources/assets/3D/Bombs/Animated/bomb.glb", "resources/assets/3D/Bombs/Animated/bomb.glb"}),
    _fire(fire),
    _exploded(false),
    _explosing(false),
    _bZoneX({0, 0}),
    _bZoneY({0, 0})
{

}

Game::Bomb::~Bomb()
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

void Game::Animated::move(const std::string &direction)
{
    std::map<std::string, std::pair<float, float>> dict = {
        {"goEast", {-0.01f, 0.f}},
        {"goNorth", {0.f, 0.01f}},
        {"goSouth", {0.f, -0.01f}},
        {"goWest", {0.01f, 0.f}}
    };

    std::map<std::string, float> rota = {
        {"goEast", 180.f},
        {"goNorth", 90.f},
        {"goSouth", 270.f},
        {"goWest", 0.f}
    };

    _model.makeWalk();
    _rotation = rota[direction];

    _positions.x += dict[direction].first;
    _positions.y += dict[direction].second;

    _moving = true;
    _model.update();

}

std::pair<int, int> Game::Animated::getPositions2D()
{
    return {(int)round(_positions.x), (int)round(_positions.y)};
}