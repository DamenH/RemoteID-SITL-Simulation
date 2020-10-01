#pragma once

#include "../SIM_Multicopter.h"

namespace SITL { class MultiCopter;}

namespace RemoteID {

class RemoteIDManager {

public:
    SITL::MultiCopter *multicopter;

    RemoteIDManager(SITL::MultiCopter *_multicopter):
        multicopter(_multicopter)
    {}

    void update();

protected:

    const uint64_t LegacyBTStatic = 3000000;
    const uint64_t LegacyBTDynamic = 333333;
    const uint64_t BTExtended = 333333;
    const uint64_t WiFiStatic = 3000000;
    const uint64_t WiFiDynamic = 333333;

    uint64_t nextStaticUpdate = 0;
    uint64_t nextDynamicUpdate = 0;

};


}