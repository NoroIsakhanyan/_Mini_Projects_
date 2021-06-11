#include <iostream>
#include <cstdlib>
#include <string>
#include <random>
#include <time.h>       

std::string upper_gen(){
    int run;
    std::string str = "";
    run = rand() % 5 + 2;
    for(int i = 0;i < run;++i){
    int num = 0;
    num = rand() % (int)'Z' + (int)'A';
    char ch = num;
    str += ch;
 }
    return str;
}

std::string lower_gen(){
    int run;
    std::string str = "";
    run = rand() % 5 + 2;
    for(int i = 0;i < run;++i){
    int num = 0;
    num = rand() % (int)'z' + (int)'a';
    char ch = num;
    str += ch;
 }
 return str;
}

std::string symbol_gen(){
    int run;
    std::string str = "";
    run = rand() %  2;
    for(int i = 0;i < run;++i){
    int num = 0;
    num = rand() % (int)'/' + (int)'!';
    if(num == 40 || num == 42){
        num = 41;
    }
    char ch = num;
    str += ch;
 }
 return str;
}
std::string symbol_gen1(){
    int run;
    std::string str = "";
    run = rand() % 2;
    for(int i = 0;i < run;++i){
    int num = 0;
    num = rand() % (int)'`' + (int)'[';
    char ch = num;
    str += ch;
 }
 return str;
}

std::string num_gen(){
    int run;
    std::string str = "";
    run = rand() % 5 + 2;
    for(int i = 0;i < run;++i){
    int num = 0;
    num = rand() % (int)'9' + (int)'0';
    char ch = num;
    str += ch;
 }
 return str;
}

void shufle(std::string& str){
    int n = str.length();
    int loop = 0;
    for(int i = 0;i < n;++i){
        loop = rand() % n;
        std::swap(str[loop],str[i]);
    }
}

bool test(std::string& str){
    if(str.length() < 8 || str.length() > 24 ){
        return false;
    }
    int upper = 0;
    int lower = 0;
    int symbol = 0;

    for(auto& a : str){
        if(a >= 'A' && a <= 'Z'){
            upper++;
        }else if(a >= 'a' && a <= 'z'){
            lower++;
        }else if((a >= '!' && a <= '/') || (a >= '[' && a <= '`')){
            symbol++;
        }
    }


    if(upper <=2 || lower <=2 || symbol == 0 ){
        return false;
    }
    return true;
}




int main(){
    srand(time(NULL));
    std::string password;
    password += upper_gen();
    password += lower_gen();
    password += symbol_gen();
    password += symbol_gen1();
    password += num_gen();
    std::cout << password << '\n';
    std::cout << test(password);

}