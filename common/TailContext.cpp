//
// Created by error on 2017/9/26.
//

#include "TailContext.h"


TailContext::TailContext(DefaultPacketPipeline *pipeline)
        : AbstractPacketHandlerContext(pipeline, "tail", true, false) {}