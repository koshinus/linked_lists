#include "single_linked.hpp"

//
// Created by vadim on 11.04.16.
//
int main()
{
    single_linked<int> l;
    if (l.is_empty()) for (int i = 1; i<5; i++) l.add_elem(i);
    //singleLinkedList <int> ll = rev(l);
    single_linked <int> ll;
    if (ll.is_empty()) for (int i = 4; i<4; i++) ll.add_elem(i);
    l.show();
    std::cout << "\n";
    l.reverse();
    l.show();
    std::cout << "\n";
    l.del_elem();
    l.show();
    std::cout << "\n" << l.size() << "\n";
    l = ll;
    return 0;
}
