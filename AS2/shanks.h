// Duy Nhan Cao
// File: shanks.h

#ifndef GMP
#define GMP

#include "gmp.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    mpz_t value;
    mpz_t exp;
} shanks_t;

struct Node{
    shanks_t data;
    struct Node *right, *left;
};

struct Node* newNode(shanks_t data) {
    struct Node* temp = (struct Node*) malloc(sizeof( struct Node ));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

shanks_t makeData(const mpz_t g, mpz_t exp, const mpz_t p);
void addNode(struct Node *root, struct Node *leave);
int searchTree(struct Node *root, shanks_t data, mpz_t exp);

void shanks(mpz_t rop, const mpz_t p, const mpz_t g, const mpz_t h) {
    mpz_t n, p2, exp, exp2;
    mpz_init(n);
    mpz_init(p2);
    mpz_init_set_ui(exp, 0);
    mpz_init(exp2);
    
    struct Node *root;
    shanks_t dat;
    
    mpz_sub_ui(p2, p, 1);
    mpz_sqrt(n, p2);
    mpz_add_ui(n, n, 1);
    
    dat = makeData(g, exp, p);
    mpz_add_ui(exp, exp, 1);
    
    root = newNode(dat);
    
    while(mpz_cmp(exp, n)!=0) {
        dat = makeData(g, exp, p);
        struct Node* tem;
        tem = newNode(dat);
        
        addNode(root, tem);
        
        mpz_add_ui(exp, exp, 1);
    }
    
    mpz_set_ui(exp, 0);
    while(mpz_cmp(exp, n)!=0) {
        mpz_mul(exp2, exp, n);
        
        dat = makeData(g, exp2, p);
        
        mpz_invert(dat.value, dat.value, p);
        mpz_mul(dat.value, dat.value, h);
        
        mpz_tdiv_r(dat.value, dat.value, p);
        
        //gmp_printf("[%Zd %Zd]", exp, dat.value);
        
        if(searchTree(root, dat, exp)) {
            mpz_add(rop, exp, exp2);
            break;
        }
        mpz_add_ui(exp, exp, 1);
    }
}

void addNode(struct Node *root, struct Node *leave) {
    struct Node *tem;
    tem = root;
    while(1) {
        if(mpz_cmp(tem->data.value, leave->data.value)<0) {
            if(tem->right == NULL) {
                
                //gmp_printf("| %Zd - %Zd |", leave->data.value, leave->data.exp);
                
                tem->right = newNode(leave->data);
                break;
            }
            tem = tem->right;
        }
        else {
            if(tem->left == NULL) {
                
                //gmp_printf("%Zd - %Zd", leave->data.value, leave->data.exp);
                
                tem->left = newNode(leave->data);
                break;
            }
            tem = tem->left;
        }
    }
    
}

shanks_t makeData(const mpz_t g, mpz_t exp, const mpz_t p) {
    shanks_t dat;
    mpz_init(dat.value);
    mpz_init(dat.exp);
    
    mpz_powm(dat.value, g, exp, p);
    mpz_set(dat.exp, exp);
    
    return dat;
}

int searchTree(struct Node *root, shanks_t data, mpz_t exp) {
    struct Node *tem;
    tem = root;
    
    while(1) {
        if(tem == NULL) {
            //printf("-");
            return 0;
        }
        //printf(".");
        if(mpz_cmp(tem->data.value, data.value)<0) {
            tem = tem->right;
            //printf("r");
        } else
            if(mpz_cmp(tem->data.value, data.value)>0) {
                tem = tem->left;
                //printf("l");
            } else {
                mpz_set(exp, tem->data.exp);
                
                return 1;
            }
    }
}


#endif

