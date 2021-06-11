#ifndef ENCRYPTOR
#define ENCRYPTOR

#include <iostream>
#include <fstream>
#include <vector>
#include <random>


struct cube{
    char first;
    char second;
    char third;
    char fourth;
    char fifth;
    char sixth;
    char seventh;
    char eighth;

    cube& operator=(const cube& oth); 
};

struct rotate{
    int Left = 0;
    int Right = 0;
    int Up = 0;
    int Down = 0;

    rotate& operator=(const rotate& oth);
};


class Encryptor{
    private:
        static int s_range;
        std::string m_text;
        std::vector<cube> m_bigcube;
        std::vector<rotate> m_rotations;
        int m_cube_count = 0;
        cube m_word;
        rotate r;
    private:
        void insert_for_cube(std::string,int s);
        void insert_rotates(int l,int r,int u,int d);
        void rotate_left(cube& cube,int l);
        void rotate_right(cube& cube,int r);
        void rotate_up(cube& cube,int u);
        void rotate_down(cube& cube,int d);
    public:
        Encryptor() = delete;
        Encryptor(std::string message);
        ~Encryptor();
    public:
        void insert_bigcube();
        void rotate_cube();
        void cube_print();
};

#endif //ENCRYPTOR