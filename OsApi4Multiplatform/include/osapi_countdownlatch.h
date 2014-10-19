#ifndef __OSAPI_COUNTDOWNLATCH_H__
#define __OSAPI_COUNTDOWNLATCH_H__
#include "osapi_scoped_lock.h"
#include "osapi_condition.h"



MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE
class CountDownLatch
{
public:
	explicit CountDownLatch(int count);

	void Wait();

	void CountDown();

	int GetCountValue();

private:
	MutexLock m_oMutex;
	Condition m_oCondition;
	int m_iCount;
};


MULTIPLATFORM_OSAPI_END_NAMESPACE


#endif