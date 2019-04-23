#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> coins;
    /*
    Comparison : If two coins are same - take them down as 1 together.
    */

    /*
    n coins
    if n is even

    if n is odd - there'll be a coin left : last
        n-1/2 comparisons - k coins remaining
        k : [0, n/2]
        if k is odd
            keep doing comparisons the same way
        else if k is even
            keep making comparisons till you get 1,
            if you get one coin left - make that the last
            if the coins vanish, then the last coin will be the gold coin
            
    */
}