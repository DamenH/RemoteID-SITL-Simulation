#include <stdint.h>

struct OperatorIDMessageData {
    unsigned OperatorIDType : 8;
    uint8_t OperatorID[20];
    uint8_t Reserved[3];
} OperatorID;

class OperatorIDMessage {
    public:
        static void Encode(
            uint8_t operatorIdType,
            uint8_t operatorId[20]
        )
        {
            OperatorID.OperatorIDType = operatorIdType;

            for(int i = 0; i < 20; i++)
            {
                OperatorID.OperatorID[i] = operatorId[i];
            }

        }
};