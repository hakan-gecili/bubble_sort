#include <iostream>
#include <vector>
using namespace std;

class Sorter{
    std::vector<int> A;

public:
    Sorter(std::vector<int> A_){
        A.assign(A_.begin(), A_.end());
    }

    void insertion_sort (std::vector<int> &A){
        int key = 0;
        int i = 0;
        for (int j = 2; j < A.size(); j++){
        key = A[j];
        i = j -1;
        while (i >= 0 & A[i] > key){
            A[i+1] = A[i];
            i = i - 1;
        }
        A[i + 1] = key;
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
    Sorter insertion_sorter(A);
    std::cout<< "Initial Vector: ";
    insertion_sorter.print_vector(A);
    insertion_sorter.insertion_sort(A);
    std::cout<< "After Sort    : ";
    insertion_sorter.print_vector(A);
    return(0);
}
