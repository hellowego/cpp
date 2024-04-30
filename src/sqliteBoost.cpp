#include "sqliteBoost.h"
#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <sqlite3.h>

void query_sqlite(boost::asio::io_service &io_service, const std::string &db_path)
{
    sqlite3 *db = nullptr;
    int result = sqlite3_open(db_path.c_str(), &db);
    if (result != SQLITE_OK)
    {
        std::cerr << "Cannot open database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return;
    }

    const char *sql = "SELECT id,name,passwd FROM user;";
    sqlite3_stmt *stmt;
    result = sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr);
    if (result != SQLITE_OK)
    {
        std::cerr << "Failed to prepare statement: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_finalize(stmt);
        sqlite3_close(db);
        return;
    }

    // 异步执行SQL查询
    io_service.post([stmt, db]()
                    {
        int result = sqlite3_step(stmt);
        if (result == SQLITE_ROW) {
            // 处理结果集
            do {
                // 例如，获取列数据
                int column_count = sqlite3_column_count(stmt);
                for (int i = 0; i < column_count; ++i) {
                    std::cout << sqlite3_column_text(stmt, i) << " ";
                }
                std::cout << std::endl;
            } while (sqlite3_step(stmt) == SQLITE_ROW);
        }
 
        sqlite3_finalize(stmt);
        sqlite3_close(db); });
}
