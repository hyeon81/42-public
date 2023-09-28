#include "Message.hpp"

Message::Message(std::string msg): msg(msg)
{
    //어차피 클라이언트가 버퍼를 가지고 갈 거잖음
    //그리고 그 내용을 바탕으로 유효성 검사를 할 것이고
    //그럼 이제 데이터를 어떻게 할 것인가를 먼저 결정해야함
    //말했다시피
    //클라의 raw buffer를 가지고 있다가
    //메시지 클래스에 전달하고
    //메시지 클래스는 서버에 전달하는 형태로
    //int sender //client fd
    //std::string Command
    //std::string params
    //이렇게 처리하면 될 듯

    //그래서 서버에서 명령어 처리를 할 거잖음
    //뭐 내부 구조가 어떻게 돼있는지는 잘 모르겠지만
    //어쨌든 서버에서 뭐 run이나 exec하는 함수가 있을거고
    //거기에 message클래스를 전달하면 되지
    //만약에 유효성 검사에서 이상한 경우는 null을 보내든 exception 던지든 하고
    //암튼 이제 앞에가 어떻게 되든간에 command params crlf
    //가 정상적으로 들어왔을 때 서버에 저걸 전달하면 되는거고
    //recv를 어차피 server.cpp에서 하는거면
    //그냥 예외처리로 try catch 하고
    //예외 발생은 무시하고
    //try 안에다가 내용 처리하면 되겠네ㅇㅇ
    //그럼 메시지 클래스에선 진짜 제대로 파싱만 하고 정상적인 결과면 server가 지금 처리할 메시지만 가져가도 되는거니까
    //그럼 그냥 메시지 클래스로 가져갈 필요가 없네..?

    //이게 구조가 지금
    //클라이언트를 소유하는 서버가 recv를 하잖음
    //데이터가 어차피 다 안에 있으니까
    //함수로만 빼도 괜찮을듯
    //음..사실 그렇게 안해도 될것 같은게
    //그냥 서버가 command랑 param이라는 string 변수 두 개만 가지고 있어도 됨

    //ㅇㅇ
    //그래서 클래스로 나눌 필요 없이 그냥 함수에서
    //this.command = 파싱 완료된 메시지
    //this.params = 파싱 완료된 메시지
    //하고

    //exec에서
    //this.command.clear()
    //this.params.clear()
    //하면 되니까

    //멀티플렉싱 I/O 자체는
    //kqeue, select, poll같은 애들이
    //현재 이 fd 버퍼를 사용할 수 있다~ 이걸 비동기/블로킹 방식으로 감지하는 애고
    //우리는 그렇게 받은걸 토대로 recv / send 하는 거였음

    //암튼 너가 걱정하는게 먼 말인지 이해했음
    //그러면 클라이언트가 해당 메시지를 소유하게 하는게 가장 나을라나?
    //사실 그게 맞긴 함ㅋㅋ
    //어쨌든 구조 결정하면 이게 합리적인가 아닌가만 따져도 되는거잖음
    //ㄴㄴ 그건 절대 아님
    //의존성 최대한 제거하는게 맞아
    //메시지를 담당하는 애면
    //메시지만 처리하고 리턴하든 예외던지든 그것만 하는게 맞음
    //긍까 메시지를 중립으로 놓을거면(서버가 소유하는게 아니라 도구 같은 개념이라면)
    //fd를 가져가야하고
    //서버가 데이터를 소유하게 하면
    //fd를 가져갈 필요가 없지
    //이미 알고있으니까
    //ㅇㅇ 그래서 이걸 결정하는건 너 몫이고
    //어쨌든 메시지 관리하는 애를 따로 나누는게 맞다- 이거지
    //ㅇㅇ

    //비어있는 메세지일 경우는?
    parseMessage(msg);
}

Message::~Message()
{}

void Message::parseMessage(std::string msg)
{
    std::stringstream ss(msg);

    //원하는 개수가 아닐 경우 처리 필요
    //일단 변수에 담아주기
    std::string command, param
    ss >> command;
    msg->command = command;

    while (ss >> param) {
        if ((param.size() == 2) && (param[0] == '\r') && (param[1] '\n'))
            break;
        msg->params.push_back(param);
    }
    // this->crlf = crlf;
    //crlf는 어케 처리하지
}

MessageInfo &Message::getMessageInfo()
{
    return (msg);
}
