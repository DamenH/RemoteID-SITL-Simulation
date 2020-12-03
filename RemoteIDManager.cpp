#include "RemoteIDManager.h"
#include "Messages/Messages.h"
// #include "Helper.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <chrono>

using namespace RemoteID;

void RemoteIDManager::loop() {


    uint64_t current_time = multicopter->get_time_now_us();

    if(current_time >= nextUpdate) {

        MessagePack * messagePack = new MessagePack();

        // Basic
        uint8_t idType = 3;
        uint8_t uaType = 2;
        char uasID[20] = "N.123456";
        MessageHeader *basicMessageHeader = new MessageHeader(0x0);
        BasicIDMessage *basicIdMessage = new BasicIDMessage(idType, uaType, uasID);
        MessageBody *basicBody = basicIdMessage;
        messagePack->addMessage(basicMessageHeader, basicBody);


        // Auth
        uint8_t authType = 0;
        uint8_t pageNumber = 0;
        uint8_t pageCount = 1;
        uint8_t length = 17;
        //   1,605,796,610
        // - 1,546,300,800
        // ----------------
        //      59,495,810
        time_t timestamp = std::time(nullptr) - 1546300800;
        uint32_t authenticationTimestamp = static_cast<uint32_t> (timestamp);
        // std::cout << authenticationTimestamp << " seconds since the 01/01/2019 00:00:00\n";
        uint8_t authenticationData[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
        MessageHeader *authenticationMessageHeader = new MessageHeader(0x2);
        AuthenticationMessage *authenticationMessage =  new AuthenticationMessage(
            authType, 
            pageNumber,
            pageCount,
            length,
            authenticationTimestamp,
            authenticationData
        );
        MessageBody *authenticationMessageBody = authenticationMessage;
        messagePack->addMessage(authenticationMessageHeader, authenticationMessageBody);

        // AuthPages
        uint8_t authPagesType = 0;
        uint8_t pagesNumber = 1;
        uint8_t authenticationPagesData[23] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23};
        MessageHeader *authenticationMessagePagesHeader = new MessageHeader(0x2);
        AuthenticationMessagePages *authenticationMessagePages =  new AuthenticationMessagePages(authPagesType, pagesNumber, authenticationPagesData);
        MessageBody *authenticationPagesMessageBody = authenticationMessagePages;
        messagePack->addMessage(authenticationMessagePagesHeader, authenticationPagesMessageBody);

        // SelfID
        uint8_t descriptionType = 0;
        char description[23] = "DronesRus:Survey";
        MessageHeader *selfIDMessageHeader = new MessageHeader(0x3);
        SelfIDMessage *selfIDMessage =  new SelfIDMessage(descriptionType, description);
        MessageBody *selfIDMessageBody = selfIDMessage;
        messagePack->addMessage(selfIDMessageHeader, selfIDMessageBody);

        // // SystemMessage
        uint8_t systemFlags = 0;
        int32_t operatorLatitude = multicopter->home.lat;
        int32_t operatorLongitude = multicopter->home.lng;
        uint16_t areaCount = 1;
        uint8_t areaRadius = 0;
        uint16_t AreaCeiling = 0;
        uint16_t AreaFloor = 0;
        MessageHeader *systemMessageHeader = new MessageHeader(0x4);
        SystemMessage *systemMessage =  new SystemMessage(            
            systemFlags,
            operatorLatitude,
            operatorLongitude,
            areaCount,
            areaRadius,
            AreaCeiling,
            AreaFloor
        );
        MessageBody *systemMessageBody = systemMessage;
        messagePack->addMessage(systemMessageHeader, systemMessageBody);

        // OperatorID
        uint8_t operatorIdType = 0;
        char operatorId[20] = "Damen Hannah #123";
        MessageHeader *operatorIDMessageHeader = new MessageHeader(0x5);
        OperatorIDMessage *operatorIDMessage =  new OperatorIDMessage(operatorIdType, operatorId);
        MessageBody *operatorIDMessageBody = operatorIDMessage;
        messagePack->addMessage(operatorIDMessageHeader, operatorIDMessageBody);

        // Location
        // // if(previousLocation.is_zero()) previousLocation = gps->location();
        gps->update();
        const Location &currentLocation = gps->location();
        // // printf("%" PRId32 "\n", currentLocation.alt);
        uint8_t status = 0;
        uint8_t locationVectorFlags = 0;
        uint8_t trackDirection = (uint8_t)gps->ground_course();
        uint8_t speed = (uint8_t)gps->ground_speed();
        uint8_t verticalSpeed = 0; // calculate from velocity_ef
        int32_t latitude = currentLocation.lat;
        int32_t longitude = currentLocation.lng;
        uint16_t pressureAltitude = 584;
        uint16_t geodeticAltitude = 584;
        uint16_t height = 0;
        uint8_t verticalAccuracy = 0;
        uint8_t horizontalAccuracy = 0;
        uint8_t baroAltitudeAccuracy = 0;
        uint8_t speedAccuracy = 0;
        uint16_t locationVectorTimestamp = 0; //(gps->time_week_ms()/1000); // 0–36000
        uint8_t timestampAccuracy = 0;
        MessageHeader *locationVectorMessageHeader = new MessageHeader(0x1);
        LocationVectorMessage *locationVectorMessage =  new LocationVectorMessage(
            status,
            locationVectorFlags,
            trackDirection,
            speed,
            verticalSpeed,
            latitude,
            longitude,
            pressureAltitude,
            geodeticAltitude,
            height,
            verticalAccuracy,
            horizontalAccuracy,
            baroAltitudeAccuracy,
            speedAccuracy,
            locationVectorTimestamp,
            timestampAccuracy
        );
        MessageBody *locationVectorMessageBody = locationVectorMessage;
        messagePack->addMessage(locationVectorMessageHeader, locationVectorMessageBody);

        // std::cout << messagePack->toJson().dump(4) << std::endl;

        logFile << messagePack->toJson().dump(4) << std::endl;

        nextUpdate += updateRate;
    }
    
}
