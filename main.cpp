#include <iostream>
#include "Speaker.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    auto speaker = CreateSpeaker();
    speaker(56);
    return 0;



}
