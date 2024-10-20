#include "parser.hpp"
#include "lexer.hpp"
#include <sstream>
#include <iostream>


node* headNode = nullptr;
node* currentNode = nullptr;


int setOpNode(nodeOps ops)
{
    std::cout<<"op node setting"<<std::endl;

    if(currentNode->type != nodeType::nul) return -1;

    currentNode->type = nodeType::op;
    currentNode->val.nodeOperator = ops;

    std::cout<<"set"<<std::endl;
    return 0;
}

int setNumNode(int num)
{
    std::cout<<"setting num"<<std::endl;
    
    if(currentNode->type == nodeType::nul) return -1;
    if(currentNode->left == nullptr)
    {
        currentNode->left = new node();
        currentNode->left->type = nodeType::num;
        currentNode->left->val.nodeValue = num;
        currentNode->left->parent = currentNode;
        std::cout<<"left num set"<<std::endl;
        return 0;
    }
    if(currentNode->right == nullptr)
    {
        currentNode->right = new node();
        currentNode->right->type = nodeType::num;
        currentNode->right->val.nodeValue = num;
        currentNode->right->parent = currentNode;
        std::cout<<"right num set"<<std::endl;
        return 0;
    }
    std::cout<<"Node Full ;("<<std::endl;
    return -1;
}

int traverseUp()
{
    if(currentNode != headNode)
    {
        std::cout<<"traversed up"<<std::endl;
        currentNode = currentNode->parent;
        return 0;
    }
    std::cout<<"already at top"<<std::endl;
    return -1;
}
int addNode()
{
    std::cout<<"Node Created"<<std::endl;
    if(headNode == nullptr)
    {
        std::cout<<"xh"<<std::endl;
        headNode = new node();
        currentNode = headNode;
        return 0;
    }
    if(currentNode->left == nullptr)
    {
        std::cout<<"xl"<<std::endl;
        currentNode->left = new node();
        std::cout<<"xl1"<<std::endl;
        currentNode->left->parent = currentNode;
        std::cout<<"xl2"<<std::endl;
        currentNode = currentNode->left;
        std::cout<<"xl3"<<std::endl;
        return 0;
    }
    if(currentNode->right == nullptr)
    {
        std::cout<<"xr"<<std::endl;
        currentNode->right == new node();
        currentNode->right->parent = currentNode;
        currentNode = currentNode->right;
        return 0;
    }
    else 
    {
        return -1;
    }
}
int executeNode(node* exec)
{
    std::cout<<"execing"<<std::endl;
    if(exec->type != nodeType::op) return -1;

    switch(exec->val.nodeOperator)
    {
        case nodeOps::equal : 
        {
            std::cout<< exec->left->val.nodeValue;
            break;
        }
        case nodeOps::add : 
        {
            exec->val.nodeValue = exec->left->val.nodeValue + exec->right->val.nodeValue;
            exec->type = nodeType::num;
            break;
        }
        case nodeOps::sub : 
        {
            exec->val.nodeValue = exec->left->val.nodeValue - exec->right->val.nodeValue;
            exec->type = nodeType::num;
            break;
        }
        case nodeOps::mul : 
        {
            exec->val.nodeValue = exec->left->val.nodeValue * exec->right->val.nodeValue;
            exec->type = nodeType::num;
            break;
        }
        default : 
        {
            std::cout<<"uh oh"<<std::endl;
            break;
        }

    }

    return 0;
}
int execute(node* exec)
{
    std::cout<<"execute start"<<std::endl;
    if(exec == headNode){
        std::cout<<exec->left->val.nodeValue<<std::endl;
        return 0;
        }
    if(exec->left->type == nodeType::op) 
    {
        std::cout<<"left"<<std::endl;
        execute(exec->left);
    }
    std::cout<<"1"<<std::endl;
    if(exec->right->type == nodeType::op)
    {
        std::cout<<"right"<<std::endl;
        execute(exec->right);
    }
    std::cout<<"2"<<std::endl;
    if(exec->left->type==nodeType::num && exec->right->type==nodeType::num)
    {
        std::cout<<"executing Node!"<<std::endl;
        executeNode(exec);
        if(exec == headNode) {
            std::cout<<"done executing"<<std::endl;
            return 0; 
        }
        execute(exec->parent);
    }
    //std::cout<< "AST error"<<std::endl;
    return 0;
}

int parser(std::string& str)
{
   // init();
    for(std::string::iterator i = str.begin();i!= str.end();i++)
    {
        switch(*i)
        {
            case '(':
            {
                addNode();
                break;
            }

            case ')':
            {
                traverseUp();
                break;
            }
            case '=':
            {
                setOpNode(nodeOps::equal);
                break;
            }
             case '+':
            {
                setOpNode(nodeOps::add);
                break;
            }
             case '-':
            {
                setOpNode(nodeOps::sub);
                break;
            }
             case '*':
            {
                setOpNode(nodeOps::mul);
                break;
            }
             case 'N':
            {//CHECK IF THERE ARE NUMS!
                setNumNode(intArgs.front());
                intArgs.pop();
                break;
            }
            case ' ': break;
            default:{return -1;}
        }
    }
    execute(headNode->left);
    return 0;
}