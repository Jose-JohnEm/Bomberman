/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** PlayerSelector.hpp
*/

#ifndef PLAYERSELECTOR_SELECTOR
#define PLAYERSELECTOR_SELECTOR

#include "Camera3D/Camera3D.hpp"
#include "Texture/Texture.hpp"
#include "raylib.h"
#include "PlayerSelector/Player.hpp"
#include "PlayerSelector/Map.hpp"
#include <filesystem>

#define POS_1 Raylib::Vector3(-3.25, -0.15, 0)
#define POS_2 Raylib::Vector3(-1.10, -0.15, 0)
#define POS_3 Raylib::Vector3(1.15, -0.15, 0)
#define POS_4 Raylib::Vector3(3.35, -0.15, 0)



namespace PlayerSelector
{
    struct CharDictionary
    {
        std::string obj;
        std::string texture;
        float scalable;
        std::string name;
        Raylib::Color color;
        std::vector<std::string> animations;
    };

    class Selector
    {
        public:
            /**
             * @brief Construct a new Selector object
             * 
             */
            Selector();

            /**
             * @brief Destroy the Selector object
             * 
             */
            ~Selector();

            /**
             * @brief Load for the first time a character
             * 
             */
            void firstLoad();

            /**
             * @brief Add a character
             * 
             */
            void load();

            /**
             * @brief Remove a character
             * 
             * @param id character's id to remove
             */
            void unload(const int &id);

            /**
             * @brief Get characters Models
             * 
             * @return a vector of pairs of Model withe their scalable value 
             */
            std::vector<std::pair<Model, float>> getModels() const;

            /**
             * @brief Get the Bloc Textures object
             * 
             * @return a vector of textures
             */
            std::vector<Texture2D> getBlocTextures() const;

            /**
             * @brief Remove all characters
             * 
             */
            void unloadAll();

            /**
             * @brief Display all the players
             * 
             */
            void drawPlayers();

            /**
             * @brief Init the 3D maps from the Ascii one
             * 
             * @param asciiMap the ascii map
             */
            void initMaps(std::vector<std::string> asciiMap);

            /**
             * @brief Display the 3D map
             * 
             * @param asciiMap a new ascii map 
             */
            void drawMaps();

            /**
             * @brief Get the Ascii Map
             * 
             * @return the ascii map 
             */
            std::vector<std::string> getMap() const;

            /**
             * @brief Unload map
             * 
             */
            void endMaps();

            /**
             * @brief Select the next map textures
             * 
             */
            void nextMap();

            /**
             * @brief Select the previous map textures
             * 
             */
            void prevMap();

            /**
             * @brief Select the next character
             * 
             * @param player id of player who want to change the character
             */
            void next(const int &player);

            /**
             * @brief Select the next character
             * 
             * @param player id of player who want to change the character 
             */
            void prev(const int &player);

            /**
             * @brief Get the Map Type
             * 
             * @return map type (Floor, Wall, or Box)
             */
            size_t getMapType() const;

            std::vector<Raylib::Vector3> POS;

            PlayerSelector::Player &operator[](const int &index);
            const PlayerSelector::Player &operator[](const int &index) const;

        private:
            
            /**
             * @brief update Characters z Rotation axis 
             * 
             */
            void updateRotationAxis();

            Raylib::Camera3D *camera;
            std::vector<PlayerSelector::Player> _players;
            int _nbCharacters;
            std::vector<CharDictionary> _charaDictionary;
            Map *_map;
            std::vector<std::string> _asciiMap = {""};

            float _rotationAxis;
    };
}

#endif