#include "Lexer.hpp"
#include "InvalidTokenException.hpp"
#include <ctime>

#define EXCEPTION_HANDLING(ex) \
auto now = time(0);\
auto ct = ctime(&now);\
std::cerr << ct << ": " << iex.what() << std::endl;


namespace Compiler
{
void PrintInputsVector(const Lexer& lexer)
{
    for(auto s : lexer.stringTokens)
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
    try
    {
        lexer.Init();
        PrintInputsVector(lexer);
    }
    catch(Compiler::InvalidTokenException& iex)
    {
        EXCEPTION_HANDLING(iex);
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

