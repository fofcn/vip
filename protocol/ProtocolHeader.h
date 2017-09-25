//
// Created by jiquanxi on 17-9-21.
//

#ifndef VIP_PROTOCOLHEADER_H
#define VIP_PROTOCOLHEADER_H


#include "../Types.h"

struct ether_header
{
    uchar ether_dhost[6];
    uchar ether_shost[6];
    ushort ether_type;
};

typedef struct ether_header eth_header;



#endif //VIP_PROTOCOLHEADER_H
