#include "Lexer.hpp"
namespace Compiler
{
void PrintInputsVector(const Lexer& lexer)
{
    for(auto s : lexer.inputsString)
    {
        std::cout << s << std::endl;
    }
}
}

int main(int argc, char *argv[])
{
    std::string mStrings;
    std::getline(std::cin, mStrings);
    Compiler::Lexer lexer{mStrings};
    lexer.Init();
    PrintInputsVector(lexer);}

