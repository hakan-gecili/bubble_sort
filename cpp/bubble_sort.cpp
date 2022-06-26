#include <iostream>
#include <vector>
#include <random>

using namespace std;

class Sorter_{
    std::vector<int> A;
    int Size, Min, Max;
public:
    Sorter_(int Size_,int Min_, int Max_):Size(Size_), Min(Min_), Max(Max_){
        A.resize(Size);
        GenerateRandomIntegers();
    }

    void bubble_sort(){
        int N = A.size();
        int temp = 0;
        for (int i = 0; i < N; i++){
            for (int j = (N-1); j > i; j--){
                if (A[j] < A[i]){
                    temp = A[j];
                    A[j] = A[i];
                    A[i] = temp;
                }
            }
        }
    }
 
    void print_vector(){
            std::cout << "A = { ";
        for (int a : A) {
            std::cout << a << " ";
        }
        std::cout << "}; \n";
    }

    void GenerateRandomIntegers() {
        std::random_device rd; 
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(Min, Max);
        std::generate(A.begin(), A.end(), [&](){ return dist(gen); });
    }
};


int main(void){
    const int number_count = 100;
    const int min_num = 0;
    const int max_num = 1000; 
    Sorter_ sorter(number_count, min_num, max_num);
    std::cout<< "Initial Vector: ";
    sorter.print_vector();
    sorter.bubble_sort();
    std::cout<< "After Sort    : ";
    sorter.print_vector();
    return(0);
}
