#include "osapi_countdownlatch.h"

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE

CountDownLatch::CountDownLatch(int count)
			:m_oMutex()
			,m_oCondition(m_oMutex);
			,m_iCount(count)
		{

		}
void CountDownLatch::Wait()
	{
		MutexLockGuard AutoLock(m_oMutex);
		while(m_iCount > 0)
		{
			m_oCondition.wait();
		}
	}

void CountDownLatch::CountDown()
	{
		MutexLockGuard AutoLock(m_oMutex);
		m_iCount--;
		if(m_iCount == 0)
		{
			m_oCondition.NotifyAll();
		}
	}

int CountDownLatch::GetCountValue()
	{
		MutexLockGuard AutoLock(m_oMutex);
		return m_iCount;
	}

MULTIPLATFORM_OSAPI_END_NAMESPACE