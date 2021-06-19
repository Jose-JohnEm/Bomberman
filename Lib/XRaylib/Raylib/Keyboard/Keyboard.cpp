/*
** EPITECH PROJECT, 2021
** B-YEP-400-LYN-4-1-indiestudio-lucas.guichard
** File description:
** Keyboard
*/

#include "Keyboard.hpp"
#include "../../../Engine/Exception/MyException.hpp"

Raylib::Keyboard::Keyboard()
{
}

Raylib::Keyboard::~Keyboard()
{
}

// STANDARD EXCEPTION CLASS detection according to type of exceptions if one exists.
// catch
// throw
// try

int catchThrowTryisKeyPressed() {
    try
    {   Raylib::Keyboard test;
        size_t key;
    	test.isKeyPressed(key);
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryisKeyDown() {
    try
    {   Raylib::Keyboard test;
        size_t key;
    	test.isKeyDown(key);
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryisKeyReleased() {
    try
    {   Raylib::Keyboard test;
        size_t key;
    	test.isKeyReleased(key);
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTryisKeyUp() {
    try
    {   Raylib::Keyboard test;
        size_t key;
    	test.isKeyUp(key);
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetKeyPressed() {
    try
    {   Raylib::Keyboard test;
    	test.getKeyPressed();
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}

int catchThrowTrygetCharPressed() {
    try
    {   Raylib::Keyboard test;
    	test.getCharPressed();
    }
    catch (Engine::MyException& ex)
    {
    	std::cout << ex.what() << ex.get_info() << std::endl;
        std::cout << "Function: " << ex.get_func() << std::endl;
        return EXIT_FAILURE;
    }
    return 0;
}