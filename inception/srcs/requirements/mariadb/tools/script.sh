#!/bin/bash

rm -rf /var/lib/mysql/*
mysql_install_db
mkdir -p /run/mysqld
chown -R mysql:mysql /var/lib/mysql
chown -R mysql:mysql /run/mysqld

service mariadb start

mariadb -u root -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
mariadb -u root -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
mariadb -u root -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
mariadb -u root -e "FLUSH PRIVILEGES;"

service mariadb stop

mariadbd
