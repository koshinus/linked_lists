//
// Created by vadim on 11.04.16.
//
/*
#ifndef LINKED_LISTS_BASE_HPP
#define LINKED_LISTS_BASE_HPP

#endif //LINKED_LISTS_BASE_HPP
*/
#pragma once

#include <stdint-gcc.h>
#include <iostream>
#include "structures.hpp"

template <typename T>
class base_list
{
protected:
    list_elem<T> *top;
    size_t l_size;
    inline void next_elem() { top = top->get_next(); }
public:
    base_list();
    ~base_list() {};
    bool is_empty() const { return top == nullptr && l_size == 0; };
    virtual size_t size() { return l_size; };
    virtual void add_elem(const T &elem) = 0;
    /*{
        list_elem<T> *new_el = new list_elem<T>();
        new_el->set_elem(elem);
        new_el->set_next(top);
        top = new_el;
        size++;
    }*/
    void show()						//выводим список
    {
        if (is_empty())
        {
            std::cout << "[]";
            return;
        }
        list_elem<T> *start = top;
        std::cout << "[";
        while (top != nullptr)
        {
            std::cout << top->get_elem() << ", ";
            next_elem();
        }
        std::cout << "\b\b]";
        top = start;
    }
    virtual void reverse()//разворот списка, колдуем с указателями
    {
        if (is_empty() || l_size == 1) return;
        list_elem<T> *prev_el = top->get_next();
        list_elem<T> *next_el = top;
        top->set_next(nullptr);
        top = prev_el;
        while (prev_el != nullptr)
        {
            prev_el = top->get_next();
            top->set_next(next_el);
            next_el = top;
            top = prev_el;
        }
        top = next_el;
    }
    /*
    void reverse()//разворот списка, колдуем с указателями
    {
        if (size == 0 || size == 1) return;
        list_elem *prev_el = top->next;
        list_elem *next_el = top;
        top->next = NULL;
        top = prev_el;
        while (prev_el != NULL)
        {
            prev_el = top->next;
            top->next = next_el;
            next_el = top;
            top = prev_el;
        }
        top = next_el;
    };*/
    void del_elem()
    {
        switch (l_size)
        {
            case 0:
            {
                std::cout << "List is empty, imposable to delete something!";
                break;
            }
            case 1:
            {
                delete top;
                top = nullptr;
                l_size--;
                break;
            }
            default:
            {
                list_elem<T> *start = top->get_next();
                delete top;
                top = start;
                l_size--;
                break;
            }
        }
    }
    base_list<T> & operator=(base_list<T> &l)
    {
        if (this == &l) return *this;
        while (top != nullptr) del_elem();
        if (l.is_empty()) return *this;
        list_elem<T> *start_l = l.top;
        while (l.top != nullptr)
        {
            add_elem(l.top->get_elem());
            l.next_elem();
        }
        reverse();
        l.top = start_l;
        return *this;
    }
    base_list(base_list &l)
    {
        top = nullptr; l_size = 0;
        list_elem<T> *start_l = l.top;
        while (l.top != nullptr)
        {
            add_elem(l.top->get_elem());
            l.next_elem();
        }
        l.top = start_l;
        reverse();
    }
};