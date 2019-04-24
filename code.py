#######################################

## Dummy code to verify the algorithm
## To give the input, just type out the weights with a single spacing

### Example : 1 1 0 0 1 1 0 0 1
    ## Ans = 1 and also gives the number of comparisions carried out in order to obtain the answer

#######################################
global steps
steps = 0

global token

def compare(w1, w2):
    if w1 == w2 :
        return  1
    return 0

def weight_of_genuine_coin(n, arr):
    global steps
    global token
    aux = []
    if n%2 == 0 :
        counter = 0
        while counter < n-1:
            if compare(arr[counter], arr[counter + 1]):
                aux.append(arr[counter])
            steps = steps + 1
            counter = counter + 2
        if len(aux) == 1:
            return aux[0]
        elif len(aux) == 0:
            return token
        else:
            return weight_of_genuine_coin(len(aux), aux)
    else:
        arr.pop()
        n = n - 1
        counter = 0
        while counter < n-1:
            if compare(arr[counter], arr[counter + 1]):
                aux.append(arr[counter])
            steps = steps + 1
            counter = counter + 2
        if len(aux) % 2 == 1:
            token = aux[-1]
        if len(aux) == 1:
            return aux[0]
        elif len(aux) == 0:
            return token
        else:
            return weight_of_genuine_coin(len(aux), aux)

arr = map(int, raw_input().split())
n = len(arr)
token = arr[-1]

print "Weight of the genuine coin is: ", weight_of_genuine_coin(n, arr)
print "Number of weighings by the algorithm is: ", steps








