A constructor is a special member function of a class that is automatically called when an object is created.
  
Purpose:
Initialize class variables
Allocate resources
Set initial state of the object

Key Properties:
Same name as class
No return type
Automatically invoked

///////////////////////////////
#include <iostream>
using namespace std;

class Car
{
public:
    int speed;

    Car() // constructor
    {
        speed = 100;
        cout << "Constructor called" << endl;
    }
};

int main()
{
    Car c;
    cout << "Speed: " << c.speed << endl;
}


///////////////////////////////  DESTRUCTOR
Destructor :  ~

A destructor is a special function that is automatically called when an object is destroyed.

Purpose:
Free memory
Close files
Release resources
//////////////////////////////////////

#include <iostream>
using namespace std;

class Car
{
public:
    Car()
    {
        cout << "Constructor called" << endl;
    }

    ~Car()
    {
        cout << "Destructor called" << endl;
    }
};

int main()
{
    Car c;
}



///////////////////////TYPES OF CONSTRUCTOR
Types of Constructors
1. Default Constructor - No parameters.
  
class Test
{
public:
    Test()
    {
        cout<<"Default Constructor"<<endl;
    }
};
///////////////////////////
2. Parameterized Constructor - Used to initialize values.

#include <iostream>
using namespace std;

class Rectangle
{
public:
    int length, width;

    Rectangle(int l,int w)
    {
        length = l;
        width = w;
    }

    int area()
    {
        return length*width;
    }
};

int main()
{
    Rectangle r(10,20);
    cout<<r.area();
}

/////////////////////////
3. Copy Constructor - Creates object from another object.

#include <iostream>
using namespace std;

class Test
{
public:
    int x;

    Test(int a)
    {
        x = a;
    }

    Test(const Test &obj)
    {
        x = obj.x;
    }
};

int main()
{
    Test t1(10);
    Test t2 = t1;

    cout<<t2.x;
}

///////////////////////////////////COPY CONSTRUCTOR TYPES
Shallow Copy	- Copies memory addresses
Deep Copy - Copies actual memory data


//////////////////SHALLOW COPY 
Shallow Copy
Default copy constructor performs shallow copy.


#include <iostream>
using namespace std;

class Test
{
public:
    int *ptr;

    Test(int x)
    {
        ptr = new int(x);
    }
};

int main()
{
    Test t1(10);
    Test t2 = t1;

    cout << *t1.ptr << endl;
    cout << *t2.ptr << endl;
}

Problem:
Both objects point to same memory location.

//////////////////SHALLOW COPY 
Deep Copy
Deep copy creates separate memory for each object

#include <iostream>
using namespace std;

class Test
{
public:
    int *ptr;

    Test(int x)
    {
        ptr = new int(x);
    }

    // Copy Constructor
    Test(const Test &obj)
    {
        ptr = new int(*obj.ptr);
    }

    ~Test()
    {
        delete ptr;
    }
};

int main()
{
    Test t1(10);
    Test t2 = t1;

    cout << *t1.ptr << endl;
    cout << *t2.ptr << endl;
}

//////////////////Move Constructor  
Move constructor : 
Moving is faster than copying when objects contain large resources.
Example:
Instead of copying a large image buffer, you transfer ownership.

///////
#include <iostream>
using namespace std;

class Test
{
public:
    int* data;

    Test(int value)
    {
        data = new int(value);
    }

    // Move Constructor
    Test(Test&& obj)
    {
        data = obj.data;
        obj.data = nullptr;
    }

    ~Test()
    {
        delete data;
    }
};

int main()
{
    Test t1(10);

    Test t2 = std::move(t1);
}


/////////////////////IMP///////////
Rule of 3:
If a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely requires all three.

Rule of 5:
Extends Rule of 3 by including move constructor and move assignment for efficient resource transfer.


////////////////////////////
Can Constructors be Virtual?
No
Constructors cannot be virtual.

Reason:
Constructors cannot be virtual because the object is not fully constructed when the constructor runs.


/////////////////////////////////////
Can Destructors be Virtual?
Yes
Destructors should be virtual when using inheritance.

This ensures the derived class destructor runs properly.

//////
#include <iostream>
using namespace std;

class Base
{
public:
    virtual ~Base()
    {
        cout<<"Base Destructor"<<endl;
    }
};

class Derived : public Base
{
public:
    ~Derived()
    {
        cout<<"Derived Destructor"<<endl;
    }
};

int main()
{
    Base* b = new Derived();       //Derived Destructor Base Destructor
    delete b;
}
