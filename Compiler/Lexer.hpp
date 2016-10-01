#ifndef COMPILER_LEXER_H_
#define COMPILER_LEXER_H_

#include "Operator.h"				
#include <iostream>
#include <vector>

namespace Compiler
{
    class Lexer;
    void PrintInputsVector(const Lexer&);
}

class Compiler::Lexer final
{
private:
    std::vector<Compiler::Operator> tokens;
    std::vector<std::string> stringTokens;
    std::string inputsString;
    
    Compiler::Operator GetToken(const std::string&);
    
    Operator TokenProducer(const std::string&);
public:	
    Lexer() = delete;
    explicit Lexer(const std::string&);
    
    class TokenPruducer;
    
    void Init();

    void SplitInputs(const std::string&);
    
    bool IsSpace(const char&);
    
    void GetTokenVector();
    
friend void Compiler::PrintInputsVector(const Compiler::Lexer&);
};
#endif
