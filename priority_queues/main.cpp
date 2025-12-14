#include <iostream>

using namespace std;

class PriorityQueue
{
    int *heap;
    int sz;
    int cap;

    void swap(int &a,int &b)
    {
        int t = a;
        a = b;
        b = t;
    }

    void heapifyUp(int i)
    {
        while(i > 0)
        {
            int p = (i - 1) / 2;
            if(heap[p] < heap[i])
            {
                swap(heap[p], heap[i]);
                i = p;
            }
            else break;
        }
    }

    void heapifyDown(int i)
    {
        while(true)
        {
            int l = 2*i + 1;
            int r = 2*i + 2;
            int m = i;

            if(l < sz && heap[l] > heap[m]) m = l;
            if(r < sz && heap[r] > heap[m]) m = r;

            if(m != i)
            {
                swap(heap[i], heap[m]);
                i = m;
            }
            else break;
        }
    }

public:
    PriorityQueue()
    {
        cap = 8;
        sz = 0;
        heap = new int[cap];
    }

    PriorityQueue(const PriorityQueue& other)
    {
        sz = other.sz;
        cap = other.cap;
        heap = new int[cap];
        for(int i = 0;i < sz;i++)
            heap[i] = other.heap[i];
    }

    PriorityQueue& operator=(const PriorityQueue& other)
    {
        if(this == &other) return *this;

        delete[] heap;
        sz = other.sz;
        cap = other.cap;
        heap = new int[cap];
        for(int i = 0;i < sz;i++)
            heap[i] = other.heap[i];

        return *this;
    }

    void push(int value)
    {
        if(sz == cap)
        {
            cap *= 2;
            int *n = new int[cap];
            for(int i = 0;i < sz;i++)
                n[i] = heap[i];
            delete[] heap;
            heap = n;
        }
        heap[sz] = value;
        heapifyUp(sz);
        sz++;
    }

    int top(){ return heap[0]; }

    void pop()
    {
        if(sz == 0) return;
        heap[0] = heap[--sz];
        heapifyDown(0);
    }

    bool empty(){ return sz == 0; }

    ~PriorityQueue()
    {
        delete[] heap;
    }
};

int main()
{
    PriorityQueue a;
    a.push(15);
    a.push(5);
    a.push(30);

    PriorityQueue b = a;
    PriorityQueue c;
    c = a;

    while(!b.empty())
    {
        cout << b.top() << " ";
        b.pop();
    }

    cout << endl;
    return 0;
}