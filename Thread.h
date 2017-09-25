//
// Created by jiquanxi on 17-9-19.
//

#ifndef VIP_THREAD_H
#define VIP_THREAD_H

class Thread
{
public:
    virtual bool start() = 0;
    virtual bool stop() = 0;
};

#endif //VIP_THREAD_H
