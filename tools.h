#ifndef TOOLS_H
#define TOOLS_H

#include <stable.h>

struct Result{
    bool isMine;
    std::vector<std::pair<int,int>> path;
};
class Tools
{
public:
    static void GenerateMap(int width,int length,int mines);
    static void PrintMap(const Matrix& matrix);
    static
};

#endif // TOOLS_H
