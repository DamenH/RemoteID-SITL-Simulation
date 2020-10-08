#include <stdint.h>

struct MessagePackData {
    unsigned MessageSize : 8;
    unsigned NumberMessages : 8;
    uint8_t Messages[250];
} Pack;

class MessagePack {
    public:
        static void Encode(
            uint8_t messageSize,
            uint8_t numberMessages,
            uint8_t messages[250]
        )
        {
            Pack.MessageSize = messageSize;
            Pack.NumberMessages = numberMessages;

            for(int i = 0; i < 250; i++)
            {
                Pack.Messages[i] = messages[i];
            }

        }
};