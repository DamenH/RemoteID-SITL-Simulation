#include <stdint.h>
#include <string>

#include "MessageBody.h"

struct MessageHeaderData {
    MessageHeaderData() : ProtocolVersion(0x0){}
    unsigned MessageType : 4;
    unsigned ProtocolVersion : 4;
};

class MessageHeader {
    public:
        struct MessageHeaderData header;

        MessageHeader(uint8_t messageType)
        {
            header.MessageType = messageType & 0xF;
        }

        json toJson()
        {
            json j;
            j["Message Type"] = "0x" + std::to_string(header.MessageType);
            j["Protocol Version"] = "0x" + std::to_string(header.ProtocolVersion);
            return j;

            // std::cout << "Message Type: " << header.MessageType << " ";
            // std::cout << "Protocol Version: " << header.ProtocolVersion << '\n';
            // // header.messageBody->Print();
            // std::cout << '\n';
        }
};