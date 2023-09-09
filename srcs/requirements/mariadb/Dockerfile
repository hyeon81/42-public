FROM debian:bullseye

RUN apt-get update && apt-get upgrade && apt-get install -y mariadb-server mariadb-client && rm -rf /var/lib/apt/lists/*

COPY ./tools/script.sh /script.sh

RUN rm -rf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/

RUN chmod +x /script.sh

CMD ["/script.sh"]

EXPOSE 3306