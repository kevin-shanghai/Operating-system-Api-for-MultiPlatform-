/*************************************************************************
	> File Name: osapi_mutex.cpp
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年05月11日 星期日 17时14分37秒
 ************************************************************************/

#include<iostream>
#include "osapi_common_def.h"
#include "osapi_mutex.h"
#include "osapi_mutex_impl.h"

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE

Mutex::Mutex():m_pMutexImpl(new MutexImpl())
{
	std::cout<<"In Mutex::Mutrex()."<<std::endl;
}

Mutex::~Mutex()
{
	if(m_pMutexImpl != NULL)
		delete m_pMutexImpl;
}

bool Mutex::Lock(void)
{
	return m_pMutexImpl->Lock();
}

bool Mutex::TryLock(void)
{
	return m_pMutexImpl->TryLock();
}

bool Mutex::UnLock(void)
{
	return m_pMutexImpl->UnLock();
}

MULTIPLATFORM_OSAPI_END_NAMESPACE