#include "lexer.hpp"
#include <iostream>




std::queue<int> intArgs;

int replaceInts(std::string& str)
{
    char const* digits = "0123456789";
    size_t n,m;
    n = str.find_first_of(digits);
    if(n != std::string::npos)
    {
        m = str.find_first_not_of(digits,n);
        int num = atoi(str.substr(n,m-n).c_str());
        intArgs.push(num);
        str.replace(n,m-n,"N");
        replaceInts(str);
    }
    return 0;
}
std::string lex(std::string& str)
{
    //Replace simplfiy with =
    size_t ret,ret1;
    ret = str.find("simplify");
    if(ret == std::string::npos) return NULL; //error

    str.replace(ret,8,"=");

    replaceInts(str);
    std::cout<<str;
    //ADD REMOVE SPACES!
    return str;
}