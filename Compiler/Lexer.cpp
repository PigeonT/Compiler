#include "Lexer.hpp"
#include <sstream>
#include <iostream>

Lexer::Lexer() = default;

void Lexer::SplitInputs(const std::string& inputs)
{
    std::string s{};
    for(const char& c : inputs)
    {
        if(IsSpace(c))
        {
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

Operator Lexer::GetToken(const char& c)
{
    return Operator::MINUS;
}
