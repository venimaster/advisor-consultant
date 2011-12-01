#include "psyh.h"

void Psyh::addResult(const AC& res)
{
    if(m_result != NULL)
    {
        const int N = sizeof(m_result)/sizeof(AC);
        AC* temp = (AC*)malloc(N*sizeof(AC));
        for(int i = 0; i < N-1; ++i)
        {
            temp[i] = m_result[i];
        }
        temp[N - 1] = res;
        free(m_result);
        m_result = temp;
    }
    else
    {
        m_result = (AC*)malloc(sizeof(AC));
        m_result[0] = res;
    }
}

void Psyh::calcRigidnost(int* a)
{
    const int N = sizeof(a)/sizeof(int);
    if(N == 50)
    {
        int yes[] = {2, 3, 5, 7, 10, 12, 15, 16, 17, 19, 21, 22, 24, 25, 28, 29, 32, 35, 36, 37, 41, 42, 45, 47, 49};
        int pos = 0;
        int score = 0;
        for(int i = 0; i < N; ++i)
        {
            switch(a[i])
            {
            case 0: //нет
            {
                if(i != yes[pos])
                {
                    ++score;
                }
                else
                {
                    ++pos;
                }
                break;
            }
            case 1: //да
            {
                if(i == yes[pos])
                {
                    ++score;
                    ++pos;
                }
                break;
            }
            }
        }
        if( (score>=0) && (score<27) )
        {
            addResult(GIBKOST);
        }
        if( score > 13 )
        {
            addResult(RIGIDNOST);
        }
    }
}

void Psyh::calcHudozhnik(int* a)
{
    const int N = sizeof(a)/sizeof(int);
    if(N == 10)
    {
        const int left = a[1] + a[2] + a[5] + a[8] + a[9];
        const int right = a[3] + a[4] + a[6] + a[7] + a[10];
        if( (left - right) >= 5)
        {
            addResult(MUSLITEL);
        }
        else if((right - left) >= 5)
        {
            addResult(HYDOZHNIK);
        }
        else
        {
            addResult(HYDOZHNIK);
            addResult(MUSLITEL);
        }
    }
}

void Psyh::calcFigyru(char* a,const double& time)
{
    const int N = sizeof(a)/sizeof(char);
    if(N == 30)
    {
        char pattern[] = {'А','Б','В','Г','В','В','А','В','Д','Д',
                        'Б','А','А','В','Б','Д','А','А','Б','В',
                        'Г','Б','Г','А','Д','Б','А','Д','В','Б'};
        int score = 0;
        for(int i = 0; i < N; ++i)
        {
            if(a[i] == pattern[i])
            {
                ++score;
            }
        }
        const double solve = score / time;
        if(solve > 2.5)
        {
            addResult(POLEZAVISIMOST);
        }
        else
        {
            addResult(POLENEZAVISIMOST);
        }
    }
}

bool isBelong(int value, int* array)
{
    const int N = sizeof(array)/sizeof(int);
    for(int i = 0; i < N; ++i)
    {
        if(value == array[i])
        {
            return true;
        }
    }
    return false;
}

void Psyh::calcTemperament(int* a)
{
    int iskrennost_yes[] = {6,24,36};
    int iskrennost_no[] = {12,18,30,42,48,54};
    int nestabilnost_yes[] = {2,4,7,9,11,14,16,19,21,23,26,28,31,33,35,38,40,43,45,47,50,52,55,57};
    int ekstraversia_yes[] = {1,3,8,10,13,17,22,25,27,39,44,46,49,53,56};
    int ekstraversia_no[] = {5,15,20,29,32,34,37,41,51};
    const int N = sizeof(a)/sizeof(int);

    int iskrennost_score = 0,
        nestabilnost_score = 0,
        ekstraversia_score = 0;

    if(N == 57)
    {
        for(int i = 0; i < N; ++i)
        {
            if(a[i] == 0)
            {
                if(isBelong(i,iskrennost_no)) ++iskrennost_score;
                if(isBelong(i,ekstraversia_no)) ++ekstraversia_score;
            }
            else
            {
                if(isBelong(i,iskrennost_yes)) ++iskrennost_score;
                if(isBelong(i,nestabilnost_yes)) ++nestabilnost_score;
                if(isBelong(i,ekstraversia_yes)) ++ekstraversia_score;
            }
        }
        if(iskrennost_score < 5)
        {
            addResult(ISKRENOST);
        }
        else
        {
            addResult(NEISKRENOST);
        }

        if((nestabilnost_score <= 12) && (ekstraversia_score <= 12))
        {
            addResult(FLEGMATIK);
        }
        if((nestabilnost_score <= 12) && (ekstraversia_score > 12))
        {
            addResult(SANGVINIK);
        }
        if((nestabilnost_score > 12) && (ekstraversia_score <= 12))
        {
            addResult(MELANHOLIK);
        }
        if((nestabilnost_score > 12) && (ekstraversia_score > 12))
        {
            addResult(HOLERIK);
        }
    }
}

Psyh::AC* Psyh::getResult()
{
    return m_result;
}
