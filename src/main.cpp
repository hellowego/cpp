#include <iostream>
#include "../include/add.h"
#include "../include/sub.h"
#include "leetcode.h"
#include "Poco/DateTime.h"
using Poco::DateTime;
int main()
{
    // Poco::DateTime DateTime now;
    DateTime now;
    int year = now.dayOfWeek();
    std::cout << "5-2 = " << sub(5, 2) << std::endl;
    std::cout << "3/2 = " << 3 / 2 << std::endl;
    std::cout << "datetime: " << year << std::endl;
    return 0;
}