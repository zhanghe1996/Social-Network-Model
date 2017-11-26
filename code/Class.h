//
//  Class.h
//  News
//
//  Created by ZH on 16/1/30.
//  Copyright © 2016年 ZH. All rights reserved.
//

#ifndef Class_h
#define Class_h
#include "initialize.h"

#define M 5
#define N 50

/*class News{
public:
    double s; //importance of the news
    
};*/

class Individual{
public:
    double b; //one's attitude towards the news
    double m; //one's likelihood to believe others
    bool w; //whether the one know the news
    
    bool w_n; //whether the one covered by newspapers
    bool w_t; //whether the one covered by telegraph
    bool w_r; //whether the one covered by radio
    bool w_v; //whether the one covered by television
    bool w_i; //whether the one covered by internet
    //bool w_c; //whether the one has cellphone
    
    bool i_inter; //whether insterested in news from foreign countries
    
    bool i_f; //whether insterested in financial news
    bool i_p; //whether insterested in political news
    bool i_r; //whether insterested in recreational news
    bool i_s; //whether insterested in scientific news
    
    int f[M+1][3]; //one's M friends with internet connection
};

class Country{
public:
    int population; //population of this country
    
    double newspaper; //coverage rate of newspapers
    double telegraph; //coverage rate of telegraph
    double radio; //coverage rate of radio
    double television; //coverage rate of televisions
    double internet; //coverage rate of internet
    //double cellphone; //coverage rate of celephone
    
    double inter; //interests in news form foreign countries
    
    double financial; //interests in financial news
    double political; //interests in political news
    double recreational; //interests in recreational news
    double scientific; //interests in scientific news
    
    Individual a[N+2][N+2]; //condition of a part of individuals in this country
};

#endif /* Class_h */
