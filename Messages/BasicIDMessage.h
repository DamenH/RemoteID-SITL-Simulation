struct BasicIDMessage {
    unsigned IDType : 4;
    unsigned UASType : 4;
    unsigned UASID : 160;
    unsigned Reserve :24;
};