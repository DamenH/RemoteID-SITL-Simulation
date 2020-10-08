#include "RemoteIDManager.h"

#include "Messages/Messages.h"

#include <stdio.h>
#include <iostream>

using namespace RemoteID;

void RemoteIDManager::update()
{

    // uint64_t current_time = multicopter->get_time_now_us();

    // print sim time
    // printf("%" PRIu64 "\n", current_time);

    uint8_t uasID[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    uint8_t idType = 3;
    uint8_t uaType = 0;

    BasicIDMessage::Encode(idType, uaType, uasID);
    uint8_t basicIdMessage[24];
    BasicIDMessage::Copy(basicIdMessage);

    MessageHeader::Encode(0x0, basicIdMessage);
    uint8_t basicId[25];
    MessageHeader::Copy(basicId);

    // location vector params

    LocationVectorMessage::Encode();
    uint8_t locationVectorMessage[24];
    LocationVectorMessage::Copy(locationVectorMessage);

    MessageHeader::Encode(0x0, locationVectorMessage);
    uint8_t locationVector[25];
    MessageHeader::Copy(basicId);

    // location vector params

    LocationVectorMessage::Encode();
    uint8_t locationVectorMessage[24];
    LocationVectorMessage::Copy(locationVectorMessage);

    MessageHeader::Encode(0x1, locationVectorMessage);
    uint8_t locationVector[25];
    MessageHeader::Copy(locationVector);

    // authentication params

    // AuthenticationMessage::Encode();
    uint8_t authenticationMessage[24];
    AuthenticationMessage::Copy(authenticationMessage);

    MessageHeader::Encode(0x2, authenticationMessage);
    uint8_t authentication[25];
    MessageHeader::Copy(authentication);

    // authentication pages params

    // AuthenticationMessagePages::Encode();
    uint8_t authenticationMessagePages[24];
    AuthenticationMessagePages::Copy(authenticationMessagePages);

    MessageHeader::Encode(0x2, authenticationMessagePages);
    uint8_t authenticationPages[25];
    MessageHeader::Copy(authenticationPages);

    // self id params

    // SelfIDMessage::Encode();
    uint8_t selfIdMessage[24];
    SelfIDMessage::Copy(selfIdMessage);

    MessageHeader::Encode(0x3, selfIdMessage);
    uint8_t selfId[25];
    MessageHeader::Copy(selfId);

    // system params

    // SystemMessage::Encode();
    uint8_t systemMessage[24];
    SystemMessage::Copy(systemMessage);

    MessageHeader::Encode(0x4, systemMessage);
    uint8_t system[25];
    MessageHeader::Copy(system);

    // operator params

    // OperatorIDMessage::Encode();
    uint8_t operatorIdMessage[24];
    OperatorIDMessage::Copy(operatorIdMessage);

    MessageHeader::Encode(0x5, operatorIdMessage);
    uint8_t operatorId[25];
    MessageHeader::Copy(operatorId);

    


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
