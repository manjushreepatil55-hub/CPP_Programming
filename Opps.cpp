#include<iostream>
#include<string>
using namespace std;
//C++ OPPs

//class :  class is extend version of structure, which holds both member variables and functions together 
class St
{
int Id;
string name ;

public:
void PrintDetails(int i, string s)
{
  Id= i;
  name = s;
  cout << "ID : "<< Id<<"name : "<< s << endl;
}
};

int main(){
  St s;
s.PrintDetails(10, "Manju");
 return 0;
}

//OOPS: 
//1.Encapsulation : binding data and functions into single entity
class Vehicle
{
int year;
string brand ;

public:
void PrintDetails(int i, string s)
{
  year= i;
  brand = s;
  cout << "ID : "<< Id<<"name : "<< s << endl;
}
};

int main(){
  Vehicle V;
V.PrintDetails(2000, "BMW");
 return 0;
}

//2.Abstraction :  showing/represting only essential features without including any background details 
//* Abstract class will hold pure virtual function , which can be updated/override in dervied classes 

// Abstract class
class Vehicle
{
int year;
string brand ;

public:
// Pure virtual function
    virtual void start() = 0;
};

// Derived class
class Car : public Vehicle
{
void start()
{
cout << "Car starts with key ignition" << endl;
}

};

// Another derived class
class Bike : public Vehicle
{
public:
    void start()
    {
        cout << "Bike starts with self start" << endl;
    }
};

int main()
{
    Vehicle* v1;
    Car c;
    Bike b;

    v1 = &c;
    v1->start();

    v1 = &b;
    v1->start();

    return 0;
}
//3.Polymorphism : data or message to be prossed in more than one form (many forms)

// 1. compile time polymorphism and 2. run time 
/*1. compile time : Function overloading , Operator overloading , Templates
  this happens when compiler decides which function to be called */

//Function Overloading :

#include <iostream>
using namespace std;

class Vehicle
{
public:
    void start()
    {
        cout << "Vehicle starts normally" << endl;
    }

    void start(string keyType)
    {
        cout << "Vehicle starts using " << keyType << endl;
    }
};

int main()
{
    Vehicle v;

    v.start();
    v.start("Smart Key");

    return 0;
}

// Operator Overloading : 
//Suppose we want to add two complex numbers.

#include<iostream>
#include<string>
using namespace std;
class complex{
public :
    
int r;
int i;

complex(int x, int y){
  r = x;
  i = y; 
}

complex operator + (complex obj)
{
  complex temp(0,0);
  temp.r = r + obj.r;
  temp.i = i + obj.i;
  return temp;
}
};
int main()
{
complex c1(2, 3);
complex c2(4, 5);
complex c3= c1+c2;

cout << c3.r<< " " << c3.i << endl;
return 0;
}



//2. Run time : Function overriding (Virtual function like abstract class )
//this happens during runtime by calling virtual functions 

#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual void start()
    {
        cout << "Vehicle starts" << endl;
    }
};

class Car : public Vehicle
{
public:
    void start() override
    {
        cout << "Car starts with key ignition" << endl;
    }
};

class Bike : public Vehicle
{
public:
    void start() override
    {
        cout << "Bike starts with self start" << endl;
    }
};

int main()
{
    Vehicle* v;

    Car c;
    Bike b;

    v = &c;
    v->start();

    v = &b;
    v->start();

    return 0;
}

//Inheritance : 
//capability of one class to inherit the properties of another class
//protected and public members of base class becomes protected members of derived class

class A{
int a ; 
int b;
};

class B : public A{

int c;
int d;
};


//example : 

#include<iostream>
using namespace std;

class shape {
protected:
    int width, length;

public:
    void setValues(int a, int b)
    {
        width = a;
        length = b;
    }
};

class rectangle : public shape {
public:
    int area()
    {
        return width * length;
    }
};

class triangle : public shape {
public:
    int area()
    {
        return (width * length) / 2;
    }
};

int main()
{
    rectangle r;
    r.setValues(10,20);
    cout << "Rectangle area: " << r.area() << endl;

    triangle t;
    t.setValues(10,20);
    cout << "Triangle area: " << t.area() << endl;

    return 0;
}

  








  
