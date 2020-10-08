#include <stdint.h>

struct MessageHeaderData {
    MessageHeaderData() : ProtocolVersion(0x0){}
    unsigned MessageType : 4;
    unsigned ProtocolVersion : 4;
    uint8_t MessageData[24];
} Header;

class MessageHeader {
    public:
        static void Encode(
            uint8_t messageType,
            uint8_t messageData[24]
        )
        {
            Header.MessageType = messageType & 0xF;

            for(int i = 0; i < 24; i++)
            {
                Header.MessageData[i] = messageData[i];
            }
        }
};