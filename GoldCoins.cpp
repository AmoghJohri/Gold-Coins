#include<bits/stdc++.h>
using namespace std;

/* Global variables declarations */
int weighings = 0; // Counts the number of times two coins are weighed or compared
int token; // Used to store a coin in case of total number of coins being odd 

/* Functions declaration */

/* This function takes the "total number of coins" and the "array of coins", and gives out the genuin coin (i.e. the weight of the coin which is in majority).
It calls the balance function (i.e. the function which compares or weighs two coins) a maximum of n-B(n) times, where B(n) represents the number of 1s in the binary representation of n */
int weightOfGenuineCoin(int, vector<int>); 

/* This function takes two coins (two integers consisting of the weights of two coins) as its input and returns 1 for if their weights are equal and 0 for if their weights are unequal*/
int balance(int, int);

int main(){
    int numberOfCoins; // Stores the total number of coins as an integer
    cin>>numberOfCoins; // Takes a command-line input for the total number of coins
    vector<int> coins; // Forms an empty array of integers
    for(int i = 0; i < numberOfCoins; i++){ // takes the coins (weight of the coin) as input and adds the coin to the array named "coins". The input is taken through the command line with a space seperating two inputs. For the purpose of simplicity, we have assumed the two types of inputs to be 1 or 0
        int x;
        cin>>x;
        coins.push_back(x);
    }
    token = coins[coins.size() - 1];    // Stores the last coin of the input

    cout<<"Weight of The Genuine Coin: "<< weightOfGenuineCoin(numberOfCoins, coins)<<endl; // Calls the function which returns the weight of the genuine coins given the input as total number of coins and the array of coins
    cout<<"Number of Weighings: "<< weighings << endl; // Prints the number of weighings (number of times balance function was called by the weightOfGenuineCoin function) that was required in order to obtain the weight of the genuine coin
   return 0;
}


int weightOfGenuineCoin(int numberOfCoins, vector<int> coins){
    vector<int> aux; //Defines an empty array of integers, at every stage, two adjacent coins are compared with the balance function and if they are equal one of the coins are added to this array. In case of the weight of the coins being different, both the coins are ignored
    /* Case 1 : Number of coins are even */
    if(numberOfCoins%2 == 0){ 
        int counter = 0; // Defining a counter in order to traverse the array of coins
        while(counter < numberOfCoins-1){ //While we have at least two coins left in the array towards the right
            if(balance(coins[counter], coins[counter + 1])){ // Compares the two adjacent coins with the balance function
                aux.push_back(coins[counter]); // In case of the weights of the coins being equal, they are added to the aux array
            }
            weighings += 1; // The weighings or the variable storing the total number of calls of balance function is incremented
            counter += 2; // The counter is incremented by 2, as we consider the coin and the next adjacent coin in every execution of the loop body
        }
        if(aux.size() == 1){ // If the size of the aux array formed is 1, i.e. only one coin is present in it, we return the coin present in it (the weight of that coin) as the final output
            return aux[0];
        } else if(aux.size() == 0){ // In the case of the aux array being empty, i.e. no coin is present in it, we return the coin stored as token as the output
            return token;
        } else{
            return weightOfGenuineCoin(aux.size(), aux); // For all other cases, we recursively call the weightOfGenuineCoin function again with the new inputs being the size of the aux array formed and the aux array
        }

    }

    /* Case 2 : Number of coins are odd */
    else{
        token = coins[coins.size() - 1]; // In case the number of total coins being odd, the last coin is stored as token
        coins.erase(coins.end() - 1); // The last coin is then removed from the array
        numberOfCoins = numberOfCoins - 1; // The total number of coins is decremented by 1
        int counter = 0; // Defining a counter in order to traverse the array of coins
        while(counter < numberOfCoins-1){// While we have at least two coins left in the array towards the right
            if(balance(coins[counter], coins[counter + 1])){// Compares the two adjacent coins with the balance function
                aux.push_back(coins[counter]);// In case of the weights of the coins being equal, they are added to the aux array
            }
            weighings += 1; // The weighings or the variable storing the total number of calls of balance function is incremented
            counter += 2; // The counter is incremented by 2, as we consider the coin and the next adjacent coin in every execution of the loop body
        }
        if(aux.size() % 2 == 1){ // In acase the number of coins in the aux array is odd
            token = aux[aux.size() - 1]; // we store the last coin as the token
        } 
        if(aux.size() == 1){ // If the size of the aux array formed is 1, i.e. only one coin is present in it, we return the coin present in it (the weight of that coin) as the final output
            return aux[0];
        } else if(aux.size() == 0){ // In the case of the aux array being empty, i.e. no coin is present in it, we return the coin stored as token as the output
            return token;
        } else{
            return weightOfGenuineCoin(aux.size(), aux); // For all other cases, we recursively call the weightOfGenuineCoin function again with the new inputs being the size of the aux array formed and the aux array
        }
    }
}

/* Helper function */
int balance(int w1, int w2){ // Takes the input as two coins (weights of two coins)
    if(w1 == w2){ // Compares the weight of two coins
        return 1; // In case of weights being equal, returns 1
    }
    return 0; // In case of weights being unequal, returns 0
}
