// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
#include <any>
#include "TypeManager.h"

class Node
{
    using OrderFunc = std::function<int(std::vector<Node>, Node&&)>;
    std::any element;
    std::vector<Node> links;
    Node(std::any element)
    {

        std::string typeName = element.type().name();
        if (typeName.find("char") != std::string::npos) {
            std::cout << "Type is a string" << std::endl;
            char* s = std::any_cast<char*>(element);
            std::string str = s;
            this->element = str;
        } 
        else
            this->element = element;
    }

    class Builder
    {
        Node& node;
        OrderFunc order;
    public:
        Builder(Node&& node, OrderFunc func) : node(node), order(func)
        {
        }

        Builder& addLink(std::any element)
        {
            return *this;
        }

        Node& build()
        {
            return node;
        }
    };
public:
    Node(Node& other): element(other.element), links(other.links)
    {
        std::cout << "Copying Node" << std::endl;
    }
    static Builder builder(std::any element)
    {
        
        return Builder(Node(element), [](std::vector<Node> links, Node&& node) { return 0; });
    }

    std::string toString()
    {
        return element.type().name();
    }
};

template<typename T>
void print(T t)
{
    const type_info* tid = &typeid(t);
    std::cout << tid->name() << ":" <<
        tid->raw_name() << "[" <<
        tid->hash_code() << "]" << std::endl;
}

int main()
{
    /*Node& test = Node::builder("Just a test").addLink("Hello World").build();
    std::cout << test.toString();*/
    TypeManager manager = *type_manager;
    Type t = manager.getTypeByName("INT");
    std::cout << typeid(TypeManager).name() << std::endl;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
