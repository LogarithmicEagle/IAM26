#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

double poisson(double mu, int k) {
  return pow(mu, k) * exp(-mu) / tgamma(k + 1);
}

int main() {
  std::vector<int> counts(11, 0); // Index i is number of i in sums
  std::ifstream fin("sums.txt");
  std::ofstream fout("hist.txt");
  std::ofstream fout2("histpoi.txt");
  
  double n_read;
  double N = 0;
  double sum = 0;

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
    std::cout << i << " " << counts.at(i) << " " << N * poisson(avg, i) << std::endl;
    fout << i << " " << counts.at(i) << std::endl;
    fout2 << i << " " << counts.at(i) << " " << N * poisson(avg, i) << std::endl;
  }

  fin.close();
}
