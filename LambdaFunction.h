//
// Created by naren on 2022/3/19.
//

#ifndef SPEEKER_LAMBDAFUNCTION_H
#define SPEEKER_LAMBDAFUNCTION_H
// 4 闭包 lambda+function
using Getter = function<Info (vector<Info> &)>;
Getter ValueGetter(int i)  {return [i](vector<Info> &) {/* implements */};}
Getter IndexGetter(Value i)  {return [i](vector<Info> &) {/* implements */};}
Getter InfoGetter(Info& i)  {return [i](vector<Info> &) {/* implements */};}

Speaker CreateSpeaker(vector<Info>& infos, Getter& getter);
CreateSpeaker({/* impliments*/ }, ValueGetter(3));
#endif //SPEEKER_LAMBDAFUNCTION_H
