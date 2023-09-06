FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/*

RUN rm -rf /var/lib/mysql/* 

RUN mariadb-install-db && mkdir -p /run/mysqld

RUN chown -R mysql:mysql /var/lib/mysql && chown -R mysql:mysql /run/mysqld

COPY ./tools/script.sh /script.sh

RUN rm -rf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

RUN chmod +x /script.sh

CMD ["/script.sh"]

EXPOSE 3306
