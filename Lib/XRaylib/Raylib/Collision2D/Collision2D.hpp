/*
** EPITECH PROJECT, 2021
** Indie
** File description:
** Collision2D
*/

#ifndef Collision2D_HPP_
#define Collision2D_HPP_

#include <string>
#include <iostream>
#include "Vector2/Vector2.hpp"
#include "Rectangle/Rectangle.hpp"
#include "raylib.h"

namespace Raylib
{
    class Collision2D {
        public:
            /**
             * @brief Construct a new Collision2D object
             */
            Collision2D();

            /**
             * @brief Destroy the Collision2D object
             */
            ~Collision2D();

            /**
             * @brief Check if two rectangles intersects
             * 
             * @param rec1 the first rectangle
             * @param rec2 the second one
             * @return true when the rectangles intersects
             * @return false otherwise  
             */
            bool checkCollision(Rectangle rec1, Rectangle rec2);

            /**
             * @brief 
             * 
             * @param center1 the first circle's center position
             * @param radius1 the first circle's radius
             * @param center2 the second circle's center position
             * @param radius2 the second circle's radius
             * @return true when the rectangles intersect
             * @return false otherwise
             */
            bool checkCollision(Vector2 center1, float radius1, Vector2 center2, float radius2);

            /**
             * @brief 
             * 
             * @param center the circle's center position
             * @param radius the circle's radius
             * @param rec the rectangle
             * @return true when the rectangle and the circle intersect
             * @return false otherwise
             */
            bool checkCollision(Vector2 center, float radius, Rectangle rec);

            /**
             * @brief 
             * 
             * @param point the point coordinates
             * @param rec the rectangle
             * @return true when the point is on the rectangle
             * @return false otherwise
             */
            bool checkCollision(Vector2 point, Rectangle rec);

            /**
             * @brief 
             * 
             * @param point the point coordinates
             * @param center the circle's center position
             * @param radius the circle's radius
             * @return true when the point is on the circle
             * @return false otherwise
             */
            bool checkCollision(Vector2 point, Vector2 center, float radius);

            /**
             * @brief 
             * 
             * @param point the point coordinates
             * @param p1 the first triangle's point 
             * @param p2 the second trinagle's point
             * @param p3 the third triangle's point
             * @return true when the point is on the trinagle
             * @return false otherwise
             */
            bool checkCollision(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3);

            /**
             * @brief 
             * 
             * @param startPos1 the first lines's start position
             * @param endPos1 the first lines's end position
             * @param startPos2 the second lines's start position
             * @param endPos2 the second lines's end position
             * @param collisionPoint the collision point pointer
             * @return true when the two lines intersect
             * @return false otherwise 
             */
            bool checkCollision(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 &collisionPoint);

            /**
             * @brief Get the Collision Rec object
             * 
             * @param rec1 the first rectangle
             * @param rec2 the second rectangle
             * @return Rectangle corresponding the instersection zone
             */
            Rectangle getCollision(Rectangle rec1, Rectangle rec2);
 
    };

    #include "Collision2D.inl"

}

#endif /* !Collision2D_HPP_ */
