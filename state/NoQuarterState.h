//
// Created by jiquanxi on 17-9-19.
//

#ifndef VIP_NOQUARTERSTATE_H
#define VIP_NOQUARTERSTATE_H

#include <iostream>
#include "State.h"
#include "GumballMachine.h"

class NoQuarterState : public State
{
public:
    NoQuarterState(GumballMachine gumballMachine) : gumballMachine(gumballMachine){}

    virtual void insertQuarter()
    {
        std::cout<< "You inserted a quarter" <<std::endl;
    }

    virtual void ejectQuarter()
    {
        std::cout<< "You haven't inserted a quarter" <<std::endl;
    }

private:
    GumballMachine gumballMachine;
};

#endif //VIP_NOQUARTERSTATE_H
