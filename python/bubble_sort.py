from typing import List
import random as rand

def bubble_sort (A:List[int]) -> List[int]:
    N = len(A)
    for i in range(1,N):
        for j in range((N-1), i, -1):
            if A[j] < A[i-1]:
                temp = A[j]
                A[j] = A[i-1]
                A[i-1] = temp

if __name__ == '__main__':
    A = rand.sample(range(1000), 100)
    bubble_sort(A)
    print(A)
