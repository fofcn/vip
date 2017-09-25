//
// Created by jiquanxi on 17-9-20.
//

#include <pcap.h>
#include <cstring>

#include "Device.h"

bool NetDevice::exists()
{
    pcap_if_t *devList = NULL;
    char errBuf[PCAP_ERRBUF_SIZE] = {0};

    if(pcap_findalldevs(&devList, errBuf) == -1)
    {
        return false;
    }

    for(pcap_if_t *d = devList; d; d = d->next)
    {
        if(strcmp(d->name, name) == 0)
        {
            return true;
        }

    }

    return false;
}
