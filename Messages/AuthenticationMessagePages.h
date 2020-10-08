#include <stdint.h>

struct AuthenticationMessagePagesData {
    unsigned AuthType : 4;
    unsigned PageNumber : 4;
    uint8_t AuthenticationData[23];
} AuthenticationPages;

class AuthenticationMessagePages {
    public:
        static void Encode(
            uint8_t authType,
            uint8_t pageNumber,
            uint8_t authenticationData[23]
        )
        {
            AuthenticationPages.AuthType = authType & 0xF;
            AuthenticationPages.PageNumber = pageNumber & 0xF;

            for(int i = 0; i < 23; i++)
            {
                AuthenticationPages.AuthenticationData[i] = authenticationData[i];
            }
        }
};