#include "Lexer.hpp"

int main(int argc, char *argv[])
{
    Lexer lexer;
    std::string mStrings;
    std::getline(std::cin, mStrings);
    lexer.getInputs(mStrings);
}
