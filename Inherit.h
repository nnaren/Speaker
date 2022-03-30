//
// Created by naren on 2022/3/19.
//

#ifndef SPEEKER_INHERIT_H
#define SPEEKER_INHERIT_H
#include <vector>
using namespace std;
// 2继承
namespace method2 {
struct Value {
    // implements
};
struct Info {
    // implements
};


// 基本类型
struct Getter{
    virtual Info Get(vector<Info> &) = 0;
    ~Getter() {}
};  // 注意析构、clone方法

// 类型
struct IndexGetter : public  Getter {
    // implements
    IndexGetter(int _index) {}
};
// 类型
struct ValueGetter : public  Getter {
    // implements
    ValueGetter(Value _value) {}
};
// 类型
struct InfoGetter : public  Getter {
    // implements
    InfoGetter(Info& _info) {}
};
Speaker CreateSpeaker(vector<Info>& infos, Getter* getter);
CreateSpeaker({/* implements*/ },  new IndexGetter(3));
CreateSpeaker({/* implements*/ },  new ValueGetter(Value()));   // 注意delete getter
CreateSpeaker({/* implements*/ },  new InfoGetter(Info()));


//改进1：
Speaker CreateSpeaker(vector<Info>& infos, Getter* getter);

Getter * CreateGetter(int _index) {
    return new IndexGetter(_index);
}

Getter * CreateGetter(Value _value) {
    return new ValueGetter(_value);
}
Getter * CreateGetter(Info & _info){
    return new InfoGetter(_info);
}
CreateSpeaker({/* implements  */ }, CreateGetter(3));        // 注意delete getter
CreateSpeaker({/* implements  */ }, CreateGetter(Value()));  // 注意delete getter
CreateSpeaker({/* implements  */ }, CreateGetter(Info()));   // 注意delete getter

//改进2：
smart_ptr<Getter> CreateGetter(int _index) {
    return make_shared<Getter>(IndexGetter(_index));
}
smart_ptr<Getter> CreateGetter(Value _value) {
    return make_shared<Getter>(ValueGetter(_value));
}
smart_ptr<Getter> CreateGetter(Info & _info) {
    return make_shared<Getter>(InfoGetter(_info));
}
CreateSpeaker({/* implements*/ }, CreateGetter(3));
CreateSpeaker({/* implements*/ }, CreateGetter(Value()));
CreateSpeaker({/* implements*/ }, CreateGetter(Info()));


// 改进3：模板 + 继承
template<typename GetterInfo>
Speaker CreateSpeaker(vector<Info>& infos, GetterInfo & i) {
    Getter* getter = CreateGetter(i);  //2 转方案2， 一般不转方案3 、4
}
CreateSpeaker({/* implements*/ }, CreateGetter(3));
CreateSpeaker({/* implements*/ }, CreateGetter(Value()));
CreateSpeaker({/* implements*/ }, CreateGetter(Info()));

}
#endif //SPEEKER_INHERIT_H
