
#include "inc/LinkedList.hpp"

int main()
{
    LinkedList *list = new LinkedList();
    
    int a = 5;
    int b = 10;
    int c = 15;

    list->addNode(&a);
    list->addNode(&b);
    list->printList();

    list->addNode(&c);
    list->printList();

    delete list;

    return 0;
}