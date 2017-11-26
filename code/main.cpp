//
//  main.cpp
//  News
//
//  Created by ZH on 16/1/30.
//  Copyright © 2016年 ZH. All rights reserved.
//

#include <iostream>
#include <random>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "initialize.h"
#include "Class.h"

using namespace std;

#define P 0.2 //possibility for neighbors to meet in one unit of time

#define P_n 0.06 //minimum ratio of people who know the news needed for newpaper to publish news
#define P_t 0.05 //minimum ratio of people who know the news needed for telegraph to publish news
#define P_r 0.05 //minimum ratio of people who know the news needed for radio to publish news
#define P_v 0.06 //minimum ratio of people who know the news needed for television to publish news
#define P_i 0.04 //minimum ratio of people who know the news needed for internet to publish news

#define T_inter 2 //units of time needed for news to transfer form one country to other countries
#define T_n 10 //units of time needed for newspaper to prepare news
#define T_t 5 //units of time needed for telegraph to prepare news
#define T_r 5 //units of time needed for radio to prepare news
#define T_v 6 //units of time needed for television to prepare news
#define T_i 3 //units of time needed for internet to prepare news

bool d_n = 0, d_t = 0, d_r = 0, d_v = 0, d_i = 0; //whether each medimum decides to publish the news
int p_n = T_n, p_t = T_t, p_r = T_r, p_v = T_v, p_i = T_i; //units of time left for the news to be published after decision

bool d_inter = 0; //whether the news is decided to be publish in foreign countries;
//units of time left for the news to be published in foreign countries after decision
int p_inter_n = T_n + T_inter, p_inter_t = T_t + T_inter, p_inter_r = T_r + T_inter, p_inter_v = T_v + T_inter, p_inter_i = T_i + T_inter;

bool check_inter = 0; //whether foreign countries are checked

double value; //the value of the news
string category; //the category of the news
string country; //the starting country of the news



void check(Country *c, string name) {
    int i, j, s;
    s = 0;
    
    /*for(i = 1; i <= N; i ++) {
        for(j = 1; j <= N; j ++) {
            cout << (*c).a[i][j].i_inter << " ";
        }
        cout << endl;
    }
    cout<<endl;*/
     
    for(i = 1; i <= N; i ++) {
        for(j = 1; j <= N; j ++) {
            cout << (*c).a[i][j].w << " ";
            if((*c).a[i][j].w == 1) s++;
        }
        cout << endl;
    }
    cout << s << endl;
    
    //situaiton in the starting country
    if(name == country) {
        if(s >= N * N * P_n / value) d_n = 1;
        if(s >= N * N * P_t / value) d_t= 1;
        if(s >= N * N * P_r / value) d_r = 1;
        if(s >= N * N * P_v / value) d_v = 1;
        if(s >= N * N * P_i / value) d_i = 1;
    
        if(d_n == 1 && p_n > 0) p_n--;
        if(d_t == 1 && p_t > 0) p_t--;
        if(d_r == 1 && p_r > 0) p_r--;
        if(d_v == 1 && p_v > 0) p_v--;
        if(d_i == 1 && p_i > 0) p_i--;
    
        if(d_n == 1) cout<<"n decide"<<endl;
        if(d_t == 1) cout<<"t decide"<<endl;
        if(d_r == 1) cout<<"r decide"<<endl;
        if(d_v == 1) cout<<"v decide"<<endl;
        if(d_i == 1) cout<<"i decide"<<endl;
    
        if(p_n == 0) cout<<"n strat"<<endl;
        if(p_t == 0) cout<<"t strat"<<endl;
        if(p_r == 0) cout<<"r strat"<<endl;
        if(p_v == 0) cout<<"v strat"<<endl;
        if(p_i == 0) cout<<"i strat"<<endl;
    }
    
    //situaiton in foreign countries
    else if (check_inter == 0) {
        if(p_n == 0 || p_v == 0 || p_i == 0) d_inter = 1;
        
        if(d_inter == 1 && p_inter_n > 0) p_inter_n--;
        if(d_inter == 1 && p_inter_t > 0) p_inter_t--;
        if(d_inter == 1 && p_inter_r > 0) p_inter_r--;
        if(d_inter == 1 && p_inter_v > 0) p_inter_v--;
        if(d_inter == 1 && p_inter_i > 0) p_inter_i--;
        
        if(d_inter == 1) cout<<"inter decide"<<endl;
        
        if(p_inter_n == 0) cout<<"n strat"<<endl;
        if(p_inter_t == 0) cout<<"t strat"<<endl;
        if(p_inter_r == 0) cout<<"r strat"<<endl;
        if(p_inter_v == 0) cout<<"v strat"<<endl;
        if(p_inter_i == 0) cout<<"i strat"<<endl;
        
        check_inter = 1;
    }
    
    return;
}



