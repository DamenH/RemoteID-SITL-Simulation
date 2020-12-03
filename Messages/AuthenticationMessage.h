#include <stdint.h>

struct authenticationMessageData {
    unsigned authType : 4;
    unsigned pageNumber : 4;
    unsigned pageCount : 8;
    unsigned length : 8;
    uint32_t timestamp;
    uint8_t authenticationData[17];
};

class AuthenticationMessage: public MessageBody {
    public:

        struct authenticationMessageData authentication;
        
        AuthenticationMessage(
            uint8_t authType, 
            uint8_t pageNumber,
            uint8_t pageCount,
            uint8_t length,
            uint32_t timestamp,
            uint8_t authenticationData[17]
        )
        {
            authentication.authType = authType;
            authentication.pageNumber = pageNumber;
            authentication.pageCount = pageCount;
            authentication.length = length;
            authentication.timestamp = timestamp;

            for(int i = 0; i < 17; i++)
            {
                authentication.authenticationData[i] = authenticationData[i];
            }

        };

        json toJson() override
        {
            json j;
            j["Auth Type"] = std::to_string(authentication.authType);
            j["Page Number"] = std::to_string(authentication.pageNumber);
            j["Page Count"] = std::to_string(authentication.pageCount);
            j["Length"] = std::to_string(authentication.length);
            j["Timestamp"] = std::to_string(authentication.timestamp);
            j["Authentication Data"] = "...";
            return j;

        }
};