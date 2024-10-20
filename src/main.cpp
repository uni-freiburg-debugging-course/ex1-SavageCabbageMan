#include "parser.hpp"
#include "lexer.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char* argv[])
{
    std::string input;
    std::getline(std::cin,input);
    lex(input);
    parser(input);
}