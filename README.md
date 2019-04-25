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
            return the last coin of coins
        else 
            return WEIGHT-OF-GENUINE-COIN(aux.len, aux)

    else:
        remove the last coin of coins
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
            return the last coin of the aux
        else:
            return WEIGHT-OF-GENUINE-COIN(aux.len, aux)

In the main:
    input n - the number of coins
    input coins - an array of 0s and 1s
    print "Weight of the genuine coin : " + WEIGHT-OF-GENUINE-COIN(n coins)
    print "Number of steps required : " + steps
```

## Proof Of The Algorithm  
### Proof Of Correctness 
Proving by induction
#### Base Cases:
1. number of coins = 1

    - Pop the coin since it is odd.

    - Array formed is empty.

    - Therefore, the answer is the only coin present.

2. number of coins = 2

    - Compare the elements.
    (No case possible where they are equal)
    
    - New array consists of 1 coin.

    - Hence proved by case a.

#### Induction Hypothesis:
Works correctly for *k* coins.

#### Inductive Step:
For *k + 1* coins, we have:
1. *k* is even, i.e. *k + 1* is odd

    - Pop the last coin and store it.

    - We have *k* elements left.

    - There can be 2 cases:

        - **Case 1**: There are *> k/2* gold coins.

            - This is lower bounded by *k/2 + 1* which is 
                *k/2 + 1 > k/2 + 1/2 = (k + 1)/2*

            - Therefore, there is a majority coin in the complete array.

            - As we know our algoritm can find the majority coin in a k-array(inductive hypothesis), this can be solved.

        - **Case 2**: There are exactly *k/2* gold coins

            - Irrespective of the arrangement of the coins in the array, in every subsequent step, our new array will be an even length array.

            - As for every operation carried out over one type of coin, an anlogous operation will occur with the other type of coin, since they are equal in number.

            - Therefore, we end up with an even array of equal number of gold and fakr coins due to symmetry.

            - This will finally lead to the case where we get an empty array and here we return the stored value of the last coin of the original array as the genuine gold coin.
            *last coin + k/2 = k/2 + 1 > (k+1)/2*

2. *k* is odd, i.e. *k + 1* is even.

    - Consider the first *k* elements.

    - Since *k* is odd, we get *g* genuine coins and *f* fake coins.

    - *g < f* is not possible since if *g < f*, then *f* is at least *g + 1*, so that  if the *(k + 1)th* coin is genuine, then there'll be equal number of genuine and fake coins which is a contradiction.

    - Also, *g = f* is also not possible, since *k* is odd.

    - Therefore, *g > f*, *g* is lower bounded by *(f + 1)*.

    - For *g > (f + 1)*, the majority coin in the k-array is the majority coin in the entire array. 

    - And for *g = (f + 1)*, *g* is the majority in  the k-array. Now, if the last coin is a genuine coin, *g* is still the majority. The last coin cannot be fake since then *g* will be equal to *f* which is a contradiction. 

Therefore, the majority in the k-array is the majority in the (k + 1)-array.

Hence proved.

### Proof of Running Time
#### Base Cases:
1. number of coins = 1
    - Pop the last coin.

    - Array formed is empty. So the genuine coin is the only coin.

    - Comparisons required = 0 <= *n - B(n)* = 1 - 1 = 0

2. number of coins = 2
    - Compare the coins. (No case possible where they are equal)

    - Array formed contains 1 coin, which is proved by the above case.

    - Comparisons required = 1 <= *n - B(n)* = 2 - 1 = 1

#### Induction Hypothesis:
Works for *k* coins in <= *k - B(k)* comparisons.

#### Inductive Step:
For *(k + 1)* coins we have, 

1. If *k* is odd, i.e. *(k + 1)* is even.
    - Now, (k - B(k)) < ((k + 1) - B(k + 1))

    - (x1x2x3...xi1) : Binary representation of k, as k is odd; where xi is 0 or 1.

    - (y1y2y3...yi0) : Binary representation of (k + 1), as k is odd; where yi is 0 or 1.

    - Now, k - B(k) <= (k + 1) - B(k + 1)

        -1 <= B(k) - B(k + 1)

        B(k + 1) - B(k) <= 1

    - **Proof by induction**
    

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

