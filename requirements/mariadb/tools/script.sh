#!/bin/bash

service mariadb start

mysql -u root "CREATE DATABASE ${DB_NAME};"
mysql -u root "CREATE USER '${DB_USER}'@'localhost' IDENTIFIED BY '${DB_PASSWORD}';"
mysql -u root "GRANT ALL ON . TO '${DB_NAME}'@'localhost' WITH GRANT OPTION;"
mysql -u root "FLUSH PRIVILEGES;"

