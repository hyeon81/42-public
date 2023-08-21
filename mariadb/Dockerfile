#사용할 이미지
FROM debian:bullseye

# mariadb 설치
RUN apt-get update && apt-get install -y mariadb-server vim\
    # && rm -rf /var/lib/apt/lists/*
    # mariadb 서버의 bind-address 주소를 주석 처리해준다. 이를 해주질 않을 경우 외부 ip에서 접근할 수 없게 된다.
    && sed -i 's/^\(bind-address\s.*\)/# \1/' /etc/mysql/mariadb.conf.d/50-server.cnf \
    # mysql 서비스 시작
RUN service mysql start \
    # mysql db, user 생성
    && mysql -u root -e "CREATE DATABASE ${MARIADB_NAME};" \
    && mysql -u root -e "CREATE USER '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';" \
    && mysql -u root -e "GRANT ALL PRIVILEGES ON ${MARIADB_NAME}.* TO '${MARIADB_USER}'@'%';" \
    && mysql -u root -e "FLUSH PRIVILEGES;" \
    # && mysql -u root -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"

# VOLUME [ "/data" ]

# WORKDIR /data

# CMD [ "executable" ]

# ENTRYPOINT [ "executable" ]

EXPOSE 3306

