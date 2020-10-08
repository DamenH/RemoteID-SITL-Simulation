#include "RemoteIDManager.h"

#include "Messages/AuthenticationMessage.h"
#include "Messages/AuthenticationMessagePages.h"
#include "Messages/BasicIDMessage.h"
#include "Messages/LocationVectorMessage.h"
#include "Messages/MessageHeader.h"
#include "Messages/MessagePack.h"
#include "Messages/OperatorIDMessage.h"
#include "Messages/SelfIDMessage.h"
#include "Messages/SystemMessage.h"

#include <stdio.h>
#include <iostream>

using namespace RemoteID;

void RemoteIDManager::update()
{

    // uint64_t current_time = multicopter->get_time_now_us();

    // print sim time
    // printf("%" PRIu64 "\n", current_time);

    // uint8_t uasID[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // BasicIDMessage::Encode(3, 0, uasID);

    // std::cout << "ID Type: " << BasicID.IDType << '\n';
    // std::cout << "UA Type: " << BasicID.UAType << '\n';
    // for(int i = 0; i < 20; i++)
    // {
    //     std::cout << (int)BasicID.UASID[i] << ' ';
    // }
    // std::cout << '\n';


    // if(current_time >= nextStaticUpdate) {
    //     printf("Broadcast BT Legacy Static\n");
    //     nextStaticUpdate += LegacyBTStatic;
    // }

    // if(current_time >= nextDynamicUpdate) {
    //     printf("Broadcast BT Legacy Dynamic\n");
    //     nextDynamicUpdate += LegacyBTDynamic;
    // }

    
}
