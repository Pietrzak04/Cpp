#include <iostream>
#include "MyList.h"

int main()
{
    MyList<int> list(5);

    list.pushBack(45);
    list.pushBack(23);
    list.pushFront(81);
    list.pushFront(28);
    list.pushFront(88);


    list.printList();

    std::cout << "usuwanie\n";

    list.insert(4, 24);
    list.remove(2);


    list.printList();


}
