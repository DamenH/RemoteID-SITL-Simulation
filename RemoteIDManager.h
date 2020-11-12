#pragma once
#include "../SIM_Multicopter.h"

#include <AP_GPS/AP_GPS.h>
#include <AP_SerialManager/AP_SerialManager.h>

namespace SITL { class MultiCopter;}

namespace RemoteID {


class RemoteIDManager {

public:
    SITL::MultiCopter *multicopter;

    
    AP_GPS *gps;
    AP_SerialManager serial_manager;


    RemoteIDManager(SITL::MultiCopter *_multicopter):
        multicopter(_multicopter)
    {

        gps = AP_GPS::get_singleton();
        
        serial_manager.init();
        gps->init(serial_manager);

    }


    void loop();

protected:

    // const uint64_t LegacyBTStatic = 3000000;
    // const uint64_t LegacyBTDynamic = 333333 * 3;
    const uint64_t LegacyBTStatic = 1000000 * 10;
    const uint64_t LegacyBTDynamic = 1000000 * 10;
    const uint64_t BTExtended = 333333;
    const uint64_t WiFiStatic = 3000000;
    const uint64_t WiFiDynamic = 333333;

    uint64_t nextStaticUpdate = 0;
    uint64_t nextDynamicUpdate = 0;

};



}