void send(Country *c, int x, int y, int i, int j, string way, bool w) {
    
    //one would not recieve the news if the one does not have insterests in that category
    if(category == "financial" && (*c).a[x][y].i_f == 0) return;
    if(category == "political" && (*c).a[x][y].i_p == 0) return;
    if(category == "recreational" && (*c).a[x][y].i_r == 0) return;
    if(category == "scientific" && (*c).a[x][y].i_s == 0) return;
    
    //one in foreign countries would not recieve the news if the one does not have insterests in foreign news
    if(w == 0 && (*c).a[x][y].i_inter == 0) return;
    
    //condition where people send news by talking
    if(way == "talk") {
        if(x != 0 && y != 0 && x != N+1 && y != N+1 && percent(P*(*c).a[i][j].b*value) == 1 && (*c).a[x][y].w == 0 && (*c).a[i][j].b > 0) {
            (*c).a[x][y].w = 1;
            (*c).a[i][j].b = (1-(*c).a[i][j].m)*(*c).a[i][j].b + (*c).a[i][j].m*(*c).a[x][y].b;
            (*c).a[x][y].b = (1-(*c).a[x][y].m)*(*c).a[x][y].b + (*c).a[x][y].m*(*c).a[i][j].b;
        }
    }
    
    //condition where people send news though Internet
    if(way == "internet") {
        if(x != 0 && y != 0 && x != N+1 && y != N+1 && percent((*c).a[i][j].b*value) == 1 && (*c).a[x][y].w == 0 && (*c).a[i][j].b > 0) {
            (*c).a[x][y].w = 1;
            (*c).a[i][j].b = (1-(*c).a[i][j].m)*(*c).a[i][j].b + (*c).a[i][j].m*(*c).a[x][y].b;
            (*c).a[x][y].b = (1-(*c).a[x][y].m)*(*c).a[x][y].b + (*c).a[x][y].m*(*c).a[i][j].b;
        }
    }
    return;
}



