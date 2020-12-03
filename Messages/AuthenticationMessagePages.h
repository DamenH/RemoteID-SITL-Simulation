#include <stdint.h>

struct authenticationMessagePagesData {
    unsigned authType : 4;
    unsigned pageNumber : 4;
    uint8_t authenticationData[23];
};

class AuthenticationMessagePages: public MessageBody {
    public:

        struct authenticationMessagePagesData authenticationPages;

        AuthenticationMessagePages(
            uint8_t authType,
            uint8_t pageNumber,
            uint8_t authenticationData[23]
        )
        {
            authenticationPages.authType = authType;
            authenticationPages.pageNumber = pageNumber;

            for(int i = 0; i < 23; i++)
            {
                authenticationPages.authenticationData[i] = authenticationData[i];
            }
        };

        json toJson() override
        {
            json j;
            j["Auth Type"] = std::to_string(authenticationPages.authType);
            j["Page Number"] = std::to_string(authenticationPages.pageNumber);
            j["Authentication Data"] = "...";
            return j;
        }
};