#!/bin/bash

service mysql start

mysql -u root "CREATE USER 'hyeokim2'@'localhost' IDENTIFIED BY '0801';"
mysql -u root "GRANT ALL ON . TO 'hyeokim2'@'localhost' WITH GRANT OPTION;"
mysql -u root "FLUSH PRIVILEGES;"
mysql -u root "CREATE DATABASE testdb;"

