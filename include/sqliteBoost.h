#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <sqlite3.h>

void query_sqlite(boost::asio::io_service &io_service, const std::string &db_path);
