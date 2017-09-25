//
// Created by jiquanxi on 17-9-20.
//

#ifndef VIP_DEVICE_H
#define VIP_DEVICE_H

class Device
{
public:
    virtual bool exists() = 0;
};

class NetDevice : public Device
{
public:
    NetDevice(char *name) : name(name) {};

    virtual bool exists();
private:
    char *name;
};

#endif //VIP_DEVICE_H
