#include <stdint.h>

struct BasicMessageData {
    unsigned IDType : 4;
    unsigned UAType : 4;
    uint8_t UASID[20];
    uint8_t Reserve[3];
} BasicID;

class BasicIDMessage {
    public:
       static void Encode(
           uint8_t idType,
           uint8_t uaType,
           uint8_t uasId[20]
        )
       {
            BasicID.IDType = idType & 0xF;
            BasicID.UAType = uaType & 0xF;

            for(int i = 0; i < 20; i++)
            {
                BasicID.UASID[i] = uasId[i];
            }

            uint8_t reserve[3] = {0,0,0};

            for(int i = 0; i < 3; i++)
            {
                BasicID.Reserve[i] = reserve[i];
            }

        } 
};