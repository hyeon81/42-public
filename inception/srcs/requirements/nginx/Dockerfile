#사용할 이미지
FROM debian:bullseye

# nginx 설치
RUN apt-get update && apt-get install -y nginx openssl && \
	 rm -rf /var/lib/apt/lists/*

# self-signed ssl 인증서 만들기
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/ssl/private/server_pkey.pem -out /etc/ssl/certs/server.crt -subj "/C=UK/ST=Warwickshire/L=Leamington/O=OrgName/OU=IT Department/CN=hyeokim2.42.fr"

COPY ./conf/default.conf /etc/nginx/sites-available/default

# nginx 실행
CMD [ "nginx", "-g", "daemon off;"]

EXPOSE 443
