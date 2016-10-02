//
//  Utils.hpp
//  Compiler
//
//  Created by pigeon on 02/10/2016.
//  Copyright © 2016 pigeon. All rights reserved.
//

#ifndef Utils_hpp
#define Utils_hpp

#include <iostream>

namespace Compiler
{
    // trim from left
    inline std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v")
    {
        s.erase(0, s.find_first_not_of(t));
        return s;
    }
    
    // trim from right
    inline std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v")
    {
        s.erase(s.find_last_not_of(t) + 1);
        return s;
    }
    
    // trim from left & right
    inline std::string& trim(std::string& s, const char* t = " \t\n\r\f\v")
    {
        return ltrim(rtrim(s, t), t);
    }
    
    inline bool BothAreSpaces(char lhs, char rhs)
    { return (lhs == rhs) && (lhs == ' '); }


}


#endif /* Utils_hpp */
