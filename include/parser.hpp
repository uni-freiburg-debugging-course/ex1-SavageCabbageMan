
#ifndef PARSER_HPP
#define PARSER_HPP

#include "structs.hpp"
#include <string>


extern node* currentNode;
extern node* headNode;
int parser(std::string& str);

//int execute(node* head);

#endif