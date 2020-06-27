#include "redis.h"
#include <thread>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
using namespace std::placeholders;

class Service 
{
public:
    Service() {
        if(_redis.connect()) {
            _redis.init_notify_handler(bind(&Service::handleRedisSubscribeMessage, this, _1, _2));
        }
    }
    void subscribe(int cid) 
    {
        _redis.subscribe(cid);
    }

    void unsubscribe(int cid) 
    {
        _redis.unsubscribe(cid);
    }
    void handleRedisSubscribeMessage(int cid, string msg) {
        cout << "通道" << cid << "收到一条新信息：" << msg << endl;
    } 

private:
    Redis _redis;
};