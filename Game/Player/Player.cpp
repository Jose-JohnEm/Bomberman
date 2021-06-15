/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

#include "Player.hpp"

Game::Animated::Animated(const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
    : _positions(positions),
    _model(obj_path, texture_path, getAnimator(animation_path)),
    _scalable(scalable),
    _color(color)
{
}

Game::Player::Player()
    : Animated({0, 0, 0}, "resources/players/3D/Bombermans/white_tpose.glb", "resources/players/3D/Bombermans/texture.png"),
    _kills{0},
    _brokenWalls{0},
    _powerUps{0}
{
}

Game::Player::Player(const std::string &name, const Raylib::Vector3 &positions, const size_t &kills, const size_t &brokenWalls, const std::array<int, 5> &powerUps)
    : Animated(positions, "resources/players/3D/Bombermans/white_tpose.glb", "resources/players/3D/Bombermans/texture.png"),
    _kills{kills},
    _brokenWalls{brokenWalls},
    _powerUps{powerUps}
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

Game::Player::Player(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
    : Animated(positions, obj_path, texture_path, animation_path, scalable, color),
     _name{name},
    _kills{0},
    _brokenWalls{0},
    _powerUps{0}
{
    std::cout << "Hey I'm a new player : " << name << std::endl;
}

Game::AI::AI(const std::string &name, const int ID, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
: Player(name, ID, positions, obj_path, texture_path, animation_path, scalable, color)
{
}

Game::Human::Human(const std::string &name, const int ID, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path, const float &scalable, const Raylib::Color color)
: Player(name, ID, positions, obj_path, texture_path, animation_path, scalable, color)
{
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

void Game::Player::move(const std::string &direction)
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

    _model.update();

}

std::pair<int, int> Game::Player::getPositions2D()
{
    return {(int)round(_positions.x), (int)round(_positions.y)};
}