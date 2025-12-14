#include <iostream>

using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
    };

    Node *head;

    void copyFrom(const LinkedList& other)
    {
        head = nullptr;
        Node *cur = other.head;
        while(cur)
        {
            push_back(cur->data);
            cur = cur->next;
        }
    }

    void clear()
    {
        Node *cur = head;
        while(cur)
        {
            Node *tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head = nullptr;
    }

public:
    LinkedList()
    {
        head = nullptr;
    }

    LinkedList(const LinkedList& other)
    {
        copyFrom(other);
    }

    LinkedList& operator=(const LinkedList& other)
    {
        if(this == &other) return *this;
        clear();
        copyFrom(other);
        return *this;
    }

    void push_front(int value)
    {
        Node *n = new Node;
        n->data = value;
        n->next = head;
        head = n;
    }

    void push_back(int value)
    {
        Node *n = new Node;
        n->data = value;
        n->next = nullptr;

        if(!head)
        {
            head = n;
            return;
        }

        Node *cur = head;
        while(cur->next)
            cur = cur->next;

        cur->next = n;
    }

    void print()
    {
        Node *cur = head;
        while(cur)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    ~LinkedList()
    {
        clear();
    }
};

int main()
{
    LinkedList a;
    a.push_back(10);
    a.push_back(20);

    LinkedList b = a;
    LinkedList c;
    c = a;

    b.print();
    c.print();
    return 0;
}