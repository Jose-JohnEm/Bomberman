/*
** MyException.hpp for B-YEP-400-LYN-4-1-indiestudio-lucas.guichard in /Users/charlesvictormahouve/delivery/B-YEP-400-LYN-4-1-indiestudio-lucas.guichard/Engine/Exception
**
** Made by charles mahouve
** Login   <charles.mahouve>
**
** Started on  Fri Jun 18 3:56:43 PM 2021 charles mahouve
** Last update Sat Jun 18 3:58:39 PM 2021 charles mahouve
*/
#include <vector>
#include <istream>
#include <algorithm>
#include <iostream>
#include <exception>
#include <cassert>
#include <assert.h>

#ifndef MYEXCEPTION_HPP_
#define MYEXCEPTION_HPP_

namespace Engine
{
    class MyException : public std::exception
    {

    public:
        /**
         * @brief Detect if a certain functions hits and exception
         *
         * @param file
         * @param line
         * @param func
         * @param info
         * @return info // about the type of exception that occured
         * @return func // the name of the aforomentioned function
         */
        MyException(const char *msg, const char *file_, int line_, const char *func_, const char *info_ = "") : std::exception(),
        file(file_),line(line_),func(func_),info(info_)
        {
        }

         /**
         * @brief gzt the file
         */
        const char *get_file() const { return file; }

        /**
         * @brief gt the line
         */
        int get_line() const { return line; }

        /**
         * @brief gt the function
         */
        const char *get_func() const { return func; }

        /**
         * @brief gt the type of exceptions
         */

        const char *get_info() const { return info; }

    private:
        /// This stores the file name
        const char *file;
        /// This stores the actiual line 
        int line;
        /// This stores the function
        const char *func;
        /// This stores  the exception info
        const char *info;
    };

} // namespace Engine

#endif /* !MYEXCEPTION_HPP_ */
