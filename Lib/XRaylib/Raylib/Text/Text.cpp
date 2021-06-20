/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Text
*/

#include "Text.hpp"
#include "../../../Engine/Exception/MyException.hpp"

Raylib::Text::Text()
{
}

Raylib::Text::~Text()
{
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTrydrawText() {
    try
    {   Raylib::Text test;
        Raylib::Color color;
        test.drawText("test", 0, 0, 1,color);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrymeasureText() {
    try
    {   Raylib::Text test;
        test.measureText("test", 1);
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrytextIsEqual() {
    try
    {   Raylib::Text test;
        test.textIsEqual("test","test");
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrytextLength() {
    try
    {   Raylib::Text test;
        test.textLength("test");
    }
    catch (Engine::MyException& ex)
    {
        std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}