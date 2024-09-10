#include <stdio.h>
#include <string.h>
#include <mysql/mysql.h>
#include "../config/db_config.h"

MYSQL *conn;

int db_connect(void) {
    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return 1;
    }

    if (mysql_real_connect(conn, DB_HOST, DB_USER, DB_PASS, DB_NAME, DB_PORT, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        mysql_close(conn);
        return 1;
    }

    return 0;
}

void db_disconnect(void) {
    mysql_close(conn);
}

int db_execute_query(const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query execution failed: %s\n", mysql_error(conn));
        return 1;
    }
    return 0;
}

MYSQL_RES* db_fetch_results(const char *query) {
    if (mysql_query(conn, query)) {
        fprintf(stderr, "Query execution failed: %s\n", mysql_error(conn));
        return NULL;
    }

    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        fprintf(stderr, "Failed to store result set: %s\n", mysql_error(conn));
        return NULL;
    }

    return result;
}

void db_free_result(MYSQL_RES *result) {
    mysql_free_result(result);
}
