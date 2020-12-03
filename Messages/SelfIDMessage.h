#include <stdint.h>

struct selfIDMessageData {
    unsigned descriptionType : 8;
    char description[23];
};

class SelfIDMessage: public MessageBody {
    public:

        struct selfIDMessageData selfID;

        SelfIDMessage(
            uint8_t descriptionType,
            char description[23]
        )
        {
            selfID.descriptionType = descriptionType;

            for(int i = 0; i < 23; i++)
            {
                selfID.description[i] = description[i];
            }
        };

        json toJson() override
        {
            json j;
            j["Description Type"] = std::to_string(selfID.descriptionType);
            j["UAS ID"] = selfID.description;
            return j;
        }
};