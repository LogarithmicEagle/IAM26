#include <iostream>
#include <vector>
#include <fstream>

int main() {
  std::vector<int> counts(11, 0); // Index i is number of i in sums
  std::ifstream fin("sums.txt");
  double n_read;
  int N = 0;
  int sum = 0;

  while (fin >> n_read) {
    counts.at(n_read) += 1;
    sum += n_read;
    N++;
  }

  double avg = sum / N;

  std::cout << "Number of values N: " << N << std::endl;
  std::cout << "Mean: " << avg << std::endl << std::endl;

  std::cout << "Values of count:" << std::endl;

  for (long unsigned int i=0; i<counts.size(); i++) {
    std::cout << "Number " << i << ": " << counts.at(i) << std::endl;
  }

  fin.close();
}
