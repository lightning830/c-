#include<iostream>
using namespace std;

namespace Kitten{
    class Kitty{};
    void aKitty();
    char str[] = "Kitty on your lap\n";
    void sakura(){
        cout<<"Crad Captor SAKURA\n";
    }
}

int main(){
    Kitten::Kitty obj;
    cout<<Kitten::str;
    Kitten::sakura();
    Kitten::aKitty();
    return 0;
}

namespace Kitten{
    void aKitty(){
        cout<<str;
    }
}