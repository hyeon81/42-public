FROM debian:bullseye

# wordpress에 필요한 패키지 설치
RUN apt-get update && apt-get -y install mariadb-client php8.2 php8.2-mysql php-cli mariadb-client curl && \
    rm -rf /var/lib/apt/lists/*

# wordpress 다운로드하기
RUN curl -O https://wordpress.org/latest.tar.gz && tar -xzf latest.tar.gz -C /var/www/html/

# # 압축풀고 이동, 권한 설정
# RUN cd /var/www && tar -xvf latest.tar.gz && rm -rf latest.tar.gz && \
#     chown -R www-data:www-data /var/www/html

# php fpm 설정 파일 수정 (외부에서도 php-fpm을 호출하도록)
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d

# # wp-config.php 파일 수정 -> 이걸 wp-cli를 사용해서 수정한듯
# COPY ./conf/wp-config.php /var/www/html/wp-config.php

# wp-cli 설치
RUN curl https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar --output /usr/bin/wp --silent

# wp-cli 실행 권한 부여
RUN chmod +x ./usr/bin/wp

# php-fpm 실행을 위한 폴더 생성
RUN mkdir /run/php

# wp-config.php 파일 수정
COPY ./conf/config.sh /var/www/html/config.sh

# 실행 권한 부여
RUN chmod +x /var/www/html/config.sh
CMD ["bash", "/var/www/html/config.sh"]

EXPOSE 9000
