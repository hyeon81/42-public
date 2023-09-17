int main (int argc, char* argv[])
{
    // 1. socket(): 리스닝 소켓 생성
    //sockaddr_in은 소켓 주소의 틀을 형성해주는 구조체. AF_INET일 경우 사용
    struct sockaddr_in serv_addr;
    int serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
    {
        std::cout << "socker() error" << std::endl;
        return (-1);
    }

    // serv_addr의 주소 정보를 초기화, IP주소와 포트 지정
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; // IPv4 주소 체계 사용 
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // IP 주소 지정
    serv_addr.sin_port = htons(atoi(argv[1])); // 포트 번호 지정
    
    // 2. bind(): 소켓에 정보(IP주소, PORT번호? 얜 어디서?) 할당
    // 근데 왜 ip 주소 부분에 serv_addr이 들어가는 거지?
    if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
    {
        std::cout << "bind() error" << std::endl;
        return (-1);
    }

    // 3. listen(): 소켓을 리스닝 상태로 변경

    // 4. accept(): 클라이언트의 요청이 들어오면, 접속을 받는다
    // *5. close(): listen 중인 서버 측 소켓을 닫는다? (여기선 1개의 클라이언트만 받을거라)
    // *6. socket(): 데이터를 주고 받을 소켓 생성?
    // 7. read(): send/recv를 통해 데이터를 주고 받는다 (while문으로)
    // 8. write()
    // 9. read()
    // 10. close(): 클라이언트와 연결된 소켓을 닫는다

}