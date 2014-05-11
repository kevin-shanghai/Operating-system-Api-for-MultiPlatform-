/*************************************************************************
	> File Name: osapi_actor.cpp
	> Author: kevinfu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: Fri 09 May 2014 05:20:43 PM CST
 ************************************************************************/

#include<iostream>
#include "osapi_actor.h"
#include "osapi_actor_impl.h"

using namespace std;


MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE
Actor::Actor(string name, int priority)
			:m_pActorImpl(NULL)
{
    m_pActorImpl = new ActorImpl(name, priority, this);
    cout<<"In Actor::Actor()."<<endl;
}

Actor::~Actor()
{
	
}

bool Actor::Start(void)
{
   return m_pActorImpl->Start();
}
MULTIPLATFORM_OSAPI_END_NAMESPACE