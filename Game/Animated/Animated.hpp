/*
** EPITECH PROJECT, 2020
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Animated.hpp
*/

#include "Interfaces/IEntity.hpp"
#include "../Lib/XRaylib/Raylib/Vector3/Vector3.hpp"
#include <string>
#include <filesystem>
#include <cmath>
#include "Interfaces/IEntity.hpp"
#include "Modeler.hpp"

namespace Game
{
class Animated : public IEntity
{
        public:

            /**
             * @brief Construct a new Animated object
             *
             * @param positions the Animated Object positions
             * @param obj_path the model path
             * @param texture_path the texture path
             * @param animation_path the animation path
             * @param scalable the scalable value
             * @param color the color
             */
            Animated(const Raylib::Vector3 &positions, const std::string &obj_path, const std::string &texture_path, const std::vector<std::string> &animation_path = {}, const float &scalable = 0.6, const Raylib::Color color = Raylib::Color::White());

            /**
             * @brief Destroy the Animated Entity object
             */
            virtual ~Animated(void) {};

            /**
             * @brief Get the Animated positions
             *
             * @return A Raylib::Vector3
             */
            Raylib::Vector3 getPositions(void) const override;

            /**
             * @brief Get the Type object
             *
             * @return A std::string
             */
            virtual std::string getType() const override = 0;

            /**
             * @brief Get player scalability
             *
             * @return A float
             */
            float getScalable(void) const;

            /**
             * @brief Set player scalability
             *
             * @param scalable A float
             */
            void setScalable(const float &scalable);

            /**
             * @brief Set the Positions
             *
             * @param positions A vector3
             */
            void setPositions(Raylib::Vector3 &positions) override;

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
            void setShouldDisplay(const bool &shouldDisplay) override;

            /**
             * @brief Get a boolean to know if this entity should be displayed
             *
             * @return true or false
             */
            bool getShouldDisplay(void) const override;

            /**
             * @brief Set a animated model
             *
             * @param model A const reference to a string describing the player name
             */
            void setModel(const std::string &model);

            /**
             * @brief Set player color
             *
             * @param color A const reference to a Raylib::Color
             */
            void setColor(const Raylib::Color &color);

            /**
             * @brief Set player color
             *
             * @param color A const reference to a string
             */
            void setColor(const std::string &color);

            /**
             * @brief
             *
             * @param direction
             */
            void move(const std::string &direction);

            /**
             * @brief
             *
             * @return std::pair<int, int>
             */
            std::pair<int, int> getPositions2D();

        private:

            /**
             * @brief convert vector of string path to Animator
             *
             * @param animation_path vector of string paths
             * @return Animator
             */
            Animator getAnimator(const std::vector<std::string> &animation_path);

            Raylib::Vector3 _positions{0, 0, 0}; // A vector3 that represents positions
            bool _shouldDisplay = true; // A boolean to know if this entity should be displayed
            Modeler _model; // Player model
            Raylib::Color _color; // Player color
            float _scalable; // Player scalability
            float _rotation;

    };

    class Bomb : public Animated
    {
        public:

            /**
             * @brief Construct a new Bomb object
             *
             * @param positions
             * @param fire
             */
            Bomb(const Raylib::Vector3 &positions, const int &fire);

            /**
             * @brief Destroy the Bomb object
             *
             */
            ~Bomb();

            /**
             * @brief Make the bomb explose
             *
             */
            int makeExplode();

            /**
             * @brief
             *
             * @return true
             * @return false
             */
            bool isExploding();

            /**
             * @brief
             *
             * @return true
             * @return false
             */
            bool hasExplode();

        private:
            Clock clock;
            bool _explosing;
            bool _exploded;
            int _fire;
    };

    #include "Animated.inl"

} // namespace Game
