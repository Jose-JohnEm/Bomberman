/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** MotionlessEntity
*/

#ifndef MOTIONLESSENTITY_HPP_
#define MOTIONLESSENTITY_HPP_

#include <vector>
#include <istream>
#include <algorithm>
#include <map>
#include "Interfaces/IEntity.hpp"

namespace Game
{
    class MotionlessEntity : public IEntity {

        public:
            /**
             * @brief Destroy the Motionless Entity object
             */
            virtual ~MotionlessEntity(void) {};

            /**
             * @brief Get the Type object
             *
             * @return A std::string
             */
            virtual std::string getType() = 0;

            /**
             * @brief Get the Positions object
             *
             * @return A Raylib::Vector3
             */
            Raylib::Vector3 getPositions(void) const;

            /**
             * @brief Set the Positions
             *
             * @param vector A vector3
             */
            void setPositions(Raylib::Vector3 &vector);

            /**
             * @brief Get Path To Obj
             */
            std::string getPathToObj() const;

            /**
             * @brief Get Path To Png
             */
            std::vector<std::string> getPathToPngs() const;

            /**
             * @brief Set a boolean to know if this entity should be displayed
             *
             * @param shouldDisplay A boolean to know if this entity should be displayed
             */
            void setShouldDisplay(bool shouldDisplay);

            /**
             * @brief Get a boolean to know if this entity should be displayed
             *
             * @return true or false
             */
            bool getShouldDisplay(void) const;

        protected:

            MotionlessEntity() = default;

            Raylib::Vector3 _positions{0, 0, 0};     // A vector3 that represents positions
            std::vector<std::string> _pathToPngs = {};              // Path To Pngs
            std::string _pathToObj = "";              // Path To Png
            bool _shouldDisplay = true;            // A boolean to know if this entity should be displayed
    };

     class SolidWall : public virtual MotionlessEntity {

        public:
        /**
         * @brief Construct a new Solid Wall
         *
         * @param positions A vector3, {0, 0, 0} as default value
         */
        SolidWall(Raylib::Vector3 positions = {0, 0, 0});

        std::string getType() override;
    };

    class BreakableWall : public virtual MotionlessEntity {

        public:
        /**
         * @brief Construct a new Solid Wall
         *
         * @param positions A vector3, {0, 0, 0} as default value
         */
        BreakableWall(Raylib::Vector3 positions = {0, 0, 0});

        std::string getType() override;
    };
}

#endif /* !MOTIONLESSENTITY_HPP_ */