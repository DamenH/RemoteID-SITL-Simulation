#include <stdint.h>

struct SystemMessageData {
    unsigned Flags : 8;
    uint8_t OperatorLatitude[4];
    uint8_t OperatorLongitude[4];
    uint8_t AreaCount[2];
    unsigned AreaRadius : 8;
    uint8_t AreaCeiling[2];
    uint8_t AreaFloor[2];
    uint8_t Reserved[8];
} System;

class SystemMessage {
    public:
        static void Encode(
            uint8_t flags,
            uint8_t operatorLatitude[4],
            uint8_t operatorLongitude[4],
            uint8_t areaCount[2],
            uint8_t areaRadius,
            uint8_t AreaCeiling[2],
            uint8_t AreaFloor[2]
        )
        {
            System.Flags = flags;
            System.AreaRadius = areaRadius;
        } 
};