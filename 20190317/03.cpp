//
// Created by 邓萌达 on 2019-03-19.
//

# include <cstdio>
# include <iostream>
# include <cmath>
# include <cstring>

using namespace std;

struct node {
    int data;
    node * next;
};

node * p;

inline void init(){
    p = (node *)malloc(sizeof(p));
    p = NULL;
}

inline void insert(node * first,int date){
    if (!first){
        first->data=data;
        return;
    }
    node * present = first;
    for(;present->next;present=present->next);
    node * add = (node *) malloc(sizeof(add));
    add->data=data;
    add->next=NULL;
    present->next=add;
}

inline void delete_p(node * first,int data){
    node * present = first;
    node * last = first;
    for(;present;present=present->next){
        if (present->data == data)
    }
}
int main(){

}