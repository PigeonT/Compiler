//
//  InvalidTokenException.cpp
//  Compiler
//
//  Created by pigeon on 02/10/2016.
//  Copyright © 2016 pigeon. All rights reserved.
//

#include "InvalidTokenException.hpp"
#include "Exception.hpp"

Compiler::InvalidTokenException::InvalidTokenException() = default;

const char*
Compiler::InvalidTokenException::what() const throw()
{
    throw "Unexpected Token: Invalid stdin";
};
