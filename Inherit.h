//
// Created by naren on 2022/3/19.
//

#ifndef SPEEKER_INHERIT_H
#define SPEEKER_INHERIT_H
// 2继承
struct Getter{
    virtual Info Get(vector<Info> &) = 0;
};  // 注意析构、clone方法
struct IndexGetter : public  Getter {
    // impliments
};
struct ValueGetter : public  Getter {
    // impliments
};
struct InfoGetter : public  Getter {
    // impliments
};
Speaker CreateSpeaker(vector<Info>& infos, Getter* getter);
GetterSpeaker({/* impliments*/ }, 3);   // 注意delete getter
//改进1：
Base * CreateGetter(int);
Base * CreateGetter(Value);
Base * CreateGetter(Info &);
GetterSpeaker({/* impliments*/ }, 3);   // 注意delete getter
//改进2：
smart_ptr<Getter> CreateGetter(int);
smart_ptr<Getter> CreateGetter(Value);
smart_ptr<Getter> CreateGetter(Info &);
#endif //SPEEKER_INHERIT_H
