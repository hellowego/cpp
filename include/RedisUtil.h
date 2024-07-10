#include <string>

class RedisUtil
{
private:
    /* data */
    std::string ip;
    int port;
    std::string passwd;

public:
    RedisUtil(std::string ip, int port, std::string passwd);
    std::string getString(std::string key);
    ~RedisUtil();
};
