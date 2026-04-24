/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

class Deep{
    int *data;
    
    public:
    Deep(int val){
         cout<<"constructor"<<endl;
        data = new int (val);
    }
    Deep(const Deep& val){
        cout<<"DeepCopy"<<endl;
        data = new int (*val.data);
    }
    Deep& operator = (const Deep& val){
        cout<<"Copy Assign"<<endl;
        if(this!=&val)
        {
            delete data ;
            data = new int (*val.data);
        }
        return *this;
    }
    
    Deep(Deep&& val){
        cout<<"MoveCopy"<<endl;
        data = val.data;
        val.data=nullptr;
    }
    Deep& operator = (Deep&& val){
        cout<<"move Assign"<<endl;
        if(this!=&val)
        {
            delete data ;
            data = val.data;
            val.data=nullptr;
        }
        return *this;
    }
    void show()
    {
        if (data)
            cout << *data << endl;
        else
            cout << "null" << endl;
    }
    ~Deep(){
         cout<<"Destructor"<<endl;
         delete data;
         data = nullptr;
    }
};

int main()
{
    
    Deep d1(10);

    Deep d2 = d1;        // Copy constructor

    Deep d3(20);
    d3 = d1;             // Copy assignment


    Deep d4 = std::move(d1); // Move constructor

    Deep d5(30);
    d5 = std::move(d2);      // Move assignment

    d1.show();
    d2.show();
    d3.show();
    d4.show();
    d5.show();
    

    return 0;
}
