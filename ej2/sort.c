/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
    if(x.rank <= y.rank) return true;
    else return false;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}

static void swap(player_t a[], unsigned int i, unsigned int j){
    player_t tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
    
    unsigned int piv = izq;
    int i = izq+1;
    int j = der;
    while(i <= j){
        if(goes_before(a[i], a[piv])) i++;
        if(!goes_before(a[j], a[piv]) || a[j].rank == a[piv].rank) j--;
        if((!goes_before(a[i], a[piv]) || a[i].rank == a[piv].rank ) && goes_before(a[j], a[piv]) && i<=j){
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, piv, j);
    piv = j;

    return piv;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    
    if(der > izq){
        unsigned int piv = partition(a, izq, der);
        
        quick_sort_rec(a, izq, piv);
        quick_sort_rec(a, piv+1, der);
    }
}

void sort(player_t a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}