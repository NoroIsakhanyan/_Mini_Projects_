#ifndef COMP_H
#define COMP_h

#include <string>
#include <fstream>
#include <string>

class Compress {
public:
    Compress() = default;
    Compress(const std::string&);
    ~Compress();

    void decompress(const std::string&);
    void compress(const std::string&);
private:
    std::string m_inputString;
    std::fstream m_file;
};

#endif //COMP_h
