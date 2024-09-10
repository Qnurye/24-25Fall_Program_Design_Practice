#ifndef DATABASE_H
#define DATABASE_H

#include <mysql/mysql.h>

extern MYSQL *conn;

int db_connect(void);

void db_disconnect(void);

int db_execute_query(const char *query);

MYSQL_RES *db_fetch_results(const char *query);

void db_free_result(MYSQL_RES *result);

#endif // DATABASE_H
