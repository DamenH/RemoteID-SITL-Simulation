#include "RemoteIDManager.h"

#include "Messages/Messages.h"
#include "Helpers.h"

#include <stdio.h>
#include <iostream>
#include <math.h>



using namespace RemoteID;

void RemoteIDManager::loop()
{


    uint64_t current_time = multicopter->get_time_now_us();

    // uint32_t test = 12345456;
    // uint8_t *arr = (uint8_t *)&test;

    // Static Updates
    if(current_time >= nextStaticUpdate) {
        // Basic
        uint8_t idType = 3;
        uint8_t uaType = 2;
        char uasID[20] = "N.123456";
        BasicIDMessage *basicIdMessage = new BasicIDMessage(idType, uaType, uasID);
        MessageBody *basicBody = basicIdMessage;
        MessageHeader *basicMessageHeader = new MessageHeader(0x0, basicBody);
        basicMessageHeader->Print();

        // Auth
        // uint8_t authType = 0;
        // uint8_t pageNumber = 0;
        // uint8_t pageCount = 0;
        // uint8_t length = 17;

        // std::time_t result = std::time(nullptr);
        // std::cout << std::asctime(std::localtime(&result)) << result << " seconds since the Epoch\n";
        // uint8_t authenticationTimestamp[4] = {1, 2, 3, 4};

        // uint8_t authenticationData[17] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
        // AuthenticationMessage *authenticationMessage =  new AuthenticationMessage(
        //     authType, 
        //     pageNumber,
        //     pageCount,
        //     length,
        //     authenticationTimestamp,
        //     authenticationData
        // );
        // MessageBody *authenticationMessageBody = authenticationMessage;
        // MessageHeader *authenticationMessageHeader = new MessageHeader(0x2, authenticationMessageBody);
        // authenticationMessageHeader->Print();

        // AuthPages
        // uint8_t authPagesType = 0;
        // uint8_t pagesNumber;
        // uint8_t authenticationPagesData[23];
        // AuthenticationMessagePages *authenticationMessagePages =  new AuthenticationMessagePages(authPagesType, pagesNumber, authenticationPagesData);
        // MessageBody *authenticationPagesMessageBody = authenticationMessagePages;
        // MessageHeader *authenticationMessagePagesHeader = new MessageHeader(0x2, authenticationPagesMessageBody);
        // authenticationMessagePagesHeader->Print();

        // SelfID
        uint8_t descriptionType = 0;
        char description[23] = "DronesRus:Survey";
        SelfIDMessage *selfIDMessage =  new SelfIDMessage(descriptionType, description);
        MessageBody *selfIDMessageBody = selfIDMessage;
        MessageHeader *selfIDMessageHeader = new MessageHeader(0x3, selfIDMessageBody);
        selfIDMessageHeader->Print();

        // SystemMessage
        uint8_t systemFlags = 0;
        uint8_t* operatorLatitude = (uint8_t *)&multicopter->home.lat;
        uint8_t* operatorLongitude = (uint8_t *)&multicopter->home.lng;
        uint8_t areaCount[2] = {0, 0};
        uint8_t areaRadius = 0;
        uint8_t AreaCeiling[2] = {0, 0};
        uint8_t AreaFloor[2] = {0, 0};
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
        MessageHeader *systemMessageHeader = new MessageHeader(0x3, systemMessageBody);
        systemMessageHeader->Print();

        // OperatorID
        uint8_t operatorIdType = 0;
        char operatorId[20] = "Damen Hannah #123";
        OperatorIDMessage *operatorIDMessage =  new OperatorIDMessage(operatorIdType, operatorId);
        MessageBody *operatorIDMessageBody = operatorIDMessage;
        MessageHeader *operatorIDMessageHeader = new MessageHeader(0x3, operatorIDMessageBody);
        operatorIDMessageHeader->Print();

        nextStaticUpdate += LegacyBTStatic;
    }

    // Dynamic Updates
    if(current_time >= nextDynamicUpdate) {
        // Location

        // if(previousLocation.is_zero()) previousLocation = gps->location();

        gps->update();
        const Location &currentLocation = gps->location();

        // printf("%" PRId32 "\n", currentLocation.alt);
        
        uint8_t status = 0;
        uint8_t locationVectorFlags = 0;
        uint8_t trackDirection = (uint8_t)gps->ground_course();
        uint8_t speed = (uint8_t)gps->ground_speed();
        uint8_t verticalSpeed = 0; // calculate from velocity_ef
        uint8_t* latitude = (uint8_t *)&currentLocation.lat;
        uint8_t* longitude = (uint8_t *)&currentLocation.lng;
        uint8_t pressureAltitude[2] = {0, 0};
        // uint8_t* geodeticAltitude = (uint8_t *)&currentLocation.alt;
        // uint8_t* height = (uint8_t *)&currentLocation.alt;
        uint8_t geodeticAltitude[2] = {0, 0};
        uint8_t height[2] = {0, 0};

        uint8_t verticalAccuracy = 0;
        uint8_t horizontalAccuracy = 0;
        uint8_t baroAltitudeAccuracy = 0;
        uint8_t speedAccuracy = 0;
        uint8_t locationVectorTimestamp[2] = {0, 0}; //(gps->time_week_ms()/1000); // 0–36000
        uint8_t timestampAccuracy = 0;
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
        MessageHeader *locationVectorMessageHeader = new MessageHeader(0x1, locationVectorMessageBody);
        locationVectorMessageHeader->Print();


        nextDynamicUpdate += LegacyBTDynamic;
    }
    
}
