//
// Created by naren on 2022/3/19.
//

#ifndef SPEEKER_LAMBDAFUNCTION_H
#define SPEEKER_LAMBDAFUNCTION_H
// 4 闭包 lambda+function
struct Value {
    // implements
    Value() = default;
};
struct Info {
    // implements
    Info() = default;
};
namespace method4 {

}
using Getter = function<Info (vector<Info> &)>;
Getter ValueGetter(int i)  {return [i](vector<Info> &) {/* implements */};}
Getter IndexGetter(Value i)  {return [i](vector<Info> &) {/* implements */};}
Getter InfoGetter(Info& i)  {return [i](vector<Info> &) {/* implements */};}

Speaker CreateSpeaker(vector<Info>& infos, Getter& getter);


{
    CreateSpeaker({/* implements*/ }, ValueGetter(3));
    CreateSpeaker({/* implements*/ }, IndexGetter(Value()));
    CreateSpeaker({/* implements*/ }, InfoGetter(Info()));
}


Speaker CreateSpeaker(vector<Info> & infos, int i);
//其他重载，只处理新增方式，或者也兼容index
//可以用方案1-5，或者混合方案1 提供重载
//但更多是用模板转方案4
template<typename  Getter>  // 一般不用GetterInfo概念
Speaker CreateSpeaker(vector<Info>& infos, Getter & i) {

}
}
CreateSpeaker({/* implements*/ }, method4::ValueGetter(3));
CreateSpeaker({/* implements*/ }, method4::IndexGetter(Value()));
CreateSpeaker({/* implements*/ }, method4::InfoGetter(Info()));


#endif //SPEEKER_LAMBDAFUNCTION_H
