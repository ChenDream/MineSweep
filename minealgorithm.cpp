#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include "global.h"
#include "minealgorithm.h"

/**
 * @brief MineAlgorithm::GenerateMap
 * generate a 2d int vector to store mines.
 * 0 resprest no mines, -1 represent mines.
 * 1 - 8 resprest number of mines around.
 *
 * @param width
 * @param length
 * @param mines
 * @return
 */
void MineAlgorithm::GenerateMap(int width, int length, int mines){
    int total = width*length;
    std::vector<int> lst;
    for(int i=0;i<total;i++){
        lst.push_back(i);
    }
    //shuffle list, list contain every index of matrix, shuffle list will
    // let index sort in a random way, and the number of mines will appear
    // on first number of index.
    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(lst.begin(),lst.end(),std::default_random_engine(seed));

    Matrix x(length,std::vector<int>(width,0));
    Matrix checkX(length,std::vector<int>(width,0));
    if(mines>total) mines = total;
    for(int i=0;i<mines;i++){
        int num = lst.at(i);
        int l = num/width;
        int w = num%width;
        x[l][w] = -1;
        checkX[l][w] = -1;
        // add 1 to every mines around.
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

    Global::getInstance().map = x;
    Global::getInstance().check_map = checkX;
    Global::getInstance().width = width;
    Global::getInstance().length = length;
}
void checkNext(int x,int y){
//    qDebug()<<"reach point"<<y<<x;
    if(Global::getInstance().map[y][x] == -1){
//        qDebug()<<"is Mine";
        return ;
    }  // is mine
    if(Global::getInstance().check_map[y][x] == 1){
//        qDebug()<<"is Checked";
        return ;
    }//checked
    Global::getInstance().check_map[y][x] = 1;
    if(Global::getInstance().map[y][x] ==0){
        if((y-1)>=0){
//            qDebug()<<"enter"<<y-1<<x;
            checkNext(x,y-1);
            if((x-1)>=0){
//                qDebug()<<"enter"<<y-1<<x-1;
                checkNext(x-1,y-1);
            }
            if((x+1)<Global::getInstance().width){
//                qDebug()<<"enter"<<y-1<<x+1;
                checkNext(x+1,y-1);
            }
        }
        if((x-1)>=0){
//            qDebug()<<"enter"<<y<<x-1;
            checkNext(x-1,y);
        }
        if((x+1)<Global::getInstance().width){
//            qDebug()<<"enter"<<y<<x+1;
            checkNext(x+1,y);
        }


        if((y+1)<Global::getInstance().length){
//            qDebug()<<"enter"<<y+1<<x;
            checkNext(x,y+1);
            if((x-1)>=0){
//                qDebug()<<"enter"<<y+1<<x-1;
                checkNext(x-1,y+1);
            }
            if((x+1)<Global::getInstance().width){
//                qDebug()<<"enter"<<y+1<<x+1;
                checkNext(x+1,y+1);
            }
        }
    }

}
bool MineAlgorithm::Click(int x, int y){
    if(x<0||x>=Global::getInstance().width
            ||y<0||y>=Global::getInstance().length) return false;
    if(Global::getInstance().check_map[y][x] == -1){
        return true;
    }
    checkNext(x,y);
    return false;
}
/**
 * @brief Tools::PrintMap
 * @param matrix
 * print maps for test only
 */
void MineAlgorithm::PrintMap(const Matrix &matrix){
    if(matrix.empty()) return;
    auto length = matrix.size();
    auto width = matrix[0].size();
    std::cout<<"--------------"<<std::endl;
    for(int i=0;i<length;i++){
        std::string str;
        for(int j=0;j<width;j++){
            int num = matrix[i][j];
            if(num!=-1)str = str.append(" ");
            str = str.append(std::to_string(num)).append(" ");
        }
        std::cout<<str<<std::endl;
    }
    std::cout<<"--------------"<<std::endl;
}
