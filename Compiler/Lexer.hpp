#ifndef _LEXER_H__
#define _LEXER_H__

#include "Operator.h"				
#include <iostream>
#include <vector>

namespace Compiler
{
    class Lexer;
}

class Lexer final
{
private:
    std::vector<Operator> tokens;
    std::vector<std::string> stringTokens;
    
public:
    explicit Lexer();
    
    void SplitInputs(const std::string&);
    
    bool IsSpace(const char&);
    
    Operator GetToken(const char& c);
    
};
#endif
