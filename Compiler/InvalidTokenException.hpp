//
//  InvalidTokenException.hpp
//  Compiler
//
//  Created by pigeon on 02/10/2016.
//  Copyright © 2016 pigeon. All rights reserved.
//

#ifndef InvalidTokenException_hpp
#define InvalidTokenException_hpp

#include "Exception.hpp"
#include <iostream>

namespace Compiler {
    class InvalidTokenException;
}

class Compiler::InvalidTokenException final
      : virtual public Exception
{
public:
    InvalidTokenException();
    const char* what() const throw() override;
};

#endif /* InvalidTokenException_hpp */
