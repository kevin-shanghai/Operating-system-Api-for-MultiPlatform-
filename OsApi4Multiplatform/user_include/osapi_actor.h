/*************************************************************************
	> File Name: osapi_actor.h
	> Author: kevinfu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: Fri 09 May 2014 04:53:25 PM CST
 ************************************************************************/
#ifndef __OSAPI_ACTOR_H__
#define __OSAPI_ACTOR_H__

#include<iostream>
#include "osapi_common_def.h"
using namespace std;

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE
class ActorImpl;
class Actor
{
public:
    Actor(string name = "", int priority = 0);
    virtual ~Actor();
    bool Start(void);
    virtual void Run() = 0;

private:
    ActorImpl* m_pActorImpl;    
};
MULTIPLATFORM_OSAPI_END_NAMESPACE
#endif
