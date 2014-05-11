/*************************************************************************
	> File Name: osapi_actor_impl.cpp
	> Author: kevinfu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: Fri 09 May 2014 05:35:23 PM CST
 ************************************************************************/

#include <iostream>
#include "osapi_actor_impl.h"
#include <string.h>
using namespace std;
MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE

static void* ThreadFunction(void* ptr)
{
	ActorImpl* pImpl = static_cast<ActorImpl*>(ptr);
	pImpl->Run();
}

ActorImpl::ActorImpl(string name,int priority, Actor* pActor)
    :m_pActor(pActor)
    ,m_bStart(false)
    ,m_iPriority(priority)
    ,m_sName(name)
{
    
}

ActorImpl::~ActorImpl()
{

}

bool ActorImpl::Start(void)
{
	if(m_bStart == true)
	{
		cout<<"This thread is already running!"<<endl;
		return true;
	}
	#ifdef __linux__
	pthread_create(&m_ThreadId, NULL, ThreadFunction, this);
	#endif
}

bool ActorImpl::Run(void)
{
	if(NULL == m_pActor)
	{
		cout<<"m_pActor is NULL."<<endl;
		return false;
	}
	m_pActor->Run();
}
MULTIPLATFORM_OSAPI_END_NAMESPACE