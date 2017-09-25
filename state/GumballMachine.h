//
// Created by jiquanxi on 17-9-18.
//

#ifndef VIP_GUMBALLMACHINE_H
#define VIP_GUMBALLMACHINE_H

class GumballMachine
{
public:
    static const int SOLD_OUT = 0;
    static const int NO_QUARTER = 1;
    static const int HAS_QUARTER = 2;
    static const int SOLD = 3;

    GumballMachine(int count): _state(SOLD_OUT),_count(0)
    {
        if(count > 0)
        {
            _state = NO_QUARTER;
        }
    }

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    void dispense();
private:
    int _state;
    int _count;
};

#endif //VIP_GUMBALLMACHINE_H
