#include "encryptor.h"


cube& cube::operator=(const cube& oth){
    if(this == &oth){
        return *this;
    }
  this->first   = oth.first;
  this->second  = oth.second;
  this->third   = oth.third;
  this->fourth  = oth.fourth;
  this->fifth   = oth.fifth;
  this->sixth   = oth.sixth;
  this->seventh = oth.seventh;
  this->eighth  = oth.eighth;

  return *this;
}

rotate& rotate::operator=(const rotate& oth){
    if(this == &oth){
        return *this;
    }
    this->Left  = oth.Left;
    this->Right = oth.Right;
    this->Up    = oth.Up;
    this->Down  = oth.Down;

    return *this;
}

Encryptor::Encryptor(std::string message){
    this->m_text = message;
}


void Encryptor::insert_for_cube(std::string str,int s){
    this->m_word.first   = str[s];
    s_range++;
    this->m_word.second  = str[s+1];
    s_range++;
    this->m_word.third   = str[s+2];
    s_range++;
    this->m_word.fourth  = str[s+3];
    s_range++;
    this->m_word.fifth   = str[s+4];
    s_range++;
    this->m_word.sixth   = str[s+5];
    s_range++;
    this->m_word.seventh = str[s+6];
    s_range++;
    this->m_word.eighth  = str[s+7];

    m_bigcube.push_back(m_word);
}


void Encryptor::insert_rotates(int l,int r,int u,int d){
    this->r.Left  = l;
    this->r.Right = r;
    this->r.Up    = u;
    this->r.Down  = d;

    m_rotations.push_back(this->r);
}

void Encryptor::insert_bigcube(){
    this->m_cube_count = this->m_text.length()/8 + 1;
    int slow = 0;
    for(int i = 0;i < this->m_cube_count;++i){
        insert_for_cube(m_text,slow);
        slow += 8;
    }
}

void Encryptor::rotate_left(cube& cube,int l){
    std::vector<int> vec = {cube.first,cube.second,cube.third,cube.fourth,cube.fifth,cube.sixth,cube.seventh,cube.eighth};
    int tmp = 0;
    for(int i = 0;i < l;++i){
        tmp = vec[0];
        for(int j = 0;j < vec.size() - 1;++j){
            vec[j] = vec[j+1];
        }

        vec[vec.size()-1] = tmp;
    }
    cube.first   = vec[0];
    cube.second  = vec[1];
    cube.third   = vec[2];
    cube.fourth  = vec[3];
    cube.fifth   = vec[4];
    cube.sixth   = vec[5];
    cube.seventh = vec[6];
    cube.eighth  = vec[7];
}

void Encryptor::rotate_right(cube& cube,int r){
    std::vector<int> vec = {cube.first,cube.second,cube.third,cube.fourth,cube.fifth,cube.sixth,cube.seventh,cube.eighth};
    int tmp = 0;
    int n = vec.size();
    for(int i = 0;i < r;++i){
        tmp = vec[n-1];
        for(int j = 0;j < n;++j){
            vec[j] = vec[j-1];
        }

        vec[0] = tmp;
    }
    cube.first   = vec[0];
    cube.second  = vec[1];
    cube.third   = vec[2];
    cube.fourth  = vec[3];
    cube.fifth   = vec[4];
    cube.sixth   = vec[5];
    cube.seventh = vec[6];
    cube.eighth  = vec[7];
}

void Encryptor::rotate_up(cube& cube,int u){
    std::vector<int> vec = {cube.first,cube.second,cube.third,cube.fourth,cube.fifth,cube.sixth,cube.seventh,cube.eighth};
    int tmp = 0;
    int n = vec.size();
    for(int i = 0;i < u;++i){
        tmp = vec[0];
        for(int j = 0;j < n/2;++j){
            vec[j] = vec[j+4];
        }

        vec[n-1] = tmp;
    }
    cube.first   = vec[0];
    cube.second  = vec[1];
    cube.third   = vec[2];
    cube.fourth  = vec[3];
    cube.fifth   = vec[4];
    cube.sixth   = vec[5];
    cube.seventh = vec[6];
    cube.eighth  = vec[7];
}

void Encryptor::rotate_down(cube& cube,int d){
 std::vector<int> vec = {cube.first,cube.second,cube.third,cube.fourth,cube.fifth,cube.sixth,cube.seventh,cube.eighth};
    int tmp = 0;
    int n = vec.size();
    for(int i = 0;i < d;++i){
        tmp = vec[n-1];
        for(int j = 4;j < n;++j){
            vec[j] = vec[j-4];
        }

        vec[0] = tmp;
    }
    cube.first   = vec[0];
    cube.second  = vec[1];
    cube.third   = vec[2];
    cube.fourth  = vec[3];
    cube.fifth   = vec[4];
    cube.sixth   = vec[5];
    cube.seventh = vec[6];
    cube.eighth  = vec[7];
}



void Encryptor::rotate_cube(){
    int l = 0;
    int r = 0;
    int u = 0;
    int d = 0;
    rotate tmp;
    for(int i = 0;i < this->m_bigcube.size();++i){
        l = rand() % 3;
        r = rand() % 3;
        u = rand() % 3;
        d = rand() % 3;

        rotate_left(this->m_bigcube[i],l);
        rotate_right(this->m_bigcube[i],r);
        rotate_up(this->m_bigcube[i],u);
        rotate_down(this->m_bigcube[i],d);

        tmp = insert_rotates(l,r,u,d);
        this->m_rotations.push_back(tmp);
    }
}

void Encryptor::cube_print(){
    for(int i = 0;i < m_bigcube.size();++i){
        std::cout << m_bigcube[i].first << m_bigcube[i].second << m_bigcube[i].third << m_bigcube[i].fourth << m_bigcube[i].fifth << m_bigcube[i].sixth << m_bigcube[i].seventh << m_bigcube[i].eighth;
    }
    std::cout << std::endl;
}

Encryptor::~Encryptor(){
    std::cout << "Encrypted" << std::endl;
}