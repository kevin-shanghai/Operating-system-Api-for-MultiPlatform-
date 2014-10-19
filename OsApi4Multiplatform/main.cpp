/*************************************************************************
	> File Name: main.cpp
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: 2014年04月13日 星期日 22时04分52秒
 ************************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "osapi_actor.h"
#include "osapi_mutex.h"
#include "osapi_scoped_lock.h"

using namespace std;
using namespace MultiPlatform_OsApi;

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE


class MyThread:public Actor
{
public:
	MyThread(char const* name):Actor(name)//, m_pMutex(new Mutex)
	{
	}
	virtual void Run()
	{
		while(1)
		{
			MutexLockGuard LockGuard(m_Mutex);
			MyThread::count++;
			cout<<"MyThread::count is:"<<MyThread::count<<endl;
		}		
	}

private:
	static int count;
	MutexLock m_Mutex;

};

int MyThread::count = 0;


MULTIPLATFORM_OSAPI_END_NAMESPACE

int main()
{
    MyThread* thread1 = new MyThread("task1");
    thread1->Run();
    MyThread* thread2 = new MyThread("task2");
    thread2->Run();
    MyThread* thread3 = new MyThread("task3");
    thread3->Run();
    MyThread* thread4 = new MyThread("task4");
    thread4->Run();
    return 0;
}

