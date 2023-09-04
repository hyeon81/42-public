#!/bin/bash


# MySQL 데이터베이스 초기화 및 폴더 준비
rm -rf /var/lib/mysql/*
mysql_install_db
mkdir -p /run/mysqld
chown -R mysql:mysql /var/lib/mysql
chown -R mysql:mysql /run/mysqld

service mariadb start

# MySQL에 SQL 명령어를 실행하는 부분을 mysql.sql 파일로 이동
cat <<EOF > mysql.sql
CREATE DATABASE ${DB_NAME};
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

# SQL 파일을 MySQL에 적용
mysql -u root < mysql.sql

# MySQL 실행
mysqld
# mysql
