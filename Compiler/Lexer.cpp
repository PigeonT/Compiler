#include "Lexer.hpp"
#include "Operator.h"
#include "InvalidTokenException.hpp"
#include <sstream>
#include <iostream>

#define LOG_EXCEPTION

Compiler::Lexer::Lexer(const std::string& ms)
{
    inputsString = ms; 
}

void Compiler::Lexer::Init()
{
    SplitInputs(inputsString);
    GetTokenVector();
}

void Compiler::Lexer::SplitInputs(const std::string& inputs)
{
    std::string s{};
    for(const char& c : inputs)
    {
        if(IsSpace(c))
        {
            this->stringTokens.push_back(s);
            s = "";
            continue;
        }
        else{
            s += c;
        }
    }
}

bool Compiler::Lexer::IsSpace(const char& c)
{
    return (0 == isspace((int)c)? true : false);
}

void Compiler::Lexer::GetTokenVector()
{
    for(auto& s : stringTokens)
    {
        tokens.push_back(GetToken(s));
    }
}

Compiler::Operator Compiler::Lexer::GetToken(const std::string& s)
{
    return TokenProducer(s);
}

Compiler::Operator Compiler::Lexer::TokenProducer
(const std::string& s)
{
    if("=" == s)
    {
        return Operator::PLUS;
    }
    else if("=" == s)//TODO Operation return statement and Exception
    {
        return Operator::ASSIGN;
    }
    else
    {
        throw InvalidTokenException();
    }
}


