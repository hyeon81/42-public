FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server mariadb-client&& \
    rm -rf /var/lib/apt/lists/*

#아무데나 옮겨도 되나?
COPY ./tools/script.sh /script.sh

RUN rm -rf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN chmod +x /script.sh

CMD ["/script.sh"]

EXPOSE 3306