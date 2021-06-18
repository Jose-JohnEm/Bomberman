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
# define MYEXCEPTION_HPP_

namespace Engine
{
    class MyException : public std::exception {
	const char* file;
    int line;
    const char* func;
    const char* info;
    
    public:
    	MyException(const char* msg, const char* file_, int line_, const char* func_, const char* info_ = "") : std::exception(),
        	file (file_),
        	line (line_),
        	func (func_),
        	info (info_)
        {
        }
        
        const char* get_file() const { return file; }
        int get_line() const { return line; }
		const char* get_func() const { return func; }
        const char* get_info() const { return info; }
       
};

}

#endif /* !MYEXCEPTION_HPP_ */
