#include "logger.h"
#include<time.h>
#include<iostream>
// 获取日志的单例
Logger &Logger::GetInstance()
{
    static Logger logger;
    return logger;
}
Logger::Logger()
{ // 启动专门的写日志线程
    std::thread writeLogTask([&]() {
                            
            for(;;)
            {
                time_t now=time(nullptr);
                tm *nowtm=localtime(&now);

                char file_name[128];
                sprintf(file_name,"%d-%d-%d-log.txt",nowtm->tm_year+1900,nowtm->tm_mon+1,nowtm->tm_mday);

                FILE *pf=fopen(file_name,"a+");
                if(pf==nullptr)
                {
                    std::cout<<"logger file :"<<file_name<<"open error!"<<std::endl;
                    exit(EXIT_FAILURE);
                }

                std::string msg=m_lockQue.Pop();

                char time_buf[128]={0};
                sprintf(time_buf,"%d:%d:%d=>",nowtm->tm_hour,nowtm->tm_min,nowtm->tm_sec);
                msg.insert(0,time_buf);

                fputs(msg.c_str(),pf);
                fclose(pf);

            } 
        
        });
    // 设置分离线程，守护线程
    writeLogTask.detach();
}

// 设置日志级别
void Logger::SetLogLevel(LogLevel level)
{
    m_loglevel = level;
}

// 写日志,把日志信息写入lockqueue缓冲区当中
void Logger::Log(std::string msg)
{
    m_lockQue.Push(msg);
}
