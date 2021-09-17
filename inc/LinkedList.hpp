
#include <iostream>

typedef struct  s_list
{
    void          *value;
    struct s_list *next;
}               t_list;

class LinkedList
{
private:
    t_list *_head;
    t_list *_tail;
    //can add size and everything you want

public:
    LinkedList() : _head(nullptr), _tail(nullptr) { }
    ~LinkedList()
    {
        t_list *current = _head;
        t_list *next = _head;
        
        while (current)
        {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void    addNode(void *val)
    {
        //create a new node
        t_list *node = new t_list();
        //assign the calue to it
        node->value = val;
        node->next = nullptr;
        //add the node to the end of the list
            //bad example: _head->next = node;
        if (_tail)
        {
            _tail->next = node;
            _tail = _tail->next;
        }
        else
        {
            _head = node;
            _tail = node;
        }
    }

    void printList(void)
    {
        t_list *node = _head;

        while (node)
        {
            std::cout << node->value << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }

    t_list *getHead(void)
    {
        return _head;
    }

    t_list *getTail(void)
    {
        return _tail;
    }
};

//proof print node
//add/print
//desrtructor
//fillit
//-> means stored inside as a pointer
    //stored as value instead of pointer
//new always paired with del
//rule of thumb: every new you call, a delete should be called
//&&  means connecting two commands together