#include "service.h"
#include <iostream>
using namespace std;

int main() 
{
    Redis redis;
    Service s1, s2;
    redis.connect();
    s1.subscribe(1);
    s2.subscribe(2);
    int cid;
    string msg;
    while(1) {
        int cid;
        cout << "请输入要发布的通道号: "; 
        cin >> cid;
        if(cid == -1) break;
        cout << "请输入消息: " ;
        cin >> msg;
        redis.publish(cid, msg);
    }
    s1.unsubscribe(1);
    s2.unsubscribe(2);
    return 0;
}