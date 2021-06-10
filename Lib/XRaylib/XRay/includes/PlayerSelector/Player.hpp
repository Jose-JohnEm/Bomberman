/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player.hpp
*/

#ifndef PLAYERSELECTOR_PLAYER
#define PLAYERSELECTOR_PLAYER

#include "raylib.h"
#include "Texture/Texture.hpp"
#include "Vector3/Vector3.hpp"
#include "Clock.hpp"

namespace PlayerSelector
{
    class Player
    {
        public:

            /**
             * @brief Construct a new Player object
             * 
             * @param obj model path
             * @param texture texture path
             * @param scalable scalable value
             * @param idCharacter id of the character
             * @param name name of the character
             * @param color main color of the character
             * @param animations strings vector of animations'path
             */
            Player(const std::string &obj, const std::string &texture, const float &scalable, const int &idCharacter, const std::string &name, const Raylib::Color &color = Raylib::Color::White(), const std::vector<std::string> &animations = {});
            
            /**
             * @brief Destroy the Player object
             * 
             */
            ~Player();
            
            /**
             * @brief Display the character
             * 
             * @param rotation rotation value (if there's not animations)
             * @param pos position to display the character
             */
            void draw(const float &rotation, const Raylib::Vector3 &pos);
            
            /**
             * @brief Get the character's Id 
             * 
             * @return the id
             */
            int getId(void) const;

            /**
             * @brief Get the Name 
             * 
             * @return the character's name
             */
            const std::string getName() const;

            /**
             * @brief Get the Model
             * 
             * @return a pair of the Model and its scalable value
             */
            std::pair<Model, float> getModel() const;


        private:
            std::string _name;
            int _idCharacter;
            float _scalable;
            Model _persoModel;
            Raylib::Texture _persoTexture;
            Raylib::Color _color;
            std::vector<ModelAnimation> _animations;

            Clock clock;
            int counter;
    };
    
} // namespace PlayerSelector

#endif