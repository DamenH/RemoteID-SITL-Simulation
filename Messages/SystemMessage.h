struct SystemMessage {
    unsigned Flags : 8;
    unsigned OperatorLatitude : 32;
    unsigned OperatorLongitude : 32;
    unsigned AreaCount : 16;
    unsigned AreaRadius : 8;
    unsigned AreaCeiling : 16;
    unsigned AreaFloor : 16;
    unsigned Reserved : 64;
};