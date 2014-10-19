#ifndef __OSAPI_CONDITION_H__
#define __OSAPI_CONDITION_H__
#include <pthread.h>
#include "osapi_scoped_lock.h"

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE

class Mutexlock;

class Condition
{
public:
	Condition(MutexLock& mutex):m_rMutex(mutex)
	{
		pthread_cond_init(&m_cond, NULL);
	}

	~Condition()
	{
		pthread_cond_destroy(&m_cond);
	}

	void Wait()
	{
		pthread_cond_wait(&m_cond, m_rMutex.GetPthreadMutex());
	}

	void Notify()
	{
		pthread_cond_signal(&m_cond);
	}

	void NotifyAll()
	{
		pthread_cond_broadcast(&m_cond);
	}

	bool WaitForSeconds(int seconds);


private:
	MutexLock& m_rMutex;
	pthread_cond_t m_cond;

};

MULTIPLATFORM_OSAPI_END_NAMESPACE
#endif