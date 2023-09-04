#!/bin/bash

# WordPress 다운로드
echo "wp core download"
# 파일 및 디렉토리 권한 설정
chown -R www-data:www-data /var/www/html/
chmod -R 755 /var/www/html/
rm -rf /var/www/html/*

sudo -u www-data sh -c "wp core download --path=/var/www/html/wordpress"

echo "cd /var/www/html/wordpress"

cd /var/www/html/wordpress

sudo -u www-data sh -c "wp config create --dbhost=mariadb \
                --dbname=wp_wordpressdb \
                --dbuser=hyeokim2 \
                --dbpass=0801"

# WordPress 설치
sudo -u www-data sh -c "wp core install --title=hyeokim2blog \
                --admin_user=hyeokim2 \
                --admin_password=0801 \
                --admin_email=hyeokim2@42seoul.kr \
                --url=hyeokim2.42.fr"

# 사용자 생성

# WordPress 설정
# sudo -u www-data sh -c "wp config create --dbhost=$DB_HOST \
#                 --dbname=$DB_NAME \
#                 --dbuser=$DB_USER \
#                 --dbpass=$DB_PASSWORD"

# # WordPress 설치
# sudo -u www-data sh -c "wp core install --title=$WP_TITLE \
#                 --admin_user=$WP_ADMIN_USER \
#                 --admin_password=$WP_ADMIN_PASSWORD \
#                 --admin_email=$WP_ADMIN_MAIL \
#                 --url=$WP_URL"

# # 사용자 생성
# sudo -u www-data sh -c "wp user create $WP_USER $WP_USER_MAIL --role=author --user_pass=$WP_USER_PASSWORD"

# php-fpm 백그라운드로 실행
php-fpm7.4 -F
