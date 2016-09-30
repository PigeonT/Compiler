#ifndef _LEXER_H__
#define _LEXER_H__

#include "Operator.h"				
#include <iostream>
#include <vector>

namespace Compiler
{
    class Lexer;
    friend void PrintInputsVector(Lexer&);
}

class Lexer final
{
private:
    std::vector<Operator> tokens;
    std::vector<std::string> stringTokens;
    const std::string& inputsString; 

    Operator GetToken(const string&);
public:
    explicit Lexer();
    explicit Lexer(const std::string&); 
    void Init();

    void SplitInputs(const std::string&);
    
    bool IsSpace(const char&);
    
    void GetTokenVector(); 
friend void PrintInputsVector(Lexer&);
};
#endif
