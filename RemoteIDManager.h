/*

    1. Create SIM_WiFi and SIM_Bluetooth
        a. These inherit from SerialDevice
        b. Possibly create new Beacon base class.
        c. Bluetooth
            - Manage the bluetooth exclusive stuff (packets, range, versions)
        d. WiFi
            - Manage the WiFi exclusive stuff
    2. This class communicates to both SerialDevices
    3. This class manages the content and timing of the messages being sent out. Tells the beacon devices what to transmit
    4. Also create a simulated reciever. It'd be nice if it were another 
    
*/
#pragma once

#include "../SIM_Multicopter.h"

namespace RemoteID {
class SITL::MultiCopter;
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
