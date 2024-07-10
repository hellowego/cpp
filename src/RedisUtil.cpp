#include "RedisUtil.h"

RedisUtil::RedisUtil(std::string ip, int port, std::string passwd)
    : ip(ip), port(port), passwd(passwd)
{
}

RedisUtil::~RedisUtil()
{
}

std::string RedisUtil::getString(std::string key)
{
    return "hi";
}