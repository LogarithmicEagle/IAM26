#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

int main() {
  // Open data file and output file
  std::ifstream fin("data.txt");
  std::ofstream fout("sums.txt");

  // Scan each line
  std::string line;
  while(std::getline(fin, line)) {
    // Scan two numbers
    int n1, n2;
    sscanf(line.c_str(), "%d\t%d", &n1, &n2);
    //std::cout << n1 << " + " << n2 << " = " << n1 + n2 << std::endl;

    // Print sum to new file
    fout << n1 + n2 << std::endl;
  }

  // Close files
  fin.close();
  fout.close();
}
