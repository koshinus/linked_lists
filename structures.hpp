//
// Created by vadim on 11.04.16.
//
/*
#ifndef LINKED_LISTS_STRUCTURES_HPP
#define LINKED_LISTS_STRUCTURES_HPP

#endif //LINKED_LISTS_STRUCTURES_HPP
*/
#pragma once


template <typename T> class list_elem
{
public:
    list_elem(){};
    ~list_elem(){};
    inline virtual T get_elem() = 0;
    inline virtual void set_elem(T _el)  = 0;
    inline virtual list_elem * get_next() = 0;
    inline virtual void set_next(list_elem *_next) = 0;
    //inline virtual list_elem * get_prev() {};
    //inline virtual void set_prev() {};
};

template <typename T>
class single_list_elem : public list_elem<T>
{
private:
    T el;
    single_list_elem *next;
public:
    single_list_elem(): list_elem<T>::list_elem(), next(nullptr){}
    single_list_elem(T _el): list_elem<T>::list_elem(), el(_el), next(nullptr) {};
    single_list_elem(T _el, single_list_elem *elem): list_elem<T>::list_elem(), el(_el), next(elem) {};
    inline virtual T get_elem() { return el; }
    inline virtual void set_elem(T _el) { el = _el; }
    inline virtual single_list_elem * get_next() { return next; }
    inline virtual void set_next(single_list_elem *_next) { next = _next; }
    //~single_list_elem() { if(next != nullptr) delete next; }
};

template <typename T>
class double_list_elem : public list_elem<T>
{
private:
    T el;
    double_list_elem *next;
    double_list_elem *prev;
public:
    double_list_elem(): next(nullptr), prev(nullptr) {}
    double_list_elem(T _el): list_elem<T>::list_elem(), el(_el), next(nullptr) {};
    double_list_elem(T _el, double_list_elem *elem): list_elem<T>::list_elem(), el(_el), next(elem) {};
    inline virtual T get_elem() { return el; }
    inline virtual void set_elem(T _el) { el = _el; }
    inline virtual double_list_elem * get_next() { return next; }
    inline virtual void set_next(double_list_elem * _prev) { prev = _prev; }
    inline virtual double_list_elem * get_prev() { return prev; }
    inline virtual void set_prev(double_list_elem * _prev) { prev = _prev; }
    /*~double_list_elem()
    {
        if(next != nullptr) delete next;
        if(prev != nullptr) delete prev;
    }*/
};