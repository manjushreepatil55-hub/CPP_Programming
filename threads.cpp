#include<threads>
Threads : A thread is the smallest unit of execution inside a process.
Normally a program runs sequentially: Task1 → Task2 → Task3

With threads:
Task1
Task2   (run simultaneously)
Task3

///////////////WHY?
Why Use Threads?
Threads are used to improve performance and responsiveness.

Reasons:
Parallel processing
Better CPU utilization
Faster execution
Background processing

///////////////syntax
thread t(function_name);
t.join();

////////////////?Single thred 
#include <iostream>
#include <thread>
using namespace std;

void display()
{
    cout << "Thread is running" << endl;
}
int main()
{
    thread t1(display);
    t1.join();
    return 0;
}



///////////////////multiple thread
#include <iostream>
#include <thread>
using namespace std;

void task1()
{
    for(int i=0;i<5;i++)
        cout<<"Task1 running"<<endl;
}

void task2()
{
    for(int i=0;i<5;i++)
        cout<<"Task2 running"<<endl;
}

int main()
{
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();

    return 0;
} //Output order may vary because both run simultaneously.


//////////////////////Thread with Parameters
#include <iostream>
#include <thread>
using namespace std;

void add(int a,int b)
{
    cout<<"Sum = "<<a+b<<endl;
}

int main()
{
    thread t1(add,5,10);
    t1.join();
    return 0;
}

//////////////////////Race Condition//////////////////
A race condition happens when two or more threads access and modify shared data simultaneously, 
and the final result depends on the order of execution of those threads.

#include <iostream>
#include <thread>
using namespace std;

int counter = 0;
void increment()
{
    for(int i=0;i<1000;i++)
        counter++;
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();

    cout<<"Counter = "<<counter<<endl;
}


////////////Fix Race Condition /////////////
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
mutex m;
void increment()
{
    for(int i=0;i<1000;i++)
    {
        m.lock();
        counter++;
        m.unlock();
    }
}

int main()
{
    thread t1(increment);
    thread t2(increment);
    t1.join();
    t2.join();

    cout<<"Counter = "<<counter<<endl;
}


////////////DEADLOCK//////////////
Deadlock
Deadlock occurs when two threads wait for each other forever.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1,m2;

void task1()
{
    m1.lock();
    cout<<"Task1 locked m1"<<endl;

    m2.lock();
    cout<<"Task1 locked m2"<<endl;

    m2.unlock();
    m1.unlock();
}

void task2()
{
    m2.lock();
    cout<<"Task2 locked m2"<<endl;

    m1.lock();
    cout<<"Task2 locked m1"<<endl;

    m1.unlock();
    m2.unlock();
}

int main()
{
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();
}
//Thread1 → locks m1
//Thread2 → locks m2
//Thread1 → waits for m2
//Thread2 → waits for m1


solution : 
try to lock the task in same order

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex m1, m2;

void task1()
{
    m1.lock();
    cout<<"Task1 locked m1"<<endl;

    m2.lock();
    cout<<"Task1 locked m2"<<endl;

    m2.unlock();
    m1.unlock();
}

void task2()
{
    m1.lock();   // same order as task1
    cout<<"Task2 locked m1"<<endl;

    m2.lock();
    cout<<"Task2 locked m2"<<endl;

    m2.unlock();
    m1.unlock();
}

int main()
{
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();
}





coding

print even and odd 

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;

mutex m ;
condition_variable cv;
int num = 0 ;
int N = 10;

void PrintEven()
{
  while(num <= N)
{
unique_lock<mutex> lock(m);
cv.wait(lock, [] {return (num%2==0);});
cout<< " EVEN " <<endl;
num++;
cv.notify_all();
}
}

void PrintOdd()
{
  while(num <= N)
{
unique_lock<mutex> lock(m);
cv.wait(lock, [] {return (num%2!=0);});
cout<< " ODD " <<endl;
num++;
cv.notify_all();
}
}

int main()
{
  thread t1(PrintEven);
  thread t2(PrintOdd);
t1.join();
t2.join();
return  0;
}




Producer/Consumer;

#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<queue>

using namespace std;

mutex m;
condition_variable cv;
queue<int> q;
const int Max = 5;

void Producer()
{
    for(int i = 0; i <= 10; i++)
    {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [] { return q.size() < Max; });

        q.push(i);
        cout << "Produced: " << i << endl;

        cv.notify_all();
    }
}

void Consumer()
{
    for(int i = 0; i <= 10; i++)
    {
        unique_lock<mutex> lock(m);

        cv.wait(lock, [] { return !q.empty(); });

        int val = q.front();
        q.pop();

        cout << "Consumed: " << val << endl;

        cv.notify_all();
    }
}

int main()
{
    thread t1(Producer);
    thread t2(Consumer);

    t1.join();
    t2.join();

    return 0;
}
