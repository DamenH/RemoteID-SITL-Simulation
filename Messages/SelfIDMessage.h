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

        void Print() override
        {
            std::cout << "SelfID Message" << '\n';
            std::cout << " Description Type: " << selfID.descriptionType << '\n';
            std::cout << " UAS ID: ";
            for(int i = 0; i < 23; i++)
            {
                std::cout << selfID.description[i];
            }
            std::cout << '\n';
        }
};