//
// Created by error on 2017/9/26.
//

#include "HeadContext.h"


HeadContext::HeadContext(DefaultPacketPipeline *pipeline)
        : AbstractPacketHandlerContext(pipeline, "head", false, true) {}