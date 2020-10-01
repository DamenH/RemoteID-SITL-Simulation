struct MessageHeader {
    MessageHeader() : ProtocolVersion(0x0){}
    unsigned MessageType : 4; // 0x1-0xF
    unsigned ProtocolVersion : 4; // Always 0x0;
};