#include"test.pb.h"
#include<iostream>
using namespace fixbug;
int main()
{
    GetFriendListResponse rsp;
    ResultCode *rc=rsp.mutable_result();
    rc->set_errcode(0);

    User *user1=rsp.add_friend_list();
    user1->set_name("chen yq");
    user1->set_age(45);
    user1->set_sex(User::MAN);

    User *user2=rsp.add_friend_list();
    user2->set_name("chen yq");
    user2->set_age(45);
    user2->set_sex(User::MAN);

    std::cout<<rsp.friend_list_size()<<std::endl;
}


int main1()
 {
    LoginRequest req;
    req.set_name("chen yq");
    req.set_pwd("302");

    std::string send_str;//对象序列化
    if(req.SerializeToString(&send_str))
 {
    std::cout<<send_str<<std::endl;

 }
    LoginRequest reqB;//对象反序列化
    if(reqB.ParseFromString(send_str))
 {

    std::cout<<reqB.name()<<std::endl;
    std::cout<<reqB.pwd()<<std::endl;

 }

return 0;

}