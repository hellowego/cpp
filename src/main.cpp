#include <iostream>
#include "../include/add.h"
#include "../include/sub.h"
#include "leetcode.h"
#include "Poco/DateTime.h"

#include "Poco/Data/SQLite/SQLite.h"
#include "Poco/Data/Session.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/SessionFactory.h"
#include "Poco/Data/RecordSet.h"
#include "Poco/Data/Column.h"
#include <vector>

using namespace std;

using Poco::DateTime;

void test()
{

    cout << "Hello World!" << endl;

    Poco::Data::SQLite::Connector::registerConnector();

    Poco::Data::Session session("SQLite", "test.db");

    std::string sql = "SELECT id,name,passwd FROM user";

    Poco::Data::Statement select(session);
    select << sql;
    select.execute();
    Poco::Data::RecordSet rs(select);
    std::size_t cols = rs.columnCount();

    for (std::size_t i = 0; i < cols; ++i)
    {
        std::cout << rs.columnName(i) << std::endl;
    }

    bool more = rs.moveFirst();
    while (more)
    {
        for (std::size_t i = 0; i < cols; ++i)
        {
            std::cout << rs[i].convert<std::string>() << " ";
        }
        std::cout << std::endl;
        more = rs.moveNext();
    }

    Poco::Data::SQLite::Connector::unregisterConnector();
}

int main()
{
    test();
    // Poco::DateTime DateTime now;
    DateTime now;
    int year = now.dayOfWeek();
    std::cout << "5-2 = " << sub(5, 2) << std::endl;
    std::cout << "3/2 = " << 3 / 2 << std::endl;
    std::cout << "datetime: " << year << std::endl;
    return 0;
}
