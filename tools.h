#ifndef TOOLS_H
#define TOOLS_H

#include <stable.h>
typedef std::vector<std::vector<int>> Matrix;
class Tools
{
public:
    Tools();
    static Matrix GenerateMap(int width,int length,int mines);
    static void PrintMap(const Matrix& matrix);
};

#endif // TOOLS_H
