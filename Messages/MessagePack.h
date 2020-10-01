struct MessagePack {
    unsigned MessageSize : 8;
    unsigned NumberMessages : 8;
    unsigned Messages : 2000;
};