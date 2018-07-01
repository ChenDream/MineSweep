#include "tools.h"
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
Tools::Tools()
{

}
/**
 * @brief Tools::GenerateMap
 * generate a 2d int vector to store mines.
 * 0 resprest no mines, -1 represent mines.
 * 1 - 8 resprest number of mines around.
 *
 * @param width
 * @param length
 * @param mines
 * @return
 */
Matrix Tools::GenerateMap(int width, int length, int mines){
    int total = width*length;
    std::vector<int> lst;
    for(int i=0;i<total;i++){
        lst.push_back(i);
    }
    //shuffle list
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(lst.begin(),lst.end(),std::default_random_engine(seed));

    Matrix x(length,std::vector<int>(width,0));

    if(mines>total) mines = total;
    for(int i=0;i<mines;i++){
        int num = lst.at(i);
        int l = num/width;
        int w = num%width;
        x[l][w] = -1;

        //top
        if((l-1)>=0){
            //top middle
            if(x[l-1][w]!=-1) x[l-1][w]++;
            //top left
            if((w-1)>=0){
                if(x[l-1][w-1]!=-1) x[l-1][w-1]++;
            }
            //top right
            if((w+1)<width){
                if(x[l-1][w+1]!=-1) x[l-1][w+1]++;
            }
        }
        //center left
        if((w-1)>=0){
            if(x[l][w-1]!=-1) x[l][w-1]++;
        }
        //center right
        if((w+1)<width){
            if(x[l][w+1]!=-1) x[l][w+1]++;
        }
        //bottom
        if((l+1)<length){
            //bottom middle
            if(x[l+1][w]!=-1) x[l+1][w]++;
            //bottom left
            if((w-1)>=0){
                if(x[l+1][w-1]!=-1) x[l+1][w-1]++;
            }
            //bottom right
            if((w+1)<width){
                if(x[l+1][w+1]!=-1) x[l+1][w+1]++;
            }
        }
    }

    PrintMap(x);
    return x;
}
void Tools::PrintMap(const Matrix &matrix){
    if(matrix.empty()) return;
    auto length = matrix.size();
    auto width = matrix[0].size();
    for(int i=0;i<length;i++){
        std::string str;
        for(int j=0;j<width;j++){
            int num = matrix[i][j];
            if(num!=-1)str = str.append(" ");
            str = str.append(std::to_string(num)).append(" ");
        }
        std::cout<<str<<std::endl;
    }
}
