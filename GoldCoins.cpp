#include<bits/stdc++.h>
using namespace std;

int steps = 0;

int token;

int weightOfGenuineCoin(int, vector<int>);
int compare(int, int);

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    token = arr[arr.size() - 1];

    cout<<"Weight: "<< weightOfGenuineCoin(n, arr)<<endl;
    cout<<"Steps: "<< steps << endl;
    


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
   return 0;
}


int weightOfGenuineCoin(int n, vector<int> arr){
    vector<int> aux;
    //Even
    if(n%2 == 0){
        int counter = 0;
        while(counter < n-1){
            if(compare(arr[counter], arr[counter + 1])){
                aux.push_back(arr[counter]);
            }
            steps += 1;
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

    //Odd
    else{
        arr.erase(arr.end() - 1);
        n = n - 1;
        int counter = 0;
        while(counter < n-1){
            if(compare(arr[counter], arr[counter + 1])){
                aux.push_back(arr[counter]);
            }
            steps += 1;
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

int compare(int w1, int w2){
    if(w1 == w2){
        return 1;
    }
    return 0;
}
