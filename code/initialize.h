//
//  initialize.h
//  News
//
//  Created by ZH on 16/1/30.
//  Copyright © 2016年 ZH. All rights reserved.
//

#ifndef initialize_h
#define initialize_h
#include "Class.h"
#include <random>

using namespace std;


bool percent(double p) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> ran(0,100);
    if(ran(mt) / 100.0 <= p) return 1;
    else return 0;
}

void initialize(Country *America, Country *China,Country *Britain,Country *Canada,Country *India) {
    int i,j,k,l,x,y,t,m,s;
    
    (*America).population = 309350000;
    (*America).newspaper = 0.6;
    (*America).telegraph = 0.1;
    (*America).radio = 0.5;
    (*America).television = 0.5;
    (*America).internet = 0.76;
    //(*America).cellphone = 0.6;
    (*America).inter = 0.8;
    (*America).financial = 0.5;
    (*America).political = 0.6;
    (*America).recreational = 0.7;
    (*America).scientific = 0.4;
    
    (*China).population = 1340910000;
    (*China).newspaper = 0.7;
    (*China).telegraph = 0.1;
    (*China).radio = 0.6;
    (*China).television = 0.3;
    (*China).internet = 0.14;
    //(*China).cellphone = 0.5;
    (*China).inter = 0.7;
    (*China).financial = 0.4;
    (*China).political = 0.5;
    (*China).recreational = 0.6;
    (*China).scientific = 0.3;
    
    (*Britain).population = 62770000;
    (*Britain).newspaper = 0.6;
    (*Britain).telegraph = 0.1;
    (*Britain).radio = 0.5;
    (*Britain).television = 0.4;
    (*Britain).internet = 0.73;
    //(*Britain).cellphone = 0.5;
    (*Britain).inter = 0.8;
    (*Britain).financial = 0.8;
    (*Britain).financial = 0.6;
    (*Britain).political = 0.5;
    (*Britain).recreational = 0.7;
    (*Britain).scientific = 0.5;
    
    (*Canada).population = 34010000;
    (*Canada).newspaper = 0.6;
    (*Canada).telegraph = 0.1;
    (*Canada).radio = 0.5;
    (*Canada).television = 0.4;
    (*Canada).internet = 0.74;
    //(*Canada).cellphone = 0.6;
    (*Canada).inter = 0.7;
    (*Canada).financial = 0.5;
    (*Canada).political = 0.6;
    (*Canada).recreational = 0.6;
    (*Canada).scientific = 0.4;
    
    (*India).population = 1205620000;
    (*India).newspaper = 0.5;
    (*India).telegraph = 0.1;
    (*India).radio = 0.4;
    (*India).television = 0.3;
    (*India).internet = 0.04;
    //(*India).cellphone = 0.2;
    (*India).inter = 0.5;
    (*India).financial = 0.5;
    (*India).political = 0.5;
    (*India).recreational = 0.6;
    (*India).scientific = 0.2;
    
    for(i = 0; i <= N + 1; i++) {
        for(j = 0; j <= N + 1; j ++) {
            (*America).a[i][j].w = 0;
            (*China).a[i][j].w = 0;
            (*Britain).a[i][j].w = 0;
            (*Canada).a[i][j].w = 0;
            (*India).a[i][j].w = 0;
        }
    }
    
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> ran1(0,200);
    uniform_int_distribution<int> ran2(0,50);
    
    //srand((unsigned)time(NULL));
    
    for(i = 1; i <= N; i ++) {
        for(j = 1; j <= N; j ++) {
            (*America).a[i][j].b = ran1(mt) / 100.0 - 1;
            (*China).a[i][j].b = ran1(mt) / 100.0 - 1;
            (*Britain).a[i][j].b = ran1(mt) / 100.0 - 1;
            (*Canada).a[i][j].b = ran1(mt) / 100.0 - 1;
            (*India).a[i][j].b = ran1(mt) / 100.0 - 1;
            
            (*America).a[i][j].m = ran2(mt) / 100.0;
            (*China).a[i][j].m = ran2(mt) / 100.0;
            (*Britain).a[i][j].m = ran2(mt) / 100.0;
            (*Canada).a[i][j].m = ran2(mt) / 100.0;
            (*India).a[i][j].m = ran2(mt) / 100.0;
            
            (*America).a[i][j].w_n = percent((*America).newspaper);
            (*America).a[i][j].w_t = percent((*America).telegraph);
            (*America).a[i][j].w_r = percent((*America).radio);
            (*America).a[i][j].w_v = percent((*America).television);
            (*America).a[i][j].w_i = percent((*America).internet);
            //(*America).a[i][j].w_c = percent((*America).cellphone);
            (*America).a[i][j].i_inter = percent((*America).inter);
            (*America).a[i][j].i_f = percent((*America).financial);
            (*America).a[i][j].i_p = percent((*America).political);
            (*America).a[i][j].i_r = percent((*America).recreational);
            (*America).a[i][j].i_s = percent((*America).scientific);
            
            (*China).a[i][j].w_n = percent((*China).newspaper);
            (*China).a[i][j].w_t = percent((*China).telegraph);
            (*China).a[i][j].w_r = percent((*China).radio);
            (*China).a[i][j].w_v = percent((*China).television);
            (*China).a[i][j].w_i = percent((*China).internet);
            //(*China).a[i][j].w_c = percent((*China).cellphone);
            (*China).a[i][j].i_inter = percent((*China).inter);
            (*China).a[i][j].i_f = percent((*China).financial);
            (*China).a[i][j].i_p = percent((*China).political);
            (*China).a[i][j].i_r = percent((*China).recreational);
            (*China).a[i][j].i_s = percent((*China).scientific);
            
            (*Britain).a[i][j].w_n = percent((*Britain).newspaper);
            (*Britain).a[i][j].w_t = percent((*Britain).telegraph);
            (*Britain).a[i][j].w_r = percent((*Britain).radio);
            (*Britain).a[i][j].w_v = percent((*Britain).television);
            (*Britain).a[i][j].w_i = percent((*Britain).internet);
            //(*Britain).a[i][j].w_c = percent((*Britain).cellphone);
            (*Britain).a[i][j].i_inter = percent((*Britain).inter);
            (*Britain).a[i][j].i_f = percent((*Britain).financial);
            (*Britain).a[i][j].i_p = percent((*Britain).political);
            (*Britain).a[i][j].i_r = percent((*Britain).recreational);
            (*Britain).a[i][j].i_s = percent((*Britain).scientific);
            
            (*Canada).a[i][j].w_n = percent((*Canada).newspaper);
            (*Canada).a[i][j].w_t = percent((*Canada).telegraph);
            (*Canada).a[i][j].w_r = percent((*Canada).radio);
            (*Canada).a[i][j].w_v = percent((*Canada).television);
            (*Canada).a[i][j].w_i = percent((*Canada).internet);
            //(*Canada).a[i][j].w_c = percent((*Canada).cellphone);
            (*Canada).a[i][j].i_inter = percent((*Canada).inter);
            (*Canada).a[i][j].i_f = percent((*Canada).financial);
            (*Canada).a[i][j].i_p = percent((*Canada).political);
            (*Canada).a[i][j].i_r = percent((*Canada).recreational);
            (*Canada).a[i][j].i_s = percent((*Canada).scientific);
            
            (*India).a[i][j].w_n = percent((*India).newspaper);
            (*India).a[i][j].w_t = percent((*India).telegraph);
            (*India).a[i][j].w_r = percent((*India).radio);
            (*India).a[i][j].w_v = percent((*India).television);
            (*India).a[i][j].w_i = percent((*India).internet);
            //(*India).a[i][j].w_c = percent((*India).cellphone);
            (*India).a[i][j].i_inter = percent((*India).inter);
            (*India).a[i][j].i_f = percent((*India).financial);
            (*India).a[i][j].i_p = percent((*India).political);
            (*India).a[i][j].i_r = percent((*India).recreational);
            (*India).a[i][j].i_s = percent((*India).scientific);
            
            for(k = 1; k <= M; k ++) {
                if((*America).a[i][j].w_i == 1)
                {
                    s = 0;
                    while(1) {
                        t = rand() % (N * N) + 1;
                        x = t / N + 1;
                        y = t % N;
                        if(y == 0) {
                            x--;
                            y = N;
                        }
                        while((*America).a[x][y].w_i == 0) {
                            t = rand() % (N * N) + 1;
                            x = t / N + 1;
                            y = t % N;
                            if(y == 0) {
                                x--;
                                y = N;
                            }
                        }
                        if(x == i && y == j) continue;
                        m = 1;
                        for(l = 1; l <= k - 1; l ++) {
                            if((*America).a[i][j].f[l][1] == x && (*America).a[i][j].f[l][2] == y) {
                                m = 0;
                                break;
                            }
                        }
                        if(m == 1) {
                            (*America).a[i][j].f[k][1] = x;
                            (*America).a[i][j].f[k][2] = y;
                            break;
                        }
                        if(s == 10) break;
                        s++;
                    }
                }
                
                if((*China).a[i][j].w_i == 1)
                {
                    s = 0;
                    while(1) {
                        t = rand() % (N * N) + 1;
                        x = t / N + 1;
                        y = t % N;
                        if(y == 0) {
                            x--;
                            y = N;
                        }
                        while((*China).a[x][y].w_i == 0) {
                            t = rand() % (N * N) + 1;
                            x = t / N + 1;
                            y = t % N;
                            if(y == 0) {
                                x--;
                                y = N;
                            }
                        }
                        m = 1;
                        for(l = 1; l <= k - 1; l ++) {
                            if((*China).a[i][j].f[l][1] == x && (*China).a[i][j].f[l][2] == y) {
                                m = 0;
                                break;
                            }
                        }
                        if(m == 1) {
                            (*China).a[i][j].f[k][1] = x;
                            (*China).a[i][j].f[k][2] = y;
                            break;
                        }
                        if(s == 10) break;
                        s++;
                    }
                }
                
                if((*Britain).a[i][j].w_i == 1)
                {
                    s = 0;
                    while(1) {
                        t = rand() % (N * N) + 1;
                        x = t / N + 1;
                        y = t % N;
                        if(y == 0) {
                            x--;
                            y = N;
                        }
                        while((*Britain).a[x][y].w_i == 0) {
                            t = rand() % (N * N) + 1;
                            x = t / N + 1;
                            y = t % N;
                            if(y == 0) {
                                x--;
                                y = N;
                            }
                        }
                        m = 1;
                        for(l = 1; l <= k - 1; l ++) {
                            if((*Britain).a[i][j].f[l][1] == x && (*Britain).a[i][j].f[l][2] == y) {
                                m = 0;
                                break;
                            }
                        }
                        if(m == 1) {
                            (*Britain).a[i][j].f[k][1] = x;
                            (*Britain).a[i][j].f[k][2] = y;
                            break;
                        }
                        if(s == 10) break;
                        s++;
                    }
                }
                
                if((*Canada).a[i][j].w_i == 1)
                {
                    s = 0;
                    while(1) {
                        t = rand() % (N * N) + 1;
                        x = t / N + 1;
                        y = t % N;
                        if(y == 0) {
                            x--;
                            y = N;
                        }
                        while((*Canada).a[x][y].w_i == 0) {
                            t = rand() % (N * N) + 1;
                            x = t / N + 1;
                            y = t % N;
                            if(y == 0) {
                                x--;
                                y = N;
                            }
                        }
                        m = 1;
                        for(l = 1; l <= k - 1; l ++) {
                            if((*Canada).a[i][j].f[l][1] == x && (*Canada).a[i][j].f[l][2] == y) {
                                m = 0;
                                break;
                            }
                        }
                        if(m == 1) {
                            (*Canada).a[i][j].f[k][1] = x;
                            (*Canada).a[i][j].f[k][2] = y;
                            break;
                        }
                        if(s == 10) break;
                        s++;
                    }
                }
                
                if((*India).a[i][j].w_i == 1)
                {
                    s = 0;
                    while(1) {
                        t = rand() % (N * N) + 1;
                        x = t / N + 1;
                        y = t % N;
                        if(y == 0) {
                            x--;
                            y = N;
                        }
                        while((*India).a[x][y].w_i == 0) {
                            t = rand() % (N * N) + 1;
                            x = t / N + 1;
                            y = t % N;
                            if(y == 0) {
                                x--;
                                y = N;
                            }
                        }
                        m = 1;
                        for(l = 1; l <= k - 1; l ++) {
                            if((*India).a[i][j].f[l][1] == x && (*India).a[i][j].f[l][2] == y) {
                                m = 0;
                                break;
                            }
                        }
                        if(m == 1) {
                            (*India).a[i][j].f[k][1] = x;
                            (*India).a[i][j].f[k][2] = y;
                            break;
                        }
                        if(s == 10) break;
                        s++;
                    }
                }
            }
        }
    }
}

#endif /* initialize_h */
