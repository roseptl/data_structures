#include <iostream>

using namespace std;

class DynamicArray
{
    int *data;
    int sz;
    int cap;

public:
    class Iterator
    {
        int *ptr;
    public:
        Iterator(int *p){ ptr = p; }
        int& operator*(){ return *ptr; }
        Iterator& operator++(){ ptr++; return *this; }
        bool operator!=(const Iterator& other){ return ptr != other.ptr; }
    };

    DynamicArray()
    {
        cap = 2;
        sz = 0;
        data = new int[cap];
    }

    DynamicArray(const DynamicArray& other)
    {
        sz = other.sz;
        cap = other.cap;
        data = new int[cap];
        for(int i = 0;i < sz;i++)
            data[i] = other.data[i];
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if(this == &other) return *this;

        delete[] data;
        sz = other.sz;
        cap = other.cap;
        data = new int[cap];
        for(int i = 0;i < sz;i++)
            data[i] = other.data[i];

        return *this;
    }

    void push_back(int value)
    {
        if(sz == cap)
        {
            cap = cap * 2;
            int *newData = new int[cap];
            for(int i = 0;i < sz;i++)
                newData[i] = data[i];
            delete[] data;
            data = newData;
        }
        data[sz++] = value;
    }

    Iterator begin(){ return Iterator(data); }
    Iterator end(){ return Iterator(data + sz); }

    ~DynamicArray()
    {
        delete[] data;
    }
};

int main()
{
    DynamicArray a;
    a.push_back(10);
    a.push_back(20);

    DynamicArray b = a;
    DynamicArray c;
    c = a;

    for(auto it = b.begin(); it != b.end(); ++it)
        cout << *it << " ";

    cout << endl;
    return 0;
}