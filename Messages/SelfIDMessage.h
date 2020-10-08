#include <stdint.h>

struct SelfIDMessageData {
    unsigned DescriptionType : 8;
    uint8_t Description[23];
} SelfID;

class SelfIDMessage {
    public:
        static void Encode(
            uint8_t descriptionType,
            uint8_t description[23]
        )
        {
            SelfID.DescriptionType = descriptionType;

            for(int i = 0; i < 23; i++)
            {
                SelfID.Description[i] = description[i];
            }
        };

        static void Copy(uint8_t selfIdMessage[24])
        {

        }
};