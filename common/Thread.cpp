//
// Created by jiquanxi on 17-9-20.
//

#include "Thread.h"

Thread::Thread() : target(NULL), started(false) {}

Thread::Thread(IRunnable *target) : target(target), started(false) {}

bool Thread::start()
{
    int ret = pthread_create(&handle, NULL, Thread::callback, this);
    if(ret != 0)
    {
        return false;
    }
}

void Thread::stop()
{

}

void Thread::stop(bool force)
{

}

void Thread::join()
{

}

void Thread::join(long milliSecs)
{

}

void *Thread::callback(void *arg)
{
    if(arg == NULL)
    {
        return NULL;
    }

    Thread *pThis = (Thread *) arg;
    pThis->started = true;

    if(pThis->target != NULL)
    {
        pThis->target->run();
    }

    pThis->started = false;
}


