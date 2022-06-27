import random as rand

def exchange(a, b):
    temp = a
    a = b
    b = temp
    return [a, b]

def partition(A, p, r):
    x = A[r]
    i = p - 1
    for j in range(p, r):
        if A[j] <= x:
            i += 1
            [A[i], A[j]] = exchange(A[i], A[j])
    [A[i+1], A[r]] = exchange(A[i+1], A[r])
    return i+1

def quickSort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quickSort(A, p, q-1)
        quickSort(A, q+1, r)

if __name__ == '__main__':
    A = [rand.randint(0,1000) for i in range(100)]
    quickSort(A, 0, len(A)-1)
    print(A)
    if A == sorted(A):
        print("Correct sorting")
    else:
        print("Sorting Failed!")
