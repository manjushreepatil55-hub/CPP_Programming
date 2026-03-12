Smart pointers are modern C++ tools 
used to manage dynamic memory safely. They are part of the Standard Template Library (STL) and are defined in the <memory> header.
They automatically delete allocated memory when it is no longer needed, preventing memory leaks.

why smart pointer ? 

example :
int* ptr = new int(10);
delete ptr;

Problems:
If delete is forgotten → memory leak
If delete called twice → program crash
Exception occurs before delete → memory leak

Smart pointers solve this by using RAII (Resource Acquisition Is Initialization).
i.e : Resource allocated → automatically freed when object goes out of scope


//////////////////////////////////////
When to Use Smart Pointers

Use smart pointers when:
Managing dynamic memory
Handling ownership of objects
Avoiding manual delete
Preventing memory leaks

Example in systems like camera processing:
CameraFrame → dynamically allocated
Smart pointer ensures automatic cleanup


///////////////TYPES///////////
Types of Smart Pointers
C++ provides three main smart pointers.

1. unique_ptr -	Single owner
2. shared_ptr	- Multiple owners
3. weak_ptr	- Non owning reference


///////////////UNIQUE_PTR
unique_ptr

Only one pointer can own the object.
Cannot be copied.
Ownership can only be moved.

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    unique_ptr<int> p1 = make_unique<int>(20);

    unique_ptr<int> p2 = move(p1); /// after move p1 will be nullptr

    cout << *p2 << endl; //20
}

///////////////SHARED_PTR
shared_ptr

Multiple pointers can share ownership of the same object.
Uses reference counting.
Memory deleted when reference count becomes zero.

#include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> p1 = make_shared<int>(50);

    shared_ptr<int> p2 = p1;

    cout << *p1 << endl;  //50
    cout << "Reference count: " << p1.use_count() << endl; //2
}

/////////////////WEAK_PTR
weak_ptr is used with shared_ptr.

It does not increase reference count.
Used to avoid circular dependency problems.

  #include <iostream>
#include <memory>

using namespace std;

int main()
{
    shared_ptr<int> p1 = make_shared<int>(100);

    weak_ptr<int> w1 = p1;

    cout << "Reference count: " << p1.use_count() << endl; //1

    if(auto temp = w1.lock())
        cout << *temp << endl;   //100
}




//////////////IMP
What is Circular Dependency?

When two objects hold shared_ptr to each other, their reference count never becomes zero.
So memory never gets deleted.

Example :
  
Person A ----shared_ptr----> Person B
Person B ----shared_ptr----> Person A

Ref count A = 1
Ref count B = 1


#include <iostream>
#include <memory>

using namespace std;

class B; // forward declaration

class A
{
public:
    shared_ptr<B> ptrB;

    ~A()
    {
        cout << "A Destructor called" << endl;
    }
};

class B
{
public:
    shared_ptr<A> ptrA;

    ~B()
    {
        cout << "B Destructor called" << endl;
    }
};

int main()
{
    shared_ptr<A> objA = make_shared<A>();
    shared_ptr<B> objB = make_shared<B>();

    objA->ptrB = objB;
    objB->ptrA = objA;

    return 0;
}

here both class objets are pointing to shared data ref count will be same 
/////////////////////////////////////////////
solution : weak_ptr 

#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
public:
    shared_ptr<B> ptrB;

    ~A()
    {
        cout << "A Destructor called" << endl;
    }
};

class B
{
public:
    weak_ptr<A> ptrA;   // weak_ptr used

    ~B()
    {
        cout << "B Destructor called" << endl;
    }
};

int main()
{
    shared_ptr<A> objA = make_shared<A>(); //make_shared is better than shared_ptr<A> objA(new A()); as it is safe creates memory for particullar variable(Single Memory Allocation)
    shared_ptr<B> objB = make_shared<B>();

    objA->ptrB = objB;
    objB->ptrA = objA;

    return 0;
}

  weak_ptr will not increase the ref count
