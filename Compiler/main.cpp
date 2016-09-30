#include "Lexer.hpp"
namespace
{
void PrintInputsVector(Lexer& lexer)
{
    for(auto s : inputsString)
    {
        std::cout << s << std::endl;
    }
}
}

int main(int argc, char *argv[])
{
    std::string mStrings;
    std::getline(std::cin, mStrings);
    Lexer lexer{mStrings};
    lexer.Init();
}

