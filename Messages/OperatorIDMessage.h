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

        json toJson() override
        {
            json j;
            j["OperatorID Type"] = std::to_string(operatorID.operatorIdType);
            j["Operator ID"] = operatorID.operatorId;
            return j;
        }
};