#include <stdint.h>

struct systemMessageData {
    unsigned flags : 8;
    uint8_t operatorLatitude[4];
    uint8_t operatorLongitude[4];
    uint8_t areaCount[2];
    unsigned areaRadius : 8;
    uint8_t areaCeiling[2];
    uint8_t areaFloor[2];
    uint8_t reserved[8];
};

class SystemMessage: public MessageBody {
    public:

        struct systemMessageData system;

        SystemMessage(
            uint8_t flags,
            uint8_t operatorLatitude[4],
            uint8_t operatorLongitude[4],
            uint8_t areaCount[2],
            uint8_t areaRadius,
            uint8_t areaCeiling[2],
            uint8_t areaFloor[2]
        )
        {
            system.flags = flags;
            system.areaRadius = areaRadius;
            for(int i = 0; i < 4; i++)
            {
                system.operatorLatitude[i] = operatorLatitude[i];
                system.operatorLongitude[i] = operatorLongitude[i];
            }
            for(int i = 0; i < 2; i++)
            {
                system.areaCount[i] = areaCount[i];
                system.areaCeiling[i] = areaCeiling[i];
                system.areaFloor[i] = areaFloor[i];
            }
        };

        void Print() override
        {
            std::cout << "System Message" << '\n';
            std::cout << " Flags: " << system.flags << '\n';
            std::cout << " Operator Latitude: ";
            std::cout << *(uint32_t *)&system.operatorLatitude;
            std::cout << " Operator Longitude: ";
            std::cout << *(uint32_t *)&system.operatorLongitude;
            std::cout << " Area Count: ";
            for(int i = 0; i < 2; i++)
            {
                std::cout << system.areaCount[i];
            }
            std::cout << " Area Radius: " << system.areaRadius << '\n';
            std::cout << " Area Ceiling: ";
            for(int i = 0; i < 2; i++)
            {
                std::cout << system.areaFloor[i];
            }
            std::cout << " Area Floor: ";
            for(int i = 0; i < 2; i++)
            {
                std::cout << system.areaFloor[i];
            }
            std::cout << '\n';
        }
};