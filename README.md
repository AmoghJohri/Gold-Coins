# Gold-Coins

## Table Of Contents
- [Problem Statement](#problem-statement)
- [Pseudo-Code](#pseudo-code)
- [Proof Of The Algorithm](#proof-of-the-algorithm)
    - [Proof Of Correctness](#proof-of-correctness)
    - [Proof Of Running Time](#proof-of-running-time)
- [Instructions To Compile And Run](#instructions-to-compile-and-run)
- [Contributors](#contributors)

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

## Pseudo-Code
The following is the pseudo-code for the algorithm to solve the above problem: 

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
        store and remove the last coin of coins
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

    - New array formed is empty.

    - Therefore, the answer is the only coin present.

2. number of coins = 2

    - Compare the elements.
    (No case possible where they are equal)
    
    - New array consists of 1 coin.
    
    - Follow the step similar to that in Base Case 1.

#### Induction Hypothesis:
Works correctly for *k* coins.

#### Inductive Step:
For *k + 1* coins, we have:
1. *k* is even, i.e. *k + 1* is odd

    - Pop the last coin and store it.

    - We have *k* elements left.

    - There can be 2 cases:

        - **Case 1**: There are *> k/2* gold coins.

            - This number of gold coins is lower bounded by *k/2 + 1* which is 
                *k/2 + 1 > k/2 + 1/2 = (k + 1)/2*

            - Therefore, the majority coin in the obtained even array is also the majority coin in the complete array.

            - As we know our algoritm can find the majority coin in a k-array(inductive hypothesis), this can be solved.

        - **Case 2**: There are exactly *k/2* gold coins

            - Irrespective of the arrangement of the coins in the array, in every subsequent step, our new array will be an even length array (due to symmetry, for every coin we include in the new array of weight w1, there will also be a coin of weight w2 (considering the two types of weight of the coins in the array to be w1 and w2).

            - As for every operation carried out over one type of coin, an anlogous operation will occur with the other type of coin, since they are equal in number.

            - Therefore, we end up with an even array of equal number of gold and fake coins due to symmetry.

            - This will finally lead to the case where we get an empty array (as our array will keep getting smaller till the smallest possible case i.e. array of length 2 and due to symmetry it will contain 1 gold coin and 1 fake coin, in the following step, the array formed will be empty) and here we return the stored value of the last coin of the original array as the genuine gold coin.
            *[last coin] + k/2 = k/2 + 1 > (k+1)/2*

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

*Proving that the execution of the algorithm utilises a maximum of n-B(n) number of balance operations*

#### Base Cases:
1. number of coins = 1
    - Pop the last coin.

    - Array formed is empty. So the genuine coin is the only coin.

    - Comparisons required = 0 <= *n - B(n)* = 1 - 1 = 0

2. number of coins = 2
    - Compare the coins. (No case possible where they are equal)

    - New array formed contains 1 coin, which can be dealt by the above case.

    - Comparisons required = 1 <= *n - B(n)* = 2 - 1 = 1

#### Induction Hypothesis:
Works for *k* coins in <= *k - B(k)* comparisons.

#### Inductive Step:
For *(k + 1)* coins we have, 

1. If *k* is odd, i.e. *(k + 1)* is even.
    - Now, (k - B(k)) < ((k + 1) - B(k + 1))

    - (x(1)x(2)x(3)...x(i)1) : Binary representation of k, as k is odd; where x(i) is 0 or 1. The last bit here is 1.

    - (y(1)y(2)y(3)...y(i)0) : Binary representation of (k + 1), as k is odd; where y(i) is 0 or 1. The last bit here is 0.

    - k - B(k) <= (k + 1) - B(k + 1)

    - 1 <= B(k) - B(k + 1)

    B(k + 1) - B(k) <= 1

    **Proof by induction** : 

    - Base case:

        Binary representation of length 1 which is odd i.e. n = 1; B(n) = 1.

        n + 1 = 10; B(n + 1) = 1

        B(n + 1) - B(n) = 1 - 1 = 0 <= 1
        Hence proved

    - Induction Hypothesis: 

        Works with binary representation of length k which is odd.

    - Inductive Step:

        In the binary representation of length (k + 1), we have two cases:

        1. The leftmost bit does not change:
            
            Proof by induction hypothesis.

        2. 1. The leftmost bit changes from 0 to 1:

                - This number will be of the form: (2<sup>(k+1)</sup> + x(k)2<sup>(k)</sup> + x(k-1)2<sup>(k-1)</sup> + . . . + 0)

                    i.e. (2<sup>(k+1)</sup> + x(k)2<sup>(k)</sup> + . . . + 0) - (y(k)2<sup>(k)</sup> + . . . + 1) = 1

                    i.e. (2<sup>(k+1)</sup> - 1) - Sum(2<sup>(i)</sup>x(i)) = 1

                    i.e. 2<sup>(k)</sup> - 1 = Sum(2<sup>(i)</sup>x(i))

                    But 2<sup>(k)</sup> - 1 = Sum(2<sup>(i-1)</sup>).1

                    Therefore, x(i) = 1

                - Binary representation of B(n) = k-ones (0111...111)

                - Binary representation of B(n + 1) = 1 one and k-zeroes (1000...0)

                - Clearly, (1 - k) <= 1 since k >= 0  
            
            2. The leftmost bit changes from 1 to 0:

                - n + 1 : (0(2<sup>(k+1)</sup>) + Sum(x(i)2<sup>(i)</sup>))
                    
                    n : (2<sup>(k+1)</sup>) + Sum(y(i)2<sup>(i)</sup>)

                    n - (n + 1) > 0 which is not possible hence a contradiction.
        
    - Therefore, B(n) - B(n + 1) <= 1 for n being odd.
    
    - B(n) is solved in <= n - B(n) steps by inductive hypothesis.

    - B(n + 1) is solved in <= n - B(n) <= (n + 1) - B(n + 1) steps.

    Hence proved.

2.  If k is even, i.e. (k + 1) is odd.
    
    k - B(k) = (k + 1) - B(k + 1)

    - Now, from the proof of correctness, we pop the last element and work with the k-length array where k is even.

    - This forms two cases:
        - Case 1:

            - We find a majority element in the k-array then, number of that majority element is lower bounded by (k/2 + 1).

            - It forms the majority for (k + 1) elements as well irrespective of the type of (k + 1)th element.

            - Since the majority element of k-array can be found in k - B(k) comparisons by inductive hypothesis, the (k + 1)-array can be solved in (k + 1) - B(k + 1) comparisons.

        - Case 2:

            - No majority element exists in the first k-elements i.e. it has (k/2) gold coins and (k/2) fake coins.

            - By symmetry, for every gold coin added to the aux array, we have a fake coin that can be added to the aux array.

            - Now the number of comparisons are greater for a greater number of coins.

            - For a single type of coin, the highest number coins which can be added to the aux array is bounded by (n/2) : if n coins of one type are present.

            - Therefore, for (k/2) gold coins and (k/2) fake coins, the maximum length aux array consists of (k/4) gold coins and (k/4) fake coins. For a k-array, k being even, number of comparisons are (k/2).

            - Now, total number of comparisons till we obtain an array of 0 length is upper bounded by (assuming the case where the first k/2 elements are of the same type and the next k/2 of the same type, in case this is not true, the same number of comparisions produce a smaller array) = 
                (k/2 + k/4 + . . . + 1)

                = (1 + 2  + 4 + . . . + k/2)

                = 1(1 - 2<sup>(log(k/2))</sup>)/(1 - 2)

                = (2<sup>(log(k/2))</sup> - 1)<sup>2</sup>

                = 2<sup>(log(k) / log(2))</sup> - 1

                = 2<sup>(log(k))</sup> - 1

                = (k - 1) comparisons  

            - Now, the upper bound is achieved for k being divisible by 2, 4, 8, . . ., (k/2)

                So, k is some power of 2.

                So the number of comparisons is maximum for k being a power of 2.

                Therefore, B(k) = 1

                Comparisons required = (k - 1) = k - B(k)

                = (k + 1) - B(k + 1) 
              
              (For the case where k is not a power of 2, from the inductive hypothesis and the proof for k+1 being even, we have that it will converge to an empty array in k - B(k) steps. Hence, as k - B(k) = (k + 1) - B(k + 1) we can state that, the k elements converge to an empty array in (k + 1) - B(k + 1) steps and then, as per the algorithm, we return the element stored as the token. Hence, the algorithm runs in a maximum of (k + 1) - B(k + 1) steps for an array of k + 1 elements).

            Hence proved.            
                 
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
Weight of the genuine coin: 0
Number of weighings required: 2
```

#### input
```
9
1 0 0 1 0 0 1 0 1
```
#### output
```
Weight of the genuine coin: 0
Number of weighings required: 4
```


## Contributors
- [Advait Lonkar](https://github.com/advait-l)
    - GoldCoins.cpp
    - Proof Of Running Time
    - Instructions To Compile and Run
    - README.md
- [Amogh Johri](https://github.com/AmoghJohri) 
    - PerformanceAnalyser.cpp
    - Pseudo-code
    - Proof Of Correctness
    - Test Cases

