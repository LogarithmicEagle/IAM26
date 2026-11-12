#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

double poisson(double mu, int k) {
  return pow(mu, k) * exp(-mu) / tgamma(k + 1);
}

double prob(const std::vector<int>& data, double mu) {
  double L = 1.;

  for (int k : data) {
    L *= poisson(mu, k);
  }

  return L;
}

int main() {
  std::ifstream fin("sums.txt");
  std::ofstream fout("likelihood.txt");
  std::vector<int> data;
  int num;

  while (fin >> num) {
    data.push_back(num);
  }

  double sampleMu = 3.11538;
  double L = prob(data, sampleMu);

  std::cout << "L(mu) = " << L << std::endl;

  for (double mu = 0.; mu <= 6.; mu += 0.01) {
    fout << mu << " " << prob(data, mu) << std::endl;
  }

  fin.close();
  fout.close();
}
