//
// Created by jiquanxi on 17-9-20.
//

#ifndef VIP_TESTRUNNABLE_H
#define VIP_TESTRUNNABLE_H

#include <iostream>

#include "common/Runnable.h"

class Runnable : public IRunnable
{
public:
    virtual void run() {std::cout << "It works!" << std::endl;}
};

#endif //VIP_TESTRUNNABLE_H
