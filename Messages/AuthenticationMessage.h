struct AuthenticationMessage {
    unsigned AuthType : 4;
    unsigned PageNumber : 4;
    unsigned PageCount : 8;
    unsigned Length : 8;
    unsigned Timestamp : 32;
    unsigned AuthenticationData : 144;
};