#include<bits/stdc++.h>
using namespace std;

/* Global variables declarations */
int weighings = 0;
int token;

/* Functions declaration */
int weightOfGenuineCoin(int, vector<int>);
int balance(int, int);

int main(){
    int numberOfCoins;
    cin>>numberOfCoins;
    vector<int> coins;
    for(int i = 0; i < numberOfCoins; i++){
        int x;
        cin>>x;
        coins.push_back(x);
    }
    token = coins[coins.size() - 1];    // Last coin

    cout<<"Weight of the genuine coin: "<< weightOfGenuineCoin(numberOfCoins, coins)<<endl;
    cout<<"Number of weighings required: "<< weighings << endl;
   return 0;
}


int weightOfGenuineCoin(int numberOfCoins, vector<int> coins){
    vector<int> aux;
    /* Case 1 : Number of coins are even */
    if(numberOfCoins%2 == 0){
        int counter = 0;
        while(counter < numberOfCoins-1){
            if(balance(coins[counter], coins[counter + 1])){
                aux.push_back(coins[counter]);
            }
            weighings += 1;
            counter += 2;
        }
        if(aux.size() == 1){
            return aux[0];
        } else if(aux.size() == 0){
            return token;
        } else{
            return weightOfGenuineCoin(aux.size(), aux);
        }

    }

    /* Case 2 : Number of coins are odd */
    else{
        token = coins[coinss.size() - 1];
        coins.erase(coins.end() - 1);
        numberOfCoins = numberOfCoins - 1;
        int counter = 0;
        while(counter < numberOfCoins-1){
            if(balance(coins[counter], coins[counter + 1])){
                aux.push_back(coins[counter]);
            }
            weighings += 1;
            counter += 2;
        }
        if(aux.size() % 2 == 1){
            token = aux[aux.size() - 1];
        } 
        if(aux.size() == 1){
            return aux[0];
        } else if(aux.size() == 0){
            return token;
        } else{
            return weightOfGenuineCoin(aux.size(), aux);
        }
    }
}

/* Helper function */
int balance(int w1, int w2){
    if(w1 == w2){
        return 1;
    }
    return 0;
}
