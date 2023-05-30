#include <iostream>
#include "MyTask.h"

int main() {
//    Queue<int> a;
//    int b = 5;
//    a.push(b);
//    a.push(2);
//    a.push(4);
//    Queue<int> a2;
//    a2.push(1);
//    a2.push(3);
//    a.swap(a2);
//    std::cout<<"size a2: "<<a2.size()<<'\n';
//    std::cout<<"front a2: "<<a2.front()<<'\n';
//    std::cout<<"back a2: "<<a2.back()<<'\n';
//    a2.clear();
//    std::cout<<"size a2 after clear: "<<a2.size()<<'\n';
    MyTask c;
    std::cout<<c.getA().size()<<'\n';
    std::cout<<c.FindAndInsert().size()<<'\n';
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
