#pragma once
#include <string>
#include <sqlite3.h>

class SQLite {
public:
    sqlite3* db;
    std::string dbPath;
    SQLite(const std::string& path);
    virtual ~SQLite();

    int openDatabase();
};

class SQLiteReader : public SQLite {
public:
    SQLiteReader(const std::string& path);
    std::string readAllRows(const std::string& query);
};

class SQLiteWriter : public SQLite {
public:
    SQLiteWriter(const std::string& path);
    std::string executeQuery(const std::string& query);
};

class SQLiteDel : public SQLite {
public:
    SQLiteDel(const std::string& path);
    std::string executeDelete(const std::string& query);
};

class SQLiteEdit: public SQLite {
public:
    SQLiteEdit(const std::string& path);
    std::string executeUpdate(const std::string& query);
};