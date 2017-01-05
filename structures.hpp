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
    virtual T get_elem() = 0;
    virtual void set_elem(T _el)  = 0;
    virtual list_elem * get_next() = 0;
    virtual void set_next(list_elem *_next) = 0;
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
    single_list_elem(T _el, single_list_elem<T> *elem): list_elem<T>::list_elem(), el(_el), next(elem) {};
    single_list_elem(T _el, list_elem<T> *elem): list_elem<T>::list_elem(), el(_el)
                { next = dynamic_cast<single_list_elem<T> *>(elem); };
    virtual T get_elem() { return el; }
    virtual void set_elem(T _el) { el = _el; }
    virtual list_elem<T> * get_next() { return next; }
    virtual void set_next(list_elem<T> *_next) { next = dynamic_cast<single_list_elem<T> *>(_next); }
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
    double_list_elem(T _el, double_list_elem<T> *elem): list_elem<T>::list_elem(), el(_el), next(elem) {};
    double_list_elem(T _el, list_elem<T> *elem): list_elem<T>::list_elem(), el(_el)
                { next = dynamic_cast<double_list_elem<T> *>(elem); };
    virtual T get_elem() { return el; }
    virtual void set_elem(T _el) { el = _el; }
    virtual list_elem<T> * get_next() { return next; }
    virtual void set_next(list_elem<T> * _next) { next = dynamic_cast<double_list_elem<T> *>(_next); }
    virtual double_list_elem<T> * get_prev() { return prev; }
    virtual void set_prev(double_list_elem<T> * _prev) { prev = _prev; }
    /*~double_list_elem()
    {
        if(next != nullptr) delete next;
        if(prev != nullptr) delete prev;
    }*/
};