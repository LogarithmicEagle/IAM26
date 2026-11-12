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

double satmodel(const std::vector<int>& data, double mu) {
  double res1 = 0;
  double res2 = 0;

  for (int k : data) {
    res1 += log(poisson(mu, k));

    if (k != 0) {
      res2 += log(poisson(k, k));
    }
  }

  return -2 * (res1 - res2);
}

int main() {
  std::ifstream fin("sums.txt");
  std::ofstream fout("likelihood.txt");
  std::ofstream fout2("nll.txt");
  std::ofstream fout3("deltanll.txt");
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

  for (double mu = 0.; mu < 6.; mu += 0.01) {
    fout2 << mu << " " << nll(data, mu) << std::endl;
  }

  for (double mu = 0.; mu < 6.; mu += 0.01) {
    fout3 << mu << " " << nll(data, mu) + 2 * log(L) << std::endl;
  }

  double min_mu;
  double min_nll = nll(data, 2.5);
  double max_l;

  for (double mu = 2.5; mu < 4.0; mu += 0.00001) {
    double nll_val = nll(data, mu);

    if (nll_val > min_nll) {
      min_mu = mu - 0.00001;
      max_l = prob(data, min_mu);
      break;
    }

    min_nll = nll_val;
  }

  std::cout << "Minimized mu: " << min_mu << std::endl;
  std::cout << "Maximized Liklihood: " << max_l << std::endl;

  double satmod = satmodel(data, min_mu);
  
  std::cout << "-2ln lambda: " << satmod << std::endl;
  std::cout << "z: " << (satmod - 233) / sqrt(2 * 233) << std::endl;

  fin.close();
  fout.close();
  fout2.close();
  fout3.close();
}
