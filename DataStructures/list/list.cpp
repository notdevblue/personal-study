#include "list.h"
#include <iostream>

list::list() : _front(nullptr), _back(nullptr)
{
}

list::~list()
{
    while (_back != nullptr)
    {
        pop();
    }
}

void list::push_front(const int &element)
{
    list_element *new_front = new list_element(element, _front, nullptr);
    if (_front != nullptr)
    {
        _front->set_prev(new_front);
    }
    _front = new_front;
    if (_back == nullptr)
    {
        _back = _front;
    }
}

void list::push_back(const int &element)
{
    list_element *new_back = new list_element(element, nullptr, _back);
    if (_back != nullptr)
    {
        _back->set_next(new_back);
    }
    _back = new_back;
    if (_front == nullptr)
    {
        _front = _back;
    }
}

const int& list::front() const
{
    return _front->get_element();
}

const int& list::back() const
{
    return _back->get_element();
}

void list::pop()
{
    if (_back == nullptr)
    {
        return;
    }
    else
    {
        list_element* new_back = _back->get_prev();
        if (new_back == nullptr)
        {
            delete (_back);
            _back = nullptr;
        }
        else
        {
            new_back->set_next(nullptr);
            delete (_back);
            _back = new_back;
        }
    }
}

const int& list::operator[](const int& index) const
{
    list_element* target = _front;

    for (int i = 0; i < index; ++i)
    {
        target = target->get_next();
    }

    return target->get_element();
}