/*************************************************************************
	> File Name: osapi_actor_impl.h
	> Author: kevinfu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: Fri 09 May 2014 05:10:52 PM CST
 ************************************************************************/
#ifndef __OSAPI_ACTOR_IMPL_H__
#define __OSAPI_ACTOR_IMPL_H__

#include<iostream>
#include "osapi_actor.h"
using namespace std;

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE
class ActorImpl
{
public:
    ActorImpl(string name, int priority, Actor* pactor);
    ~ActorImpl();
    bool Start(void);
    bool Run(void);
    
private:
    Actor* m_pActor;
    string m_sName;
    int m_iPriority;
    bool m_bStart;
#ifdef __linux__
    pthread_t m_ThreadId;
#endif
};
MULTIPLATFORM_OSAPI_END_NAMESPACE
#endif
