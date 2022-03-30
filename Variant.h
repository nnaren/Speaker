//
// Created by naren on 2022/3/19.
//

#ifndef SPEEKER_VARIANT_H
#define SPEEKER_VARIANT_H
// 5 variant
using namespace std;
struct Value {
    // implements
    Value() = default;
};
struct Info {
    // implements
    Info() = default;
};
using GetterInfo  = variant<int, Value, Info>;
Speaker CreateSpeaker(vector<Info>& infos, GetterInfo& I);
CreateSpeaker({/* impliments*/ } , 3);
CreateSpeaker({/* impliments*/ } , Value());
CreateSpeaker({/* impliments*/ } , Info());

// 混合
template<typename GetterInfo>
Speaker CreateSpeaker(vector<Info>& infos, GetterInfo & i) {
    if constexpr (std::is_same<GetterInfo, int>) {  // 相当于方案5  is_same_t
        /* */ // 一般不实现apply形式
    }
}
#endif //SPEEKER_VARIANT_H
