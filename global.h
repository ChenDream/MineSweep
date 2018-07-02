#ifndef GLOBAL_H
#define GLOBAL_H
#include "stable.h"
class Global
{
public:
    static Global& getInstance(){
        static Global instance;
        return instance;
    }
    Matrix map;          //mines map
    Matrix check_map;     //checked mines map -1 resprent mines 0 resprent uncheck,1 resprent check
private:
    Global(){}
    ~Global(){}
    Global(const Global&);
    Global& operator=(const Global&);
};
#endif // GLOBAL_H
