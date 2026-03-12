Threads: 
A template allows you to write generic code that works with different data types without rewriting the same logic.
Instead of writing separate functions for int, float, double, etc., you write one template.
Think of it as a blueprint for functions or classes.

Without tempplate :
int add(int a, int b);
float add(float a, float b);
double add(double a, double b);

When to Use Templates?
Use templates when:
The same logic works for multiple data types
You want generic programming
You want type-safe reusable code

Examples:
Sorting algorithms
Containers (vector, stack, map)
Mathematical operations
The entire STL library in C++ is built using templates

//==============================================================same type params 
#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(5,10) << endl;
    cout << add(5.5,2.5) << endl;

    return 0;
}

//==============================================================diff type params
#include<iostream>
using namespace std;

template <typename T, typename U>
void add( T a, U b)
{
    cout <<"sum : "<< (a+b)<< endl;
    
}
int main()
{
    add(10, 10.1);
    add(1.2, 2);

    return 0;
}


//==============================================================class using template

#include <iostream>
using namespace std;

template <class T>
class Box
{
public:
    T value;

    Box(T v)
    {
        value = v;
    }

    void display()
    {
        cout << "Value: " << value << endl;
    }
};

int main()
{
    Box<int> b1(10);
    Box<double> b2(5.5);

    b1.display();
    b2.display();

    return 0;
}


////////////Max num

#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b)
{
    if(a > b)
        return a;
    else
        return b;
}

int main()
{
    cout << maximum(10,20) << endl;
    cout << maximum(4.5,2.1) << endl;

    return 0;
}
