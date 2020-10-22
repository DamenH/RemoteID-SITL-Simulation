#include <stdint.h>
#include <iostream>

struct basicMessageData {
    unsigned idType : 4;
    unsigned uaType : 4;
    uint8_t uasId[20];
    uint8_t reserve[3];
};

class BasicIDMessage: public MessageBody {
    public:

        struct basicMessageData basicIDMessage;

        BasicIDMessage(
           uint8_t idType,
           uint8_t uaType,
           uint8_t uasId[20]
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

        void Print() override
        {
            std::cout << "\nBasicID Message" << '\n';
            std::cout << " ID Type: " << basicIDMessage.idType << '\n';
            std::cout << " UA Type: " << basicIDMessage.uaType << '\n';
            std::cout << " UAS ID: ";
            for(int i = 0; i < 20; i++)
            {
                std::cout << basicIDMessage.uasId[i];
            }
            std::cout << '\n';
        }
};