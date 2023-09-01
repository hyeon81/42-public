FROM debian:bullseye

# wordpress에 필요한 패키지 설치
RUN apt-get update && apt-get -y install php php-mysql php-fpm php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip curl mariadb-client && \
    rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html

# wordpress 다운로드하기
COPY https://wordpress.org/latest.tar.gz /var/www/html/latest.tar.gz

RUN cd /var/www/html && tar -xvf latest.tar.gz && \
    rm -rf latest.tar.gz

RUN chown -R www-data.www-data /var/www/html/wordpress
RUN chmod -R 755 /var/www/html/wordpress

# php fpm 설정 파일 수정 (외부에서도 php-fpm을 호출하도록)
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d

# wp-cli 설치
RUN curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp --silent

# wp-cli 실행 권한 부여
RUN chmod +x /usr/bin/wp

# php-fpm 실행을 위한 폴더 생성
RUN mkdir /run/php

# wp-config.php 파일 수정
COPY ./conf/config.sh /var/www/html/config.sh

# 실행 권한 부여
RUN chmod +x /var/www/html/config.sh

CMD ["/var/www/html/config.sh"]

