#include "osapi_common_def.h"
#include "osapi_condition.h"
#include <errno.h>
#include <time.h>

MULTIPLATFORM_OSAPI_BEGIN_NAMESPACE

bool Condition::WaitForSeconds(int seconds)
{
  struct timespec abstime;
  // FIXME: use CLOCK_MONOTONIC or CLOCK_MONOTONIC_RAW to prevent time rewind.
  clock_gettime(CLOCK_REALTIME, &abstime);
  abstime.tv_sec += seconds;
  return ETIMEDOUT == pthread_cond_timedwait(&m_cond, m_rMutex.GetPthreadMutex(), &abstime);
}


MULTIPLATFORM_OSAPI_END_NAMESPACE
