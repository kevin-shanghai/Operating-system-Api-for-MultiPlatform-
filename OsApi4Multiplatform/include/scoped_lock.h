/*************************************************************************
	> File Name: Mutex.cpp
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年05月18日 星期日 22时29分56秒
 ************************************************************************/

#ifndef __SCOPED_LOCK_H__
#define __SCOPED_LOCK_H__

#include "osapi_common_def.h"
#include <iostream>
#include "boost/noncopyable.hpp"

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE

using namespace std;
class MutexLock: boost::noncopyable
{
public:
    MutexLock()
    {
        cout<<"In MutexLock()."<<endl;
        pthread_mutex_init(&m_Mutex, NULL);
    }
    ~MutexLock()
    {
        cout<<"In ~MutexLock()."<<endl;
        pthread_mutex_destroy(&m_Mutex);
    }
    void Lock()
    {
        cout<<"In MutexLock::Lock()"<<endl;
        pthread_mutex_lock(&m_Mutex);
    }
    void UnLock()
    {
        cout<<"In MutexLock::UnLock()"<<endl;
        pthread_mutex_unlock(&m_Mutex);
    }


private:
    pthread_mutex_t m_Mutex;
};

class MutexLockGuard: boost::noncopyable
{
public:
    MutexLockGuard(MutexLock& mutex)
        :m_rMutex(mutex)
    {
        m_rMutex.Lock();
    }
    ~MutexLockGuard()
    {
        m_rMutex.UnLock();
    }

private:
    MutexLock& m_rMutex;
};

MULTIPLATFORM_OSAPI_END_NAMESPACE

#endif