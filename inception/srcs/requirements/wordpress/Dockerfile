FROM debian:bullseye

# wordpress에 필요한 패키지 설치
RUN apt-get update && apt-get -y install php php-mysql php-fpm php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip curl mariadb-client sudo && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html

# php fpm 설정 파일 수정 (외부에서도 php-fpm을 호출하도록)
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d

# wp-cli 설치
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp --silent

RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

# wp-cli 실행 권한 부여
RUN chmod +x /usr/bin/wp

# php-fpm 실행을 위한 폴더 생성
RUN mkdir /run/php

# php-fpm 실행
COPY ./tool/script.sh /script.sh

# 실행 권한 부여
RUN chmod +x /script.sh

EXPOSE 9000

CMD ["/script.sh"]
