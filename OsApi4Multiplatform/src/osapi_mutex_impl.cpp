/*************************************************************************
	> File Name: osapi_mutex_impl.cpp
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年05月11日 星期日 17时14分48秒
 ************************************************************************/

#include <iostream>
#include "osapi_mutex_impl.h"

using namespace std;

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE
MutexImpl::MutexImpl()
{
	#ifdef __linux__
	pthread_mutex_init(&m_Mutex, NULL);
	#elif defined WIN32
	#else
	#endif
	cout<<"In MutexImpl::MutexImpl()"<<endl;
}

MutexImpl::~MutexImpl()
{
	#ifdef __linux__
	pthread_mutex_destroy(&m_Mutex);
	#elif defined WIN32
	#else
	#endif
}

bool MutexImpl::Lock()
{
	return pthread_mutex_lock(&m_Mutex);
}

bool MutexImpl::TryLock(void)
{
	return pthread_mutex_trylock(&m_Mutex);
}

bool MutexImpl::UnLock(void)
{
	return pthread_mutex_unlock(&m_Mutex);
}


MULTIPLATFORM_OSAPI_END_NAMESPACE