void spread(Country *c, string name) {
    int i, j, k;
    
    //situaiton in the starting country
    if(name == country) {
        for(i = 1; i <= N; i ++) {
            for(j = 1; j <= N; j ++) {
                
                //effect of individuals
                if((*c).a[i][j].w == 1) {
                    
                    //eight neighbors
                    send(c,i-1,j-1,i,j,"talk",1);
                    send(c,i-1,j,i,j,"talk",1);
                    send(c,i-1,j+1,i,j,"talk",1);
                    send(c,i,j+1,i,j,"talk",1);
                    send(c,i+1,j+1,i,j,"talk",1);
                    send(c,i+1,j,i,j,"talk",1);
                    send(c,i+1,j-1,i,j,"talk",1);
                    send(c,i,j-1,i,j,"talk",1);
                        
                    //M friends with internet connection
                    if((*c).a[i][j].w_i == 1)
                        for(k = 1; k <= M; k ++)
                            send(c,(*c).a[i][j].f[k][1],(*c).a[i][j].f[k][2],i,j,"internet",1);
                }
            
                //effect of media
                if(category == "financial" && (*c).a[i][j].i_f == 0) continue;
                if(category == "political" && (*c).a[i][j].i_p == 0) continue;
                if(category == "recreational" && (*c).a[i][j].i_r == 0) continue;
                if(category == "scientific" && (*c).a[i][j].i_s == 0) continue;
                
                if(p_n == 0 && (*c).a[i][j].w_n == 1 && percent(value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_t == 0 && (*c).a[i][j].w_t == 1 && percent(value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_r == 0 && (*c).a[i][j].w_r == 1 && percent(value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_v == 0 && (*c).a[i][j].w_v == 1 && percent(value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_i == 0 && (*c).a[i][j].w_i == 1 && percent(value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
            }
        }
    }
        
    //situaiton in foreign countries
    else {
        for(i = 1; i <= N; i ++) {
            for(j = 1; j <= N; j ++) {
                
                //effect of individuals
                if((*c).a[i][j].w == 1) {
                    
                    //eight neighbors
                    send(c,i-1,j-1,i,j,"talk",0);
                    send(c,i-1,j,i,j,"talk",0);
                    send(c,i-1,j+1,i,j,"talk",0);
                    send(c,i,j+1,i,j,"talk",0);
                    send(c,i+1,j+1,i,j,"talk",0);
                    send(c,i+1,j,i,j,"talk",0);
                    send(c,i+1,j-1,i,j,"talk",0);
                    send(c,i,j-1,i,j,"talk",0);
                    
                    //M friends with internet connection
                    if((*c).a[i][j].w_i == 1)
                        for(k = 1; k <= M; k ++)
                            send(c,(*c).a[i][j].f[k][1],(*c).a[i][j].f[k][2],i,j,"internet",0);
                }
                
                //effect of media
                if(category == "financial" && (*c).a[i][j].i_f == 0) continue;
                if(category == "political" && (*c).a[i][j].i_p == 0) continue;
                if(category == "recreational" && (*c).a[i][j].i_r == 0) continue;
                if(category == "scientific" && (*c).a[i][j].i_s == 0) continue;
                
                if(p_inter_n == 0 && (*c).a[i][j].w_n == 1 && percent((*c).a[i][j].i_inter * value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_inter_t == 0 && (*c).a[i][j].w_t == 1 && percent((*c).a[i][j].i_inter * value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_inter_r == 0 && (*c).a[i][j].w_r == 1 && percent((*c).a[i][j].i_inter * value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_inter_v == 0 && (*c).a[i][j].w_v == 1 && percent((*c).a[i][j].i_inter * value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
                if(p_inter_i == 0 && (*c).a[i][j].w_i == 1 && percent((*c).a[i][j].i_inter * value) == 1) {
                    (*c).a[i][j].w = 1;
                    (*c).a[i][j].b = 1;
                }
            }
        }
    }
}

int main() {
    int i, start, x, y;
    Country America, China, Britain, Canada, India;
    //News news;
    initialize(&America, &China, &Britain, &Canada, &India);
    cin >> value >> category >> country;
    //cin >> value >> category;
    //news.s = s;
    
    //srand((unsigned)time(NULL));
    start = rand() % (N * N) + 1;
    x = start / N + 1;
    y = start % N;
    if(y == 0) y = N;
    
    if(country == "America") {
        America.a[x][y].b = 1;
        America.a[x][y].w = 1;
    }
    if(country == "China") {
        China.a[x][y].b = 1;
        China.a[x][y].w = 1;
    }
    if(country == "Britain") {
        Britain.a[x][y].b = 1;
        Britain.a[x][y].w = 1;
    }
    if(country == "Canada") {
        Canada.a[x][y].b = 1;
        Canada.a[x][y].w = 1;
    }
    if(country == "India") {
        India.a[x][y].b = 1;
        India.a[x][y].w = 1;
    }
    
    for(i = 1; i <= 48; i++) {
        check_inter = 0;
        check(&America, "America");
        cout<<"America"<<endl;
        check(&China, "China");
        cout<<"China"<<endl;
        check(&Britain, "Britain");
        cout<<"Britain"<<endl;
        check(&Canada, "Canada");
        cout<<"Canada"<<endl;
        check(&India, "India");
        cout<<"India"<<endl;
        
        
        spread(&America,"America");
        spread(&China,"China");
        spread(&Britain,"Britain");
        spread(&Canada,"Canada");
        spread(&India,"India");
     
        //getchar();
    }
    return 0;
}
