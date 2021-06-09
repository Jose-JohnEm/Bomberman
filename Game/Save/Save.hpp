/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Save
*/

#ifndef SAVE_HPP_
#define SAVE_HPP_

#include <array>

namespace Game
{
    class Save
    {
        public:
            /**
            * @brief Construct the Save object
            */
            Save();

            /**
            * @brief Destroy the Save object
            */
            ~Save();

        private:
            std::array<std::size_t, 7> _settings; // An array of 7 size_t
    };

    #include "Save.inl"
}

#endif /* !SAVE_HPP_ */
