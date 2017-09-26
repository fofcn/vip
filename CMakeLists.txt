cmake_minimum_required(VERSION 3.8)
project(vip)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp state/GumballMachine.h state/GumballMachine.cpp Thread.h state/State.h state/NoQuarterState.h common/Thread.h common/Runnable.h common/Thread.cpp TestRunnable.h pcap/Device.h pcap/Device.cpp protocol/ProtocolHeader.h Types.h common/PacketHandler.h common/PacketPipeline.h common/PacketPipeline.cpp common/PacketInboundInvoker.h common/AbstractPacketHandlerContext.h common/AbstractPacketHandlerContext.cpp common/PacketOutboundHandler.h common/PacketInboundHandler.h common/DefaultPacketHandlerContext.h common/DefaultPacketPipeline.h common/DefaultPacketPipeline.cpp common/HeadContext.cpp common/HeadContext.h common/TailContext.cpp common/TailContext.h common/PacketHandlerContext.h samples/SimplePacketHandler.h)
add_executable(vip ${SOURCE_FILES})
target_link_libraries(vip pthread)