#include "RemoteIDManager.h"

#include <stdio.h>

using namespace RemoteID;

void RemoteIDManager::update()
{

    uint64_t current_time = multicopter->get_time_now_us();

    // print sim time
    // printf("%" PRIu64 "\n", current_time);

    if(current_time >= nextStaticUpdate) {
        printf("Broadcast BT Legacy Static\n");
        nextStaticUpdate += LegacyBTStatic;
    }

    if(current_time >= nextDynamicUpdate) {
        printf("Broadcast BT Legacy Dynamic\n");
        nextDynamicUpdate += LegacyBTDynamic;
    }

    
}
