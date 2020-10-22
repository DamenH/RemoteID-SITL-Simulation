#include <stdint.h>

struct authenticationMessageData {
    unsigned authType : 4;
    unsigned pageNumber : 4;
    unsigned pageCount : 8;
    unsigned length : 8;
    uint8_t timestamp[4];
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
            uint8_t timestamp[4],
            uint8_t authenticationData[17]
        )
        {
            authentication.authType = authType;
            authentication.pageNumber = pageNumber;
            authentication.pageCount = pageCount;
            authentication.length = length;

            for(int i = 0; i < 4; i++)
            {
                authentication.timestamp[i] = timestamp[i];
            }

            for(int i = 0; i < 17; i++)
            {
                authentication.authenticationData[i] = authenticationData[i];
            }

        };

        void Print() override
        {
            std::cout << "\nAuthentication Message" << '\n';
            std::cout << " Auth Type: " << authentication.authType << '\n';
            std::cout << " Page Number: " << authentication.pageNumber << '\n';
            std::cout << " Page Count: " << authentication.pageCount << '\n';
            std::cout << " Length: " << authentication.length << '\n';
            std::cout << " Timestamp: ";
            for(int i = 0; i < 4; i++)
            {
                std::cout << authentication.timestamp[i];
            }
            std::cout << " Authentication Data: ";
            for(int i = 0; i < 17; i++)
            {
                std::cout << authentication.authenticationData[i];
            }
            std::cout << '\n';

        }
};