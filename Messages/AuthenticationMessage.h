#include <stdint.h>

struct AuthenticationMessageData {
    unsigned AuthType : 4;
    unsigned PageNumber : 4;
    unsigned PageCount : 8;
    unsigned Length : 8;
    uint8_t Timestamp[4];
    uint8_t AuthenticationData[17];
} Authentication;

class AuthenticationMessage {
    public:
        static void Encode(
            uint8_t authType, 
            uint8_t pageNumber,
            uint8_t pageCount,
            uint8_t length,
            uint8_t timestamp[4],
            uint8_t authenticationData[17]
        )
        {
            Authentication.AuthType = authType & 0xF;
            Authentication.PageNumber = pageNumber & 0xF;
            Authentication.PageCount = pageCount;
            Authentication.Length = length;

            for(int i = 0; i < 4; i++)
            {
                Authentication.Timestamp[i] = timestamp[i];
            }

            for(int i = 0; i < 17; i++)
            {
                Authentication.AuthenticationData[i] = authenticationData[i];
            }

        }
};