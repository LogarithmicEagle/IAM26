#include <iostream>
#include <fstream>
#include <cmath>

int main() {
  // Read in file
  std::ifstream fin("sums.txt");

  double n_read; // Number from file
  int num_lines = 0; // Number of lines in file
  double sum = 0; // Sum of the numbers
  double var_sum = 0; // Square of difference of variance and sum

  // Read through file and sum numbers
  while (fin >> n_read) {
    sum += n_read;
    num_lines++;
  }

  // Calculate results
  double average = sum / num_lines;

  // Re-open file
  fin.close();
  std::ifstream fin2("sums.txt");

  while (fin2 >> n_read) {
    var_sum += (n_read - average) * (n_read - average);
  }

  // Calculate results
  double var = var_sum / num_lines;

  // Print results
  std::cout << "The sum of numbers is: " << sum << std::endl;
  std::cout << "The average of numbers is: " << average << std::endl;
  std::cout << "The variance is: " << var << std::endl;
  std::cout << "The standard deviation is: " << sqrt(var) << std::endl;

  // Close file
  fin2.close();
}
