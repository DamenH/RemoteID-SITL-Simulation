#include <stdint.h>

struct locationVectorMessageData {
    unsigned status : 4;
    unsigned flags : 4;
    uint8_t trackDirection;
    uint8_t speed;
    uint8_t verticalSpeed;
    uint8_t latitude[4];
    uint8_t longitude[4];
    uint8_t pressureAltitude[2];
    uint8_t geodeticAltitude[2];
    uint8_t height[2];
    unsigned verticalAccuracy : 4;
    unsigned horizontalAccuracy : 4;
    unsigned baroAltitudeAccuracy : 3;
    unsigned speedAccuracy : 3;
    uint8_t timestamp[2];
    unsigned reserved23 : 4;
    unsigned timestampAccuracy : 4;
    uint8_t reserved24;
};

class LocationVectorMessage: public MessageBody {
    public:
        struct locationVectorMessageData locationVector;

        LocationVectorMessage(
            uint8_t status,
            uint8_t flags,
            uint8_t trackDirection,
            uint8_t speed,
            uint8_t verticalSpeed,
            uint8_t latitude[4],
            uint8_t longitude[4],
            uint8_t pressureAltitude[2],
            uint8_t geodeticAltitude[2],
            uint8_t height[2],
            uint8_t verticalAccuracy,
            uint8_t horizontalAccuracy,
            uint8_t baroAltitudeAccuracy,
            uint8_t speedAccuracy,
            uint8_t timestamp[2],
            uint8_t timestampAccuracy
        )
        {
            locationVector.status = status;
            locationVector.flags = flags;
            locationVector.trackDirection = trackDirection;
            locationVector.speed = speed;
            locationVector.verticalSpeed = verticalSpeed;
            locationVector.verticalAccuracy = verticalAccuracy;
            locationVector.horizontalAccuracy = horizontalAccuracy;
            locationVector.baroAltitudeAccuracy = baroAltitudeAccuracy;
            locationVector.speedAccuracy = speedAccuracy;
            locationVector.timestampAccuracy = timestampAccuracy;

            for(int i = 0; i < 4; i++)
            {
                locationVector.latitude[i] = latitude[i];
                locationVector.longitude[i] = longitude[i];
            }

            for(int i = 0; i < 2; i++)
            {
                locationVector.pressureAltitude[i] = pressureAltitude[i];
                locationVector.geodeticAltitude[i] = geodeticAltitude[i];
                locationVector.height[i] = height[i];
                locationVector.timestamp[i] = timestamp[i];
            }

            

        };

        void Print() override
        {
            std::cout << "Location Vector Message" << '\n';
            std::cout << " Status: " << locationVector.status << '\n';
            std::cout << " Flags: " << locationVector.flags << '\n';
            std::cout << " Track Direction: " << locationVector.trackDirection << '\n';
            std::cout << " Speed: " << locationVector.speed << '\n';
            std::cout << " Vertical Speed: " << locationVector.verticalSpeed << '\n';
            std::cout << " Latitude: ";
            std::cout << *(uint32_t *)&locationVector.latitude << "\n";
            std::cout << " Longitude: ";
            std::cout << *(uint32_t *)&locationVector.longitude << "\n";
            std::cout << " Pressure Altitude: ";
            std::cout << *(uint32_t *)&locationVector.pressureAltitude << "\n";
            std::cout << " Geodetic Altitude: ";
            std::cout << *(uint32_t *)&locationVector.geodeticAltitude << "\n";
            std::cout << " Height: ";
            std::cout << *(uint32_t *)&locationVector.height << "\n";
            std::cout << " Vertical Accuracy: " << locationVector.verticalAccuracy << '\n';
            std::cout << " Horizontal Accuracy: " << locationVector.horizontalAccuracy << '\n';
            std::cout << " Baro Accuracy: " << locationVector.baroAltitudeAccuracy << '\n';
            std::cout << " Speed Accuracy: " << locationVector.speedAccuracy << '\n';
            std::cout << " Timestamp: ";
            std::cout << *(uint32_t *)&locationVector.timestamp << "\n";
            std::cout << " Timestamp Accuracy: " << locationVector.timestampAccuracy << '\n';


        }

};