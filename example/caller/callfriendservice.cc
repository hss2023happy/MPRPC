#include "mprpcapplication.h"
#include "friend.pb.h"

int main(int argc, char **argv)
{
    // 整个程序启动后，想使用mprpc框架来享受rpc服务，一定先调用初始化函数
    MprpcApplication::Init(argc, argv);

    // 演示调用远程发布的rpc方法Login
    fixbug::FriendServiceRpc_Stub stub(new MprpcChannel());
    // rpc方法的请求
    fixbug ::GetFriendsListRequest request;
    request.set_userid(1000);
    // rpc方法的响应
    fixbug::GetFriendsListResponse response;

    MprpcController controller;
    stub.GetFriendsList(&controller, &request, &response, nullptr);

    // 一次rpc调用完成，读调用的结果
    if (controller.Failed())
    {
        std::cout << controller.ErrorText() << std::endl;
    }
    else
    {
        if (0 == response.result().errcode())
        {
            std::cout << "rpc GetFriendsList response success:" << std::endl;
            int size = response.friends_size();
            for (int i = 0; i < size; ++i)
            {
                std::cout << "index:" << (i + 1) << "name: " << response.friends(i) << std::endl;
            }
        }
        else
        {
            std::cout << "rpc GetFriendsList response error:" << response.result().errmsg() << std::endl;
        }
    }

    return 0;
}