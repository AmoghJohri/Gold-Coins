- The first 2 lines of the file consist of (valid) inputs.

- The first line of the input specifies the total number of the coins.

- The second line of the input is an array of the coins (represented as their weights).

- At the end of the file there is a report showing :
  1. The total number of coins
  2. Weight of the genuine coin (expected output)
  3. Number of weighings carried out by the algorithm in order to get to the output
  4. Number of weighings permitted (i.e. (n - B(n)) for n coins)
  5. Number of 1s (or number of coins with one kind of weight)
  6. Number of 0s (number of coins with the other kind of weight)

- This is carried out by the "PerformanceAnalyser.cpp" file. The input for this file is:
'''
 Total Number of Coins (Integer)
'''

- It then gives a random distribution of 1s and 0s for a total of n coins. Uses the algorithm proposed in order to figure out the weight of the genuine coin.

- Linear searches and counts the number of 1s and 0s seperately.

- Calculates (n - B(n)) or the permitted amount of weighings.

- Gives all of this information as an output file named "Report.txt"

