#include <iostream>
#include <fstream>
#include <cmath>

int main() {
  // Read in file
  std::ifstream fin("sums.txt");
  std::ifstream fin2("sums.txt");
  std::ofstream fout("means.txt");
  std::ofstream fout2("variances.txt");

  double n_read; // Number from file
  //int num_lines = 0; // Number of lines in file
  double sum = 0; // Sum of the numbers
  double var_sum = 0; // Square of difference of variance and sum
  double average = 0;
  double var = 0;

  // Read through file and calculate means
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 9; j++) {
      fin >> n_read;
      sum += n_read;
    }

    average = sum / 9;
    fout << average << std::endl;

    for (int j = 0; j < 9; j++) {
      fin2 >> n_read;
      var_sum += (n_read - average) * (n_read - average);
    }

    var = var_sum / 9;
    fout2 << var << std::endl;

    sum = 0;
    var_sum = 0;
  }
  
  // Close file
  fin.close();
  fin2.close();
  fout.close();
  fout2.close();
}
