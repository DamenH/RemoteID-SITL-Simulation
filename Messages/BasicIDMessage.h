#include <stdint.h>

struct basicMessageData {
    unsigned idType : 4;
    unsigned uaType : 4;
    char uasId[20];
    uint8_t reserve[3];
};

class BasicIDMessage: public MessageBody {
    public:

        struct basicMessageData basicIDMessage;

        BasicIDMessage(
           uint8_t idType,
           uint8_t uaType,
           char uasId[20]
        )
       {
            basicIDMessage.idType = idType;
            basicIDMessage.uaType = uaType;

            for(int i = 0; i < 20; i++)
            {
                basicIDMessage.uasId[i] = uasId[i];
            }

            uint8_t reserve[3] = {0,0,0};

            for(int i = 0; i < 3; i++)
            {
                basicIDMessage.reserve[i] = reserve[i];
            }

        };

        json toJson() override
        {
            json j;
            j["ID Type"] = std::to_string(basicIDMessage.idType);
            j["UA Type"] = std::to_string(basicIDMessage.uaType);
            j["UAS ID"] = basicIDMessage.uasId;
            return j;
        }
};