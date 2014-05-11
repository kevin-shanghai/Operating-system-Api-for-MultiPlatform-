/*************************************************************************
	> File Name: osapi_mutex_impl.h
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年05月11日 星期日 17时19分10秒
 ************************************************************************/
#ifndef __OSAPI_MUTEX_IMPL__H__
#define __OSAPI_MUTEX_IMPL__H__
#include "osapi_common_def.h"
#include<iostream>
#ifdef __linux__
	#include <pthread.h>
#elif defined WIN32
#else
#endif

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE
class MutexImpl
{
public:
	MutexImpl();
	~MutexImpl();
	bool Lock(void);
	bool TryLock(void);
	bool UnLock(void);

private:
	#ifdef __linux
	pthread_mutex_t m_Mutex;
	#elif defined WIN32
	#else
	#endif
};

MULTIPLATFORM_OSAPI_END_NAMESPACE
#endif
