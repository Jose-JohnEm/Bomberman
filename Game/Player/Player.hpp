/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <array>
#include <utility>
#include <string>
#include "Interfaces/IEntity.hpp"
#include "../Lib/XRaylib/Raylib/Vector3/Vector3.hpp"
#include "Modeler.hpp"

typedef enum {
    P_SKATE,
    P_BOMB,
    P_PASS,
    P_FIRE,
    P_LIFE
} Powerups;

namespace Game
{
    class Player : public IEntity
    {
        public:
           /**
            * @brief Construct the Player object
            */
            Player();

            /**
            * @brief Construct the Player object (Copy Constructor)
            *
            * @param name A const reference to a std::string
            * @param position A const reference to a std::pair of float
            * @param brokenWalls A const reference to a size_t
            * @param kills A const reference to a size_t
            * @param powerUps A const reference to a std::array of 5 int
            */
            Player(const std::string &name, const Raylib::Vector3 &positions, const size_t &kills, const size_t &brokenWalls, const std::array<int, 5> &powerUps);

            /**
             * @brief Construct a new Player object
             * 
             * @param name the name of the character
             * @param positions the 3D positions of the character
             * @param obj_path the model path
             * @param texture_path the texture path
             * @param animation_path the animations paths
             */
            Player(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const Animator &animation_path = {}, const Raylib::Color color = Raylib::Color::White());

            /**
             * @brief Get the Name of the Player
             *
             * @return A string
             */
            std::string getName(void) const;

            /**
             * @brief Get Broken Walls by the Player
             *
             * @return A size_t
             */
            size_t getBrokenWalls(void) const;

            /**
             * @brief Get Kills by the Player
             *
             * @return A size_t
             */
            size_t getKills(void) const;

            /**
             * @brief Get PowerUps gotten by the Player
             *
             * @return An Array of 5 (int)
             */
            std::array<int, 5> getPowerUps(void) const;

            /**
             * @brief Get the player ID
             *
             * @return An int which represents the ID of the player
             */
            int getID(void) const;

            /**
             * @brief Set the name of the player
             *
             * @param name A const reference to a string
             */
            void setName(const std::string &name);

            /**
             * @brief Set the broken walls number
             *
             * @param brokenWalls A const reference to a size_t
             */
            void setBrokenWalls(const size_t &brokenWalls);

            /**
             * @brief Set the kills number
             *
             * @param kills A const reference to a size_t
             */
            void setKills(const size_t &kills);

            /**
             * @brief Set the powerUps of the player
             *
             * @param powerUps A const reference to an array of 5 int
             */
            void setPowerUps(const std::array<int, 5> &powerUps);

            /**
             * @brief Set the ID of the player
             */
            void setID(const int &ID);

            /**
             * @brief Destroy the Player Entity object
             */
            virtual ~Player(void) {};

            /**
             * @brief Get the Type object
             *
             * @return A std::string
             */
            virtual std::string getType() const = 0;

            /**
             * @brief Get the Positions object
             *
             * @return A Raylib::Vector3
             */
            Raylib::Vector3 getPositions(void) const;

            /**
             * @brief Set the Positions
             *
             * @param positions A vector3
             */
            void setPositions(Raylib::Vector3 &positions);

            /**
             * @brief Draw Entity
             *
             */
            void drawEntity() override;

            /**
             * @brief Set a boolean to know if this entity should be displayed
             *
             * @param shouldDisplay A boolean to know if this entity should be displayed
             */
            void setShouldDisplay(const bool &shouldDisplay);

            /**
             * @brief Get a boolean to know if this entity should be displayed
             *
             * @return true or false
             */
            bool getShouldDisplay(void) const;

        private:
            std::string _name; // Name of the player entitiy
            Raylib::Vector3 _positions{0, 0, 0}; // A vector3 that represents positions
            size_t _brokenWalls; // Amount of broken walls
            size_t _kills; // Amount of kills
            std::array<int, 5> _powerUps; // Amount of powerUps
            int _ID; // ID of the player
            bool _shouldDisplay = true; // A boolean to know if this entity should be displayed
            Modeler _model;
            const Raylib::Color _color;
    };

    class Human : public virtual Player {

        public:

            /**
             * @brief Construct a new Player object
             * 
             * @param name the name of the character
             * @param positions the 3D positions of the character
             * @param obj_path the model path
             * @param texture_path the texture path
             * @param animation_path the animations paths
             */
            Human(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path = "resources/players/3D/Bombermans/white_tpose.glb", const std::string &texture_path = "resources/players/3D/Bombermans/texture.png", const Animator &animation_path = {}, const Raylib::Color color = Raylib::Color::White());

            std::string getType() const override;

    };

    class AI : public virtual Player {

        public:

            /**
             * @brief Construct a new Player object
             * 
             * @param name the name of the character
             * @param positions the 3D positions of the character
             * @param obj_path the model path
             * @param texture_path the texture path
             * @param animation_path the animations paths
             */
            AI(const std::string &name, const Raylib::Vector3 &positions, const std::string &obj_path = "resources/players/3D/Bombermans/white_tpose.glb", const std::string &texture_path = "resources/players/3D/Bombermans/texture.png", const Animator &animation_path = {}, const Raylib::Color color = Raylib::Color::White());

            std::string getType() const override;

    };

    #include "Player.inl"
}

#endif /* !PLAYER_HPP_ */