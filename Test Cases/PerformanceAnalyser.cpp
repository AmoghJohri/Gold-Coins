#include<bits/stdc++.h>
#include<fstream>
using namespace std;

/* Global variables declarations */
int weighings = 0;
int token;

/* Functions declaration */
int weightOfGenuineCoin(int, vector<int>);
int balance(int, int);
int B(int);

int main(){
    ofstream myfile;
    myfile.open ("Report.txt");

    int numberOfCoins;
    cin>>numberOfCoins;
    vector<int> coins;
    srand(time(0)); 

    int numOf1s = 0;
    int numOf0s = 0;

    for(int i = 0; i < numberOfCoins; i++){
        int x = rand()%2;
        myfile << x << " ";
        if(x == 0)
            numOf0s = numOf0s + 1;
        else
            numOf1s = numOf1s + 1;
        coins.push_back(x);
    }
    token = coins[coins.size() - 1];    // Last coin
    if(numOf0s == numOf1s)
    {
        myfile << "\n" << "INVALID INPUT!!!" << "\n";
        return 0;
    }

    
    myfile<<"\n\nNumber of coins: "<< numberOfCoins;
    myfile<<"\nWeight of genuine coin: "<< weightOfGenuineCoin(numberOfCoins, coins)<<endl;
    myfile<<"Number of Weighings: "<< weighings << endl;
    myfile<<"Number of Weighing permitted: "<< numberOfCoins - B(numberOfCoins) << endl;
    myfile <<"Num Of 1s : " << numOf1s;
    myfile <<"\nNum Of 0s : " << numOf0s;
    myfile <<"\n";

    myfile.close();
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
        token = coins[coins.size() - 1];
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

int B(int num)
{
    int bin;
    int output = 0;
    while (num > 0)
    {
        bin = num % 2;
        output = output + bin;
        num /= 2;
    }
    return output;
}
