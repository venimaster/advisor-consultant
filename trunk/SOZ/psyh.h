#ifndef PSYH_H
#define PSYH_H

#include "stdlib.h"

class Psyh {
public:

    enum AC //Answer Code
    {
        RIGIDNOST         = 1,
        GIBKOST           ,
        HYDOZHNIK         ,
        MUSLITEL          ,
        MELANHOLIK        ,
        HOLERIK           ,
        FLEGMATIK         ,
        SANGVINIK         ,
        ISKRENOST         ,
        NEISKRENOST       ,
        POLEZAVISIMOST    ,
        POLENEZAVISIMOST
    };

private:
    AC* m_result;

private:
    void addResult(const AC& res);

public:
    void calcRigidnost(int* a);
    void calcHudozhnik(int* a);
    void calcTemperament(int* a);
    void calcFigyru(char* a,const double& time);

    AC* getResult();

    Psyh()
    {
        m_result = 0;
    }

    ~Psyh()
    {
        free(m_result);
    }
};

#endif // PSYH_H
