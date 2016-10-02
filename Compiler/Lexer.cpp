#include "Lexer.hpp"
#include "Operator.h"
#include "InvalidTokenException.hpp"
#include "Utils.hpp"
#include <sstream>
#include <iostream>

Compiler::Lexer::Lexer(const std::string& ms)
{
    inputsString = ms; 
}

void
Compiler::Lexer::Init()
{
    SplitInputs(inputsString);
    //GetTokenVector();
}

void
Compiler::Lexer::SplitInputs(const std::string& inputs)
{
    std::string s{};
    std::string _inputs = const_cast<std::string&>(inputs);
    _inputs = Compiler::trim(_inputs);
    
    
    std::string::iterator new_end = std::unique(_inputs.begin(), _inputs.end(), Compiler::BothAreSpaces);
    _inputs.erase(new_end, _inputs.end());
    
    //_inputs.erase(remove_if(_inputs.begin(), _inputs.end(), isspace), _inputs.end());
    for(const char& c : _inputs)
    {

        if(IsSpace(c) || '\n' == c)
        {
            stringTokens.push_back(s);
            s.clear();
            continue;
        }
        else
        {
            s += c;
        }
    }
    stringTokens.push_back(s);
}

bool
Compiler::Lexer::IsSpace(const char c)
{
    return isspace(c);
}

void
Compiler::Lexer::GetTokenVector()
{
    for(auto& s : stringTokens)
    {
        tokens.push_back(GetToken(s));
    }
}

Compiler::Operator
Compiler::Lexer::GetToken(const std::string& s)
{
    return TokenProducer(s);
}

Compiler::Operator Compiler::Lexer::TokenProducer
(const std::string& s)
{
    if("+" == s)
    {
        return Operator::PLUS;
    }
    else if("-" == s)
    {
        return Operator::MINUS;
    }
    else if("*" == s)
    {
        return Operator::MULTIPLY;
    }
    else if("/" == s)
    {
        return Operator::DIVISION;
    }
    else if("1" == s)
    {
        return Operator::NUMBER;
    }
    else if("(" == s)
    {
        return Operator::LEFT_PARENT;
    }
    else if(")" == s)
    {
        return Operator::RIGHT_PARENT;
    }
    else if("i" == s)
    {
        return Operator::IDENTIFIER;
    }
    else
    {
        throw InvalidTokenException();
    }
}


