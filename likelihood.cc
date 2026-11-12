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

double nll(const std::vector<int>& data, double mu) {
  double res = 0.;

  for (int k : data) {
    res += log(poisson(mu, k));
  }

  return -2 * res;
}

int main() {
  std::ifstream fin("sums.txt");
  std::ofstream fout("likelihood.txt");
  std::ofstream fout2("nll.txt");
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

  for (double mu = 0.01; mu < 6.; mu += 0.01) {
    fout2 << mu << " " << nll(data, mu) << std::endl;
  }

  fin.close();
  fout.close();
  fout2.close();
}
