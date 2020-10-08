#include <stdint.h>

struct LocationVectorMessageData {
    unsigned Status : 4;
    unsigned Flags : 4;
    unsigned TrackDirection : 8;
    unsigned Speed : 8;
    unsigned VerticalSpeed : 8;
    unsigned Latitude : 32;
    unsigned Longitude : 32;
    unsigned PressureAltitude : 16;
    unsigned GeodeticAltitude : 16;
    unsigned Height : 16;
    unsigned VerticalAccuracy : 4;
    unsigned HorizontalAccuracy : 4;
    unsigned BaroAltitudeAccuracy : 3;
    unsigned SpeedAccuracy : 3;
    unsigned Timestamp : 16;
    unsigned Reserved23 : 4;
    unsigned TimestampAccuracy : 4;
    unsigned Reserved24 : 8;
} LocationVector;

class LocationVectorMessage {
    public:
        static void Encode(

        )
        {

        };

        static void Copy(uint8_t locationVectorMessage[24])
        {

        }
};