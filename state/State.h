//
// Created by jiquanxi on 17-9-19.
//

#ifndef VIP_STATE_H
#define VIP_STATE_H

class State
{
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};

#endif //VIP_STATE_H
