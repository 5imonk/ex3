#pragma once
#include <Util.hpp>
#include <vector>

std::vector<double> read_vector(std::string file_name) {
  std::vector<double> v;

  std::ifstream is (getcwd_str() + "/" + file_name);

  if (is.is_open()) {
    double temp_double;
    while (is >> temp_double) {
        v.push_back(temp_double);
    }
  }
  else {
    std::cout << "Unable to open file";
  }
  return v;
}

void print_vector(std::vector<double> v) {
  std::cout << "vector print: " << '\n';
  for (double const& e: v) {
    std::cout << e << '\n';
  }
}

void write_vector(std::vector<double> vec, std::string file_name) {
  std::ofstream outp_file;
  outp_file.open (getcwd_str() + "/" + file_name + ".txt");
  outp_file << std::scientific << std::setprecision(18);

  bool first = true;
  for (auto const& e: vec) {
    if (first) {
      first = false;
    }
    else {
      outp_file << '\n';
    }
    outp_file << e;
  }
  outp_file.close();
}

std::vector<double> MatrixMultiplication(std::vector<std::vector<double>> A, std::vector<double> v) {
  std::vector<double> result;

  for (auto const& A_row: A) {
    double temp_d{0};
    for (unsigned j=0; j<v.size(); j++) {
      temp_d += A_row.at(j) * v.at(j);
    }
    result.push_back(temp_d);
  }
  return result;
}
