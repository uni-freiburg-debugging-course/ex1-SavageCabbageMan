#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <queue>
#include "structs.hpp"

extern std::queue<int> intArgs;
std::string lex(std::string& str);
#endif