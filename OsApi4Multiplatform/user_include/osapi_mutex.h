/*************************************************************************
	> File Name: osapi_mutex.h
	> Author: KevinFu
	> Mail: kevinfu1985@gmail.com 
	> Created Time: 2014年05月11日 星期日 17时08分36秒
 ************************************************************************/
#ifndef __OSAPI_MUTEX_H__
#define __OSAPI_MUTEX_H__
#include<iostream>
using namespace std;

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE

class MutexImpl;
class Mutex
{
public:
	Mutex();
	virtual ~Mutex();
	bool Lock(void);
	bool TryLock(void);
	bool UnLock(void);
private:
	MutexImpl* m_pMutexImpl;

};

MULTIPLATFORM_OSAPI_END_NAMESPACE

#endif


