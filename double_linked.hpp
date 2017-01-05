//
// Created by vadim on 11.04.16.
//
/*
#ifndef LINKED_LISTS_DOUBLE_LINKED_HPP
#define LINKED_LISTS_DOUBLE_LINKED_HPP

#endif //LINKED_LISTS_DOUBLE_LINKED_HPP
*/
#pragma once

#include "base.hpp"

template <typename T>
class double_linked : base_list<T>
{
protected:
    inline void prev_elem() { top = top->get_prev();};
public:
    //virtual inline size_t list_size() { return size; }
    double_linked(): base_list<T>()//: base_list<T>::base_list() {};
    {
        base_list<T>::top = new double_list_elem<T>();
    }
    virtual void add_elem(const T &elem)
    {
        double_list_elem<T> *new_el = new double_list_elem<T>(elem, top);
        if(is_empty()) new_el->set_prev(new_el);
        //if (is_empty()) new_el->prev = new_el;//случай, когда список изначально пуст
        else
        {
            new_el->set_prev(top->get_prev());
            top->set_prev(new_el);
            //new_el->prev = top->prev;
            //top->prev = new_el;
        }
        //list_elem<T> *new_el = new single_list_elem<T>(elem, top);
        top = new_el;
        l_size++;
    }
    virtual void reverse()
    {
        if(is_empty() || l_size == 1) return;
        top->set_prev(top->get_next());
        top->set_next(nullptr);
        double_list_elem<T> *start = top;
        double_list_elem<T> *cur_elem;
        prev_elem();
        while (top->get_next() != nullptr)
        {
            cur_elem = top->get_next();
            top->set_next(top->get_prev());
            top->set_prev(cur_elem);
            prev_elem();
        }
        top->set_next(top->get_prev());
        top->set_prev(start);
    }
    /*
    void reverse()//разворот списка, колдуем с указателями
    {
        if (size == 0 || size == 1) return;
        top->prev = top->next;
        top->next = NULL;
        list_elem *start = top;
        list_elem *cur_elem;
        prev_elem();
        while (top->next != NULL)
        {
            cur_elem = top->next;
            top->next = top->prev;
            top->prev = cur_elem;
            prev_elem();
        }
        top->next = top->prev;
        top->prev = start;
    };*/
    ~double_linked()
    {
        list_elem<T> *cur_el;// = base_list<T>::top;
        while (top != nullptr)
        {
            cur_el = top->get_next();
            delete top;
            top = cur_el;
            //std::cout << "deleted\n";
        }
    }
};