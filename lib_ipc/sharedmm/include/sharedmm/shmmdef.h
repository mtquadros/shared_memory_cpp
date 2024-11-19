//
// Created by dev on 28/09/24.
//

#ifndef SHMMDEF_H
#define SHMMDEF_H

#include <unistd.h>

namespace sharedmm
{
    using processNumber_t = size_t;
    using bufferSize_t = size_t;
    using processId_t = pid_t;
    using validProcess_t = bool;
};

#endif //SHMMDEF_H
