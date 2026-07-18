def trav(arr, lb, ub):
    for k in range(lb, ub+1):
        print(arr[k])

    return ""

arr = [1, 2, 3, 4]
lb = 0
ub = len(arr)-1 

print(trav(arr, lb, ub))