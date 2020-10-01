struct AuthenticationMessagePages {
    unsigned AuthType : 4;
    unsigned PageNumber : 4;
    unsigned AuthenticationData : 184;
};