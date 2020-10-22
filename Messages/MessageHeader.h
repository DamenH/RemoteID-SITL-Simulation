#include <stdint.h>
#include <iostream>

#include "MessageBody.h"

struct MessageHeaderData {
    MessageHeaderData() : ProtocolVersion(0x0){}
    unsigned MessageType : 4;
    unsigned ProtocolVersion : 4;
    MessageBody *messageBody;
};

class MessageHeader {
    public:
        struct MessageHeaderData header;

        MessageHeader(
            uint8_t messageType,
            MessageBody *messageBody
        )
        {
            header.MessageType = messageType & 0xF;
            header.messageBody = messageBody;
        }

        void Print()
        {
            std::cout << "Message Type: " << header.MessageType << '\n';
            std::cout << "Protocol Version: " << header.ProtocolVersion << '\n';
            header.messageBody->Print();
            std::cout << '\n';
        }
};