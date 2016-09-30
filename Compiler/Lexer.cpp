#include "Lexer.hpp"
#include <sstream>
#include <iostream>

Lexer::Lexer() = default;

Lexer::Lexer(const std::string& ms)
{
    inputsString = ms; 
}

void Lexer::Init()
{
    SplitInputs(inputsString);
    //GetTokenVector();
}

void Lexer::SplitInputs(const std::string& inputs)
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

bool Lexer::IsSpace(const char& c)
{
    return (0 == isspace((int)c)? true : false);
}

void Lexer::GetTokenVector()
{
    for(const string& s : inputsString)
    {
        GetToken(s);
    }
}

Operator Lexer::GetToken(const string& s)
{
    return Operator::MINUS;
}
