#include <stdint.h>

struct MessagePackData {
    unsigned MessageSize : 8;
    unsigned NumberMessages : 8;
    uint8_t Messages[250];
};

class MessagePack {
    public:

        struct MessagePackData pack;

        MessagePack(
            uint8_t messageSize,
            uint8_t numberMessages,
            uint8_t messages[250]
        )
        {
            pack.MessageSize = messageSize;
            pack.NumberMessages = numberMessages;

            for(int i = 0; i < 250; i++)
            {
                pack.Messages[i] = messages[i];
            }

        }
};