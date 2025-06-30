#include <iostream>
#include "list/list.h"
#include "stack/stack.h"

int main()
{
    std::cout << "Hello Mac" << std::endl;

    /*
    list my_list = list();

    my_list.push_back(1);
    my_list.push_front(2);
    my_list.push_back(3);

    std::cout << "back: " << my_list.back() << "\r\n";
    std::cout << "front: " << my_list.front() << "\r\n";
    my_list.pop();
    std::cout << "pop\r\n";
    std::cout << "back: " << my_list.back() << "\r\n";

    list my_list2 = list();
    my_list2.push_back(1);
    my_list2.push_back(2);
    my_list2.push_back(3);

    std::cout << "[0]: " <<  my_list2[0] << "\r\n";
    std::cout << "[1]: " <<  my_list2[1] << "\r\n";
    std::cout << "[2]: " <<  my_list2[2] << std::endl;
    //*/

    stack my_stack = stack(10);

    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    my_stack.push(4);
    
    std::cout << my_stack.pop() << std::endl;
    std::cout << my_stack.peek() << std::endl; // flush 이슈
    std::cout << my_stack.pop() << std::endl;
    my_stack.push(154);
    std::cout << my_stack.pop() << std::endl;
    std::cout << my_stack.pop() << std::endl;
    std::cout << my_stack.pop() << std::endl;

    return 0;
}