#include "Lexer.hpp"
#include "Operator.h"
#include <sstream>
#include <iostream>

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
    auto token = TokenProducer(s);
    return token;
}

Compiler::Operator Compiler::Lexer::TokenProducer
(const std::string& s)
{
    if("=" == s)
    {
        return Operator::PLUS;
    }
    else//TODO Operation return statement and Exception
    {
        return Operator::MINUS;
    }
}


