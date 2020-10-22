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
};

class SystemMessage: public MessageBody {
    public:

        struct SystemMessageData system;

        SystemMessage(
            uint8_t flags,
            uint8_t operatorLatitude[4],
            uint8_t operatorLongitude[4],
            uint8_t areaCount[2],
            uint8_t areaRadius,
            uint8_t AreaCeiling[2],
            uint8_t AreaFloor[2]
        )
        {
            system.Flags = flags;
            system.AreaRadius = areaRadius;
        };

        void Print() override
        {

        }
};