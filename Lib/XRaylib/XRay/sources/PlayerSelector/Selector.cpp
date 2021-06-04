/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.cpp
*/

#include "PlayerSelector/Selector.hpp"

std::vector<std::pair<std::string, std::string>> findCharactersAvailable(int &nb_Characters)
{
    std::vector<std::pair<std::string, std::string>> res;
    std::string obj;
    std::string texture;

    for (const auto & file : std::filesystem::directory_iterator("resources/players/3D"))
    {
        if (file.is_directory())
        {
            for (const auto &f : std::filesystem::directory_iterator(file.path()))
            {
                if (f.path().extension() == ".obj")
                {
                    obj = f.path().string();
                    break;
                }
            }
            for (const auto &f : std::filesystem::directory_iterator(file.path()))
            {
                if (f.path().extension() == ".png")
                {
                    texture = f.path().string();
                    break;
                }
            }
            res.push_back({obj, texture});
        }
    }
    nb_Characters = res.size();
    return res;
}

PlayerSelector::Selector::Selector()
: camera(nullptr), _rotationAxis(0), _players({}), _nbCharacters(0), _charaDictionary(findCharactersAvailable(_nbCharacters))
{
    findCharactersAvailable(_nbCharacters);
    POS.push_back(POS_1);
    POS.push_back(POS_2);
    POS.push_back(POS_3);
    POS.push_back(POS_4);

    std::cout  << std::endl << "####### Start Player Selector #######"  << std::endl << std::endl;
}

PlayerSelector::Selector::~Selector()
{

}

void PlayerSelector::Selector::load()
{
    std::cout << std::endl << "######## Load Player Selector ########" << std::endl << std::endl;
    
    if (_players.size() == 4)
        return;
    if (!camera)
    {
        Raylib::Vector3 pos(0, 0, 10);
        Raylib::Vector3 target(0, 0, 0);
        Raylib::Vector3 up(0, 1, 0);

        camera = new Raylib::Camera3D(pos, target, up, 30);
        std::cout << "Camera OK" << std::endl;

        camera->updateCamera();

        camera->setCameraMode(CAMERA_FREE);
    }

    std::cout << std::endl << "######## Init Player Selector ########" << std::endl << std::endl;

    _players.push_back(Player(_charaDictionary[0].first, _charaDictionary[0].second, 0));


}

void PlayerSelector::Selector::unload(const int &id)
{   
    std::cout << std::endl << "######## End Player Selector ########" << std::endl << std::endl;

    _players.erase(_players.begin() + id);
}

void PlayerSelector::Selector::unloadAll()
{
    for (PlayerSelector::Player &player : _players)
    {
        _players.pop_back();
    }

    delete camera;
}

void PlayerSelector::Selector::updateRotationAxis()
{
    _rotationAxis += 0.24;

    if (_rotationAxis > 360)
        _rotationAxis -= 360;
}

void PlayerSelector::Selector::draw()
{
    char i = 0;
    
    camera->beginMode3D();

    for (PlayerSelector::Player &player : _players)
    {
        player.draw(_rotationAxis, POS[i]);
        i++;
    }
    
    updateRotationAxis();
    camera->endMode3D();
}

void PlayerSelector::Selector::next(const int &id)
{
    int next_id = (_players[id].getId() + 1 == _nbCharacters) ? 0 : _players[id].getId() + 1;

    _players[id] = Player(_charaDictionary[next_id].first, _charaDictionary[next_id].second, next_id);

}

void PlayerSelector::Selector::prev(const int &id)
{
    int next_id = (_players[id].getId() - 1 < 0) ? _nbCharacters : _players[id].getId() - 1;

    _players[id] = Player(_charaDictionary[next_id].first, _charaDictionary[next_id].second, next_id);
}