/*************************************************************************
	> File Name: main.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年04月13日 星期日 22时04分52秒
 ************************************************************************/

#include <iostream>
#include "osapi_actor.h"
//#include "osapi_actor_impl.h"

using namespace std;
//using namespace MultiOsApi;


class MyThread:public Actor
{
public:
	MyThread(char const* name):Actor(name)
	{
	}
	virtual void Run()
	{
		while(1)
			cout<<"In MyThread::Run()."<<endl;
	}

};

int main()
{
    MyThread* thread = new MyThread("task");
    thread->Run();
    //pActor->Run();
    return 0;
}

