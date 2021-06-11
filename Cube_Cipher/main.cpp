#include "encryptor.cpp"

int main(){
    std::string text = "hello world";

    Encryptor ob(text);
    ob.insert_bigcube();
    ob.rotate_cube();
    ob.rotate_cube();
}