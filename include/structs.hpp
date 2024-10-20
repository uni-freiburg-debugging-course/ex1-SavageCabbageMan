
#ifndef STRUCT_HPP
#define STRUCT_HPP
enum class nodeType
{
    op,
    num,
    nul
};

enum class nodeOps
{
    equal,
    add,
    sub,
    mul,
    nul
};

struct node
{
    node* parent;
    node* left;
    node* right;
    nodeType type;
    union
    {
        int nodeValue;
        nodeOps nodeOperator;
    }val;

    node()
    {
        parent = nullptr;
        left = nullptr;
        right = nullptr;
        type = nodeType::nul;
    }

};

#endif