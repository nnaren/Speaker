//
// Created by naren on 2022/3/17.
//

#ifndef SPEEKER_EREASURE_H
#define SPEEKER_EREASURE_H

struct Value {
    // implements
};
struct Info {
    // implements
};
// 3 类型擦除
namespace method3 {

class GetterImpl {
    virtual ~GetterImpl() {}
    virtual Info Get(vector<Info> &) = 0;
};

struct ValueGetter : public GetterImpl{
    ValueGetter(int t) {}
    virtual Info Get(vector<Info> &) {

    }
};
struct IndexGetter : public GetterImpl{
    IndexGetter(Value t) {}
    virtual Info Get(vector<Info> &) {

    }
};
struct InfoGetter  : public GetterImpl{
    InfoGetter(Info t) {}
    virtual Info Get(vector<Info> &) {

    }
};


class Getter {
public:
    // 还要处理拷贝构造、移动构造和
    Getter(int i) : impl(new IndexGetter(t)) {}
    Getter(Value i) : impl(new ValueGetter(t)) {}
    Getter(Info& i) : impl(new InfoGetter(t)) {}
    // 析构
    ~Getter() {
        if(impl != nullptr) {
            delete impl;
            impl = nullptr;
        }
    }
    // 拷贝构造
    Getter(const Getter& obj) {
        //怎么运行时动态创建类型 RTTI  ??
    }
    // 移动构造
    Getter(Getter&& obj) {
        impl = obj.impl;
        obj.impl = nullptr;
    }
    Info Get(vector<Info>& infos) { return impl->Get(infos); }

private:
    GetterImpl * impl;
};
Speaker CreateSpeaker(vector<Info>& infos, Getter& I) {
    I.Get();
}
CreateSpeaker({/* implements*/ }, Getter(3));
CreateSpeaker({/* implements*/ }, Getter(Value()));
CreateSpeaker({/* implements*/ }, Getter(Info()));
}

#endif //SPEEKER_EREASURE_H
