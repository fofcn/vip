//
// Created by jiquanxi on 17-9-18.
//
#include "GumballMachine.h"

void GumballMachine::insertQuarter()
{
    if(_state == HAS_QUARTER)
    {
//        std::cout<< "You can't insert another quarter"<<std::end;
    }
    else if(_state == NO_QUARTER)
    {
        _state = HAS_QUARTER;
//        std::cout<< "You inserted a quarter" <<std::endl;
    }
}

void GumballMachine::dispense()
{

}
