#pragma once
#include "mprpcconfig.h"
//mprpc框架的初始化类
class MprpcApplication
{
public:
    static MprpcConfig m_config;
    static void Init(int argc, char **argv);
    static MprpcApplication& GetInstancec();
 private:

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&)=delete;
    MprpcApplication(MprpcApplication&&)=delete;
};