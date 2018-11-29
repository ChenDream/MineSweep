#ifndef MINEALGORITHM_H
#define MINEALGORITHM_H

//struct Result{
//    bool isMine = false;
//    std::vector<std::pair<int,int>> path;
//};
class MineAlgorithm
{

public:
    static void GenerateMap(int width,int length,int mines);
    static void PrintMap(const Matrix& matrix);
    static bool Click(int x,int y);
};

#endif // MINEALGORITHM_H
