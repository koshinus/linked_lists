//
// Created by vadim on 11.04.16.
//
/*
#ifndef LINKED_LISTS_SINGLE_LINKED_HPP
#define LINKED_LISTS_SINGLE_LINKED_HPP

#endif //LINKED_LISTS_SINGLE_LINKED_HPP
*/
#pragma once

#include "base.hpp"

template <typename T>
class single_linked : public base_list<T>
{
public:
    //virtual inline size_t list_size() { return base_list<T>::size; }
    single_linked(): base_list<T>()//: base_list<T>::base_list(), dynamic_cast<double_list_elem<T> *>(top)// {};
    {
        //base_list<T>::top = dynamic_cast<single_list_elem<T> *>(base_list<T>::top);//new single_list_elem<T>();
        base_list<T>::top = nullptr;
    }
    virtual void add_elem(const T &elem)
    {
        //list_elem<T> *new_el = new single_list_elem<T>();
        //new_el->set_elem(elem);
        list_elem<T> *new_el = new single_list_elem<T>(elem, base_list<T>::top);
        //new_el->set_next(base_list<T>::top);
        base_list<T>::top = new_el;
        base_list<T>::l_size++;
    };

    single_linked(base_list<T> &l)
    {
        base_list<T>::top = nullptr;
        base_list<T>::l_size = 0;
        list_elem<T> *start_l = l.top;
        while (l.top != nullptr)
        {
            add_elem(l.top->get_elem());
            l.next_elem();
        }
        l.top = start_l;
        base_list<T>::reverse();
    }

    single_linked(base_list<T> *l)
    {
        base_list<T>::top = nullptr;
        base_list<T>::l_size = 0;
        list_elem<T> *start_l = l->get_top();
        list_elem<T> *l_top = start_l;
        while (l_top != nullptr)
        {
            add_elem(l_top->get_elem());
            l_top = l_top->get_next();
            //add_elem(l->get_top()->get_elem());
            //l->set_top(l->get_top()->get_next());//next_elem();
        }
        l->set_top(start_l);
        base_list<T>::reverse();
    }

    ~single_linked()
    {
        list_elem<T> *cur_el = base_list<T>::top;
        while (cur_el != nullptr)
        {
            cur_el = base_list<T>::top->get_next();
            std::cout << cur_el->get_next() << std::endl;
            delete base_list<T>::top;
            base_list<T>::top = cur_el;
            //std::cout << base_list<T>::top << std::endl;
            //std::cout << "deleted\n";
        }
    }
};