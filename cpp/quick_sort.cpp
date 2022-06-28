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
  
  int partition(int p, int r){
    int x = A[r];
    int i = p - 1;
    
    for (int j = p; j < r; j++){
      if (A[j] < x){
        i++;
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
      }
    }
    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return(i+1);
  }
  
  void quick_sort(int p, int r){
    if (p < r){
      int q = partition(p, r);
      quick_sort(p, q-1);
      quick_sort(q+1, r);
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


int main(int argc, const char * argv[]) {
  const int number_count = 100;
  const int min_num = 0;
  const int max_num = 1000;
  Sorter_ sorter(number_count, min_num, max_num);
  std::cout<< "Initial Vector: ";
  sorter.print_vector();
  sorter.quick_sort(0, number_count-1);
  std::cout<< "After Sort    : ";
  sorter.print_vector();
  return 0;
}
