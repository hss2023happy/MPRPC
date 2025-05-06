#pragma once
#include "mprpcconfig.h"
#include"mprpcchannel.h"
#include "mprpccontroller.h"


//mprpc框架的初始化类
class MprpcApplication
{
public:
    static MprpcConfig m_config;
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstance();
    static MprpcConfig& GetConfig();
 private:

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&)=delete;
    MprpcApplication(MprpcApplication&&)=delete;
};