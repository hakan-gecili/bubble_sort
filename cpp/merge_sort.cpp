#include <cmath>
#include <iostream>
#include <vector>
#include<climits>

using namespace std;

class Sorter{
    std::vector<int> A;
    int p;
    int r;
public:

    Sorter(std::vector<int> A_, int start, int end){
        A.assign(A_.begin(), A_.end());
        p = start;
        r = end;
    }

    void merge (std::vector<int> &A, int p, int q, int r){
        std::vector<int> L (A.begin()+p, A.begin()+q);
        L.push_back(INT_MAX);
        std::vector<int> R (A.begin()+q, A.begin()+r);
        R.push_back(INT_MAX);
        int i = 0;
        int j = 0;
        for (int k = p; k < r; k++){
            if (L[i] <= R[j]){
                A[k] = L[i] ;
                i++;
            } else{
                A[k] = R[j];
                j++;            
            }
        }  
    }

    void merge_sort (std::vector<int> &A, int p, int r){
        if (p < r-1) {
            int q = int(floor((r+p)/2));
            //std::cout << "p:" << p << ", q:"<< q << ", r:" << r << std::endl;
            merge_sort(A, p, q);
            merge_sort(A, q, r);
            merge(A,p,q,r);

        }
    }   

    void print_vector(const std::vector<int> A){
            std::cout << "A = { ";
        for (int a : A) {
            std::cout << a << " ";
        }
        std::cout << "}; \n";
    }
};

int main(void){
    std::vector<int> A {3, 8, 1, 9, 4, 2, 7, 5, 0 , 0 , 5, 5};
    int p = 0;
    int r = A.size();

    Sorter merge_sorter(A, p, r);
    std::cout<< "Initial Vector: ";
    merge_sorter.print_vector(A);
    merge_sorter.merge_sort(A, p, r);
    std::cout<< "After Sort    : ";
    merge_sorter.print_vector(A);
    return(0);
}
