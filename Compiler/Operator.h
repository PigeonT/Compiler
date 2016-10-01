//
//  Operator.h
//  Compiler
//
//  Created by pigeon on 30/09/2016.
//  Copyright © 2016 pigeon. All rights reserved.
//

#ifndef COMPILER_OPERATOR_H__
#define COMPILER_OPERATOR_H__
#include <iostream>
namespace Compiler {
    enum class Operator : std::int32_t;
}

enum class Compiler::Operator : std::int32_t
{
    PLUS,
    MINUS,
    ASSIGN,
    MULTIPLY,
    DIVISION,
    NUMBER,
    LEFT_PARENT,
    RIGHT_PARENT,
    IDENTIFIER
};

#endif /* Operator_h */
