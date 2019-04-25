# Gold-Coins

## Problem Statement
We have ​*n* ​gold coins out of which some coins are fake and the rest are
genuine. The number of genuine coins is strictly greater than the number of fake
coins. Coins of the same type have the same weight. We have a balance using
which we can test if two coins have the same weight.

The problem is to find a genuine coin using as few weighings as possible. A
trivial algorithm to solve the problem is to pick one coin and test it with every other
coin. This uses ​*n-1*​ weighings. We want something slightly better. Design an
algorithm that finds a genuine coin in ​*n-B(n)* weighings, where ​*B(n)* denotes the
number of 1s in the binary representation of ​*n*.

## Task List
- [x] Source files
- [x] Header files
- [x] makefile
- [ ] README
    - [ ] Sources referred
    - [ ] Data structures
    - [x] Pseudo-code
    - [ ] Proof of correctness
    - [x] Instructions to compile and run
    - [ ] Defects/Side-effects
    - [ ] Individual contributions
- [ ] Subfolder of test cases
    - [ ] Document detailing format of test cases, input and expected output

## Pseudo-code
```
steps = 0
BALANCE(w1, w2)
    if w1 == w2
        return 1
    return 0

WEIGHT-OF-GENUINE-COIN(n, coins)
    aux = []
    if n is even:
        counter = 0
        while counter < n:
            if BALANCE(coins[counter], coins[counter + 1])
                aux.append()
            steps = steps + 1
            counter = counter + 2
        if aux.len == 1:
            return aux[0]
        else if aux.len == 0:
            return the last element of coins
        else 
            return WEIGHT-OF-GENUINE-COIN(aux.len, aux)

    else:
        remove the last element of coins
        n = n - 1
        counter = 0
        while counter < n - 1:
            if BALANCE(coins[counter], coins[counter + 1])
                aux.append()
            steps = steps + 1
            counter = counter + 2
        if aux.len == 1:
            return aux[0]
        else if aux.len == 0:
            return the last element of the aux
        else:
            return WEIGHT-OF-GENUINE-COIN(aux.len, aux)

In the main:
    input n - the number of coins
    input coins - an array of 0s and 1s
    print "Weight of the genuine coin : " + WEIGHT-OF-GENUINE-COIN(n coins)
    print "Number of steps required : " + steps
```

## Proof of the algorithm  
### Proof Of Correctness 
Proving by induction
#### Base Cases:
a. number of coins = 1
    Pop the element since it is odd.
    Array formed is empty.
    Therefore, the answer is the only coin present.
b. number of coins = 2
    Compare the elements.
    (No case possible where they are equal)
    New array consists of 1 coin.
    Hence proved by case a.
#### Induction Hypothesis:
Works correctly for *k* coins.
####Inductive Step:
For *k + 1* coins, we have:
a. *k* is even, i.e. *k + 1* is odd
Pop the last element and store it.
We have *k* elements left.
There can be 2 cases:
Case 1: There are *> k/2* gold coins.
This is lower bounded by *k/2 + 1* which is - 
    *k/2 + 1 > k/2 + 1/2 = (k + 1)/2*
Therefore, there is a majority element in the complete array.
As we know our algoritm can find the majority element in a k-array(inductive hypothesis), this can be solved.

Case 2: There are exactly *k/2* gold coins
Irrespective of the arrangement of the coins in the array, in every subsequent step, our new array will be an even length array.
As for every operation carried out over one type of coin, an anlogous operation will occur with the other type of coin, since they are equal in number.
Therefore, we end up with an even array of equal number of gold and fakr coins due to symmetry.
This will finally lead to the case where we get an empty array and here we return the stored value of the last element of the original array as the genuine gold coin.
*last element + k/2 = k/2 + 1 > (k+1)/2*

b. *k* 



## Instructions To Compile And Run
- Compile the source code GoldCoins.cpp using g++
```
g++ GoldCoins.cpp
```
- a.out file will be generated
- Run the generated a.out file as follows : 
```
./a.out
```
### Input
- The first line contains the integer *n* - the number of gold coins.
- The next line contains *n* space-separated 0s or 1s denoting the two different weights of the genuine and fake coins.
- Make sure the genuine coins are more than half of the total coins.

### Output
- The first contains gives the weight of the genuine coin.
- The second line contains the number of weighings required to arrive at the genuine coin.

### Examples
#### input
```
5
1 0 0 1 0
```
#### output
```
Weight: 0
weighings: 2
```

#### input
```
9
1 0 0 1 0 0 1 0 1
```
#### output
```
Weight: 0
weighings: 4
```


## Contributors
- [Advait Lonkar](https://github.com/advait-l) 
- [Amogh Johri](https://github.com/AmoghJohri) 

