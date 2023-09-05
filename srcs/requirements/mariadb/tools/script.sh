#!/bin/bash

#!/bin/bash

service mariadb start

mariadb -u root -e "CREATE DATABASE IF NOT EXISTS ${DB_NAME};"
mariadb -u root -e "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
mariadb -u root -e "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';"
# mariadb -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${db1_pwd}';"
mariadb -u root -e "FLUSH PRIVILEGES;"

service mariadb stop
mariadbd

# MySQL 데이터베이스 초기화 및 폴더 준비
# rm -rf /var/lib/mysql/*
# mysql_install_db
# mkdir -p /run/mysqld
# chown -R mysql:mysql /var/lib/mysql
# chown -R mysql:mysql /run/mysqld

# service mysql start

# MySQL에 SQL 명령어를 실행하는 부분을 mysql.sql 파일로 이동
# cat <<EOF > mysql.sql
# CREATE DATABASE ${DB_NAME};
# CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
# GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
# FLUSH PRIVILEGES;
# EOF

# cat <<EOF > mysql.sql
# CREATE DATABASE wordpressdb;
# CREATE USER 'hyeokim2'@'%' IDENTIFIED BY '*hyeon0801';
# GRANT ALL PRIVILEGES ON wordpressdb.* TO 'hyeokim2'@'%';
# FLUSH PRIVILEGES;
# ALTER USER 'root'@'localhost' IDENTIFIED BY '*hyeon0801';
# EOF

# service mysql start
# echo "CREATE DATABASE IF NOT EXISTS ${DB_NAME};" > /root/init_db.sql
# echo "CREATE USER IF NOT EXISTS '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';" >> /root/init_db.sql
# echo "GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';" >> /root/init_db.sql \
# echo "FLUSH PRIVILEGES;" >> /root/init_db.sql \
# echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';" >> /root/init_db.sql \
# DB -hlocalhost -u root -p${DB_ROOT_PASSWORD} -e "source /root/init_db.sql;" && \
# rm /root/init_db.sql

# mysql -hlocalhost -u root -p${DB_ROOT_PASSWORD} -e "/mysql.sql";

# SQL 파일을 MySQL에 적용
# mysql -u root < mysql.sql

# MySQL 실행
# mysqld
# mysql
