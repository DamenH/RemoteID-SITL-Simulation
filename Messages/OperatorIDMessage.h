#include <stdint.h>

struct OperatorIDMessageData {
    unsigned OperatorIDType : 8;
    uint8_t OperatorID[20];
    uint8_t Reserved[3];
};

class OperatorIDMessage: public MessageBody {
    public:

        struct OperatorIDMessageData operatorID;

        OperatorIDMessage(
            uint8_t operatorIdType,
            uint8_t operatorId[20]
        )
        {
            operatorID.OperatorIDType = operatorIdType;

            for(int i = 0; i < 20; i++)
            {
                operatorID.OperatorID[i] = operatorId[i];
            }

        };

        void Print() override
        {

        }
};