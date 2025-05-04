#include<iostream>
#include "mprpcapplication.h"
#include"user.pb.h"
#include"mprpcchannel.h"

int main(int argc,char **argv)
{
    //整个程序启动后，想使用mprpc框架来享受rpc服务，一定先调用初始化函数
    MprpcApplication::Init(argc,argv);

    //演示调用远程发布的rpc方法Login
    fixbug::UserServiceRpc_Stub stub(new MprpcChannel());
    //rpc方法的请求
    fixbug ::LoginRequest request;
    request.set_name("chen yq");
    request.set_pwd("312");
    //rpc方法的响应
    fixbug::LoginResponse response;
    stub.Login(nullptr,&request,&response,nullptr);

    //一次rpc调用完成，读调用的结果
    if(0==response.result().errcode())
    {
        std::cout<<"rpc login response success:"<<response.success()<<std::endl;
    }
    else
    {
        std::cout<<"rpc login response error:"<<response.result().errmsg()<<std::endl;
    }

    //演示调用远程发布的rpc方法Register
    fixbug::RegisterRequest req;
    req.set_id(312);
    req.set_name("chen yq");
    req.set_pwd("312");
    fixbug::RegisterResponse rsp;

    //以同步的方式发起rpc调用请求，等待返回结果
    stub.Register(nullptr,&req,&rsp,nullptr);

    //一次rpc调用完成，读调用的结果
    if(0==rsp.result().errcode())
    {
        std::cout<<"rpc Register response success:"<<rsp.success()<<std::endl;
    }
    else
    {
        std::cout<<"rpc Register response error:"<<rsp.result().errmsg()<<std::endl;
    }

    return 0;

}