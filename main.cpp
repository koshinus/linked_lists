#include "single_linked.hpp"

//
// Created by vadim on 11.04.16.
//
int main()
{
    single_linked<int> *l = new single_linked<int>();
    if (l->is_empty()) for (int i = 1; i<5; i++) l->add_elem(i);
    single_linked <int> ll(*l);
    ll.show();
    std::cout << "\n";
    l->reverse();
    l->show();
    std::cout << "\n";
    for(int i = 0; i < 5; i++) l->del_elem();
    l->show();
    std::cout << "\n" << l->size() << "\n";
    *l = ll;
    l->show();
    delete l;
    return 0;
}
