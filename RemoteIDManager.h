#pragma once

#include "../SIM_Multicopter.h"
#include <AP_GPS/AP_GPS.h>
#include <AP_SerialManager/AP_SerialManager.h>

#include "json.hpp"
using json = nlohmann::json;

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <chrono>


namespace SITL { class MultiCopter;}

namespace RemoteID {


class RemoteIDManager {

public:
    SITL::MultiCopter *multicopter;

    
    AP_GPS *gps;
    AP_SerialManager serial_manager;

    json log;

    std::ofstream logFile;

    RemoteIDManager(SITL::MultiCopter *_multicopter):
        multicopter(_multicopter)
    {

        logFile.open ("/var/log/remoteid/-" + std::to_string(std::time(nullptr) - 1546300800) + ".txt");

        gps = AP_GPS::get_singleton();
        
        serial_manager.init();
        gps->init(serial_manager);

    }

    ~RemoteIDManager(){
        logFile.close();
    }


    void loop();

    

protected:

    // const uint64_t LegacyBTStatic = 3000000;
    const uint64_t updateRate = 1000000;
    // const uint64_t LegacyBTStatic = 1000000 * 10;
    // const uint64_t LegacyBTDynamic = 1000000 * 10;
    // const uint64_t BTExtended = 333333;
    // const uint64_t WiFiStatic = 3000000;
    // const uint64_t WiFiDynamic = 333333;

    uint64_t nextUpdate = 0;
    // uint64_t nextDynamicUpdate = 0;

};



}
