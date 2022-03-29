//
// Created by naren on 2022/3/17.
//

#ifndef SPEEKER_SPEAKER_H
#define SPEEKER_SPEAKER_H
#include <vector>
using namespace std;
class Speaker {};
class Info {};
class Value {};


template<class T>
Speaker CreateSpeaker(vector<Info>& infos, T t);

// 1重载 导致组合爆炸
Speaker CreateSpeaker(vector<Info>& infos, int index);
Speaker CreateSpeaker(vector<Info>& infos, Value value);
Speaker CreateSpeaker(vector<Info>& infos, Info & info);

template<typename GetterInfo>
Speaker CreateSpeaker(vector<Info>& infos, GetterInfo & i) {
    CreateSpeakerImpl(i);  // 1 转方案1
    Getter getter = CreateGetter(i);  //2 zhuan转方案2， 一般不转方案3 、4
    if constexpr (is_same_t<GetterInfo, int>) {  // 相当于方案5
        /* */ // 一般不实现apply形式
    }
}

Speaker CreateSpeaker(vector<Info> & infos, int i);
//其他重载，只处理新增方式，或者也兼容index
//可以用方案1-5，或者混合方案1 提供重载
//但更多是用模板转方案4
template<typename  Getter>
Speaker CreateSpeaker(vector<Info>& infos, Getter & i) {

}

#endif //SPEEKER_SPEAKER_H
