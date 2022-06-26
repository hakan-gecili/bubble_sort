from cmath import inf
from typing import List

def merge (A:List[int], p: int, q: int, r:int) -> List[int]:
    L = A[p : q]
    L.append(inf)
    R = A[q : r]
    R.append(inf)
    
    i = 0 
    j = 0
    for k in range(p,r):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def merge_sort(A:List[int], p:int, r:int) -> List[int]:
    if p < r-1:
        q = (r + p)  // 2 
        #print(f"""p: {p} , q: {q}, r: {r}""")
        merge_sort(A, p, q)
        merge_sort(A, q, r)
        merge(A,p,q,r)

if __name__ == '__main__':
    A = [3, 8, 1, 9, 4, 2, 7, 5, 0 , 0 , 5, 5]
    merge_sort(A, 0, len(A))
    print(A)
