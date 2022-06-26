from typing import List

def insertion_sort (A:List[int]) -> List[int]:
    for j in range(2, len(A)):
        key = A[j]
        i = j - 1
        while i >= 0 and A[i] > key:
            A[i+1] = A[i]
            i = i - 1
        A[i + 1] = key

if __name__ == '__main__':
    A = [3, 8, 1, 9, 4, 2, 7, 5, 0 , 0 , 5, 5]
    insertion_sort(A)
    print(A)
