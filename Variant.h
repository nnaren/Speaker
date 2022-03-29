//
// Created by naren on 2022/3/19.
//

#ifndef SPEEKER_VARIANT_H
#define SPEEKER_VARIANT_H
// 5 variant
using GetterInfo  = variant<int, Value, Info>;
Speaker CreateSpeaker(vector<Info>& infos, GetterInfo& I);
CreateSpeaker({/* impliments*/ } ,3)
#endif //SPEEKER_VARIANT_H
