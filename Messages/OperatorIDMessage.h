#include <stdint.h>

struct operatorIDMessageData {
    unsigned operatorIdType : 8;
    char operatorId[20];
    uint8_t reserved[3];
};

class OperatorIDMessage: public MessageBody {
    public:

        struct operatorIDMessageData operatorID;

        OperatorIDMessage(
            uint8_t operatorIdType,
            char operatorId[20]
        )
        {
            operatorID.operatorIdType = operatorIdType;

            for(int i = 0; i < 20; i++)
            {
                operatorID.operatorId[i] = operatorId[i];
            }

        };

        void Print() override
        {
            std::cout << "OperatorID Message" << '\n';
            std::cout << " nOperatorID Type: " << operatorID.operatorIdType << '\n';
            std::cout << " Operator ID: ";
            for(int i = 0; i < 20; i++)
            {
                std::cout << operatorID.operatorId[i];
            }
            std::cout << '\n';
        }
};