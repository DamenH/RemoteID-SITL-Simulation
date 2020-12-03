#include "../json.hpp"
using json = nlohmann::json;

class MessageBody {
    public:
        virtual json toJson(){
            json j;
            return j;
        }
};