#include <iostream>
#include <vector>

#define ADD "add"
#define DEL "del"
#define LS  "ls"
#define EXIT "ex"


struct info
{
    int id = 0;
    std::string name;
    std::string surname;
    std::string phone;
    std::string address;
};

void insert_for_book(std::vector<info>& vec){
    info a;
    std::cout << "ID :";
    std::cin >> a.id;
    std::cout << std::endl;
    std::cout << "name :";
    std::cin >> a.name;
    std::cout << std::endl;
    std::cout << "surname :";
    std::cin >> a.surname;
    std::cout << std::endl;
    std::cout << "phone :";
    std::cin >> a.phone;
    std::cout << std::endl;
    std::cout << "address :";
    std::cin >> a.address;
    std::cout << std::endl;
    vec.push_back(a);
}

void print_info(info& inf){
    std::cout << inf.id << '\n';
    std::cout << inf.name <<'\n';
    std::cout << inf.surname <<'\n';
    std::cout << inf.phone <<'\n';
    std::cout << inf.address <<'\n';
}

void delete_info_by_id(std::vector<info>& vec,int key){
    
    int count = 0;
    for(auto it : vec){
        if(it.id == key){
                vec.erase(std::next(vec.begin() + count ));
                break;
        }
        count++;       
    }

}

void print_book(std::vector<info>& vec){
    std::cout << std::endl;
    for(auto a : vec){
        print_info(a);
        std::cout << std::endl;
    }
}

void start(std::vector<info>& book){
    bool exit = false;

    std::string command;
    std::cout << "Choose comand" << '\n';
    std::cout << "add-For add info" << '\n';
    std::cout << "del-For add delet info by id" << '\n';
    std::cout << "ls-For add print" << '\n';
    std::cout << "ex-For add exit" << '\n';
    std::cin >> command;


    do{
        if(command == ADD){
            system("cls");
            insert_for_book(book);
            start(book);
        }else if(command == DEL){
            system("cls");
            int key;
            std::cout << "Eneter ID" << '\n';
            std::cin >> key;
            delete_info_by_id(book,key);
            start(book);
        }else if(command == LS){
            system("cls");
            print_book(book);
            start(book);
        }else if(command == EXIT){
            exit = true;
        }else{
            std::cout << std::endl <<  "Invalid command,please check commands" << std::endl;
            start(book);
        }
    }while (!exit);
    
}

int main(){
    std::vector<info> book;

    start(book);

}
