# #사용할 이미지
# FROM debian:bullseye

# COPY ./conf/50-server.cnf /conf_file
#     # mysql 서비스 시작
# COPY ./conf/config.sh /script.sh

# # mariadb 설치
# RUN apt-get update && apt-get install -y mariadb-server && \
#     rm -rf /var/lib/apt/lists/* && chmod +x /script.sh
#     # mariadb 서버의 bind-address 주소를 주석 처리해준다. 이를 해주질 않을 경우 외부 ip에서 접근할 수 없게 된다.

# EXPOSE 3306

# CMD ["/script.sh"]

FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

#아무데나 옮겨도 되나?
COPY ./tools/script.sh /script.sh

RUN rm -rf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN chmod +x /script.sh

ENTRYPOINT ["/script.sh"]