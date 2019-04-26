-> The first 2 lines of the file consist of (valid) inputs.
-> The first line of the input specifies the total number of the coins.
-> The second line of the input is an array of the coins (represented as their weights).
-> At the end of the file there is a report showing :
  a) The total number of coins
  b) Weight of the genuine coin (expected output)
  c) Number of weighings carried out by the algorithm in order to get to the output
  d) Number of weighings permitted (i.e. (n - B(n)) for n coins)
  e) Number of 1s (or number of coins with one kind of weight)
  f) Number of 0s (number of coins with the other kind of weight)
 
This has been carried out by the "PerformanceAnalyser.cpp" file. The input for this file is:
-> Total Number of Coins (Integer)
It then gives a random distribution of 1s and 0s for a total of n coins. Uses the algorithm proposed in order to figure out the weight of the genuine coin.
Linear searches and counts the number of 1s and 0s seperately.
Calculates (n - B(n)) or the permitted amount of weighings.
Gives all of this information as an output file named "Report.txt"
