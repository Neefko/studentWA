#include <iostream>
#include "sqlite_helper.h"

// Реализация класса SQLite
SQLite::SQLite(const std::string& path) : db(nullptr), dbPath(path) {}

SQLite::~SQLite() {
    if (db) {
        sqlite3_close(db);
    }
}

int SQLite::openDatabase() {
    return sqlite3_open(dbPath.c_str(), &db);
}

// Реализация SQLiteReader
SQLiteReader::SQLiteReader(const std::string& path) : SQLite(path) {}

std::string SQLiteReader::readAllRows(const std::string& query) {
    sqlite3_stmt* stmt;
    std::string result;

    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int columns = sqlite3_column_count(stmt);
        for (int i = 0; i < columns; i++) {
            const char* value = reinterpret_cast<const char*>(sqlite3_column_text(stmt, i));
            result += (value ? value : "NULL");
            if (i < columns - 1) {
                result += ", ";
            }
        }
        result += "\n";
    }

    sqlite3_finalize(stmt);
    return result;
}

// Реализация SQLiteWriter
SQLiteWriter::SQLiteWriter(const std::string& path) : SQLite(path) {}

std::string SQLiteWriter::executeQuery(const std::string& query) {
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return "Suc";
}

// Реализация SQLiteDel
SQLiteDel::SQLiteDel(const std::string& path) : SQLite(path) {}

std::string SQLiteDel::executeDelete(const std::string& query) {
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return "Suc";
}

// Реализация SQLiteEdit
SQLiteEdit::SQLiteEdit(const std::string& path) : SQLite(path) {}

std::string SQLiteEdit::executeUpdate(const std::string& query) {
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return "Suc";
}

