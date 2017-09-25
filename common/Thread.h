//
// Created by jiquanxi on 17-9-20.
//

#ifndef VIP_THREAD_H
#define VIP_THREAD_H

#include <iostream>

#include <pthread.h>

#include "Runnable.h"

class IThread
{
public:
    virtual bool start() = 0;
    virtual void stop() = 0;
    virtual void stop(bool force) = 0;
    virtual void join() = 0;
    virtual void join(long milliSecs) = 0;
};

class Thread : public IThread
{
public:
    Thread();
    Thread(IRunnable *target);

    virtual bool start();
    virtual void stop();
    virtual void stop(bool force);
    virtual void join();
    virtual void join(long milliSecs);

private:
    static void *callback(void *arg);
private:
    IRunnable *target;
    pthread_t handle;
    bool started;
};

#endif //VIP_THREAD_H
