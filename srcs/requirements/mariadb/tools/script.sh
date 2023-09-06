#!/bin/bash

echo "echo mariadb start"
service mariadb start

mariadb -u root -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
mariadb -u root -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
mariadb -u root -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
# mariadb -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${db1_pwd}';"
mariadb -u root -e "FLUSH PRIVILEGES;"

echo "echo mariadb stop"
service mariadb stop
echo "echo mariadbd"

mariadbd
