//
//  Exception.hpp
//  Compiler
//
//  Created by pigeon on 02/10/2016.
//  Copyright © 2016 pigeon. All rights reserved.
//

#ifndef Exception_hpp
#define Exception_hpp

#include <iostream>
#include <exception>
namespace Compiler
{
    class Exception;
}

class Compiler::Exception : virtual public std::exception
{
    virtual const char* what() const throw() = 0;
};
#endif /* Exception_hpp */
