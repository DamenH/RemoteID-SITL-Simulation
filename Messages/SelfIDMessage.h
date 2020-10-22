#include <stdint.h>

struct selfIDMessageData {
    unsigned descriptionType : 8;
    uint8_t description[23];
};

class SelfIDMessage: public MessageBody {
    public:

        struct selfIDMessageData selfID;

        SelfIDMessage(
            uint8_t descriptionType,
            uint8_t description[23]
        )
        {
            selfID.descriptionType = descriptionType;

            for(int i = 0; i < 23; i++)
            {
                selfID.description[i] = description[i];
            }
        };

        void Print() override
        {

        }
};