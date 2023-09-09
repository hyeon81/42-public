#!/bin/bash

chown -R www-data:www-data /var/www/html/
chmod -R 755 /var/www/html/
rm -rf /var/www/html/*

sudo -u www-data sh -c "wp core download --path=/var/www/html/wordpress"

cd /var/www/html/wordpress

sudo -u www-data sh -c "wp config create --dbhost=$DB_HOST \
                --dbname=$DB_NAME \
                --dbuser=$DB_USER \
                --dbpass=$DB_PASSWORD"

sudo -u www-data sh -c "wp core install --title=$WP_TITLE \
                --admin_user=$WP_ADMIN_USER \
                --admin_password=$WP_ADMIN_PASSWORD \
                --admin_email=$WP_ADMIN_MAIL \
                --url=$WP_URL"

sudo -u www-data sh -c "wp user create $WP_USER $WP_USER_MAIL --role=author --user_pass=$WP_USER_PASSWORD"

php-fpm7.4 -F
