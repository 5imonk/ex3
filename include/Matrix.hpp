#pragma once
#include <Util.hpp>
#include <vector>
#include <iostream>
#include <fstream>

#include <iomanip>
#include <iterator>
#include <iostream>
#include <string>
#include <sstream>

std::vector<std::vector<double>> read_matrix(std::string file_name) {
  std::vector<std::vector<double>> matrix;

  std::string line;
  std::ifstream is (getcwd_str() + "/" + file_name);

  if (is.is_open()) {
    //double temp_double;
    // char delimiter;
    while (std::getline(is, line)) {
      std::istringstream iss(line);
      // std::vector<std::string> vec_str = std::vector<std::string> (std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>());
      std::vector<double> temp_v;
      std::string s;
      while (std::getline(iss, s, ' ')) {
        temp_v.push_back(std::stod(s));
      }
      matrix.push_back(temp_v);
    }
  }
  else {
    std::cout << "Unable to open file";
  }
  return matrix;
}

void write_matrix(std::vector<std::vector<double>> matrix, std::string file_name) {
  std::ofstream outp_file;
  outp_file.open (getcwd_str() + "/" + file_name + ".txt");
  outp_file << std::scientific << std::setprecision(18);

  bool first_outerloop = true;
  bool first_innerloop;
  for (auto const& v: matrix) {
    if (first_outerloop) {
      first_outerloop = false;
    }
    else {
      outp_file << '\n';
    }
    first_innerloop = true;
    for (auto const& e: v) {
      if (first_innerloop) {
        first_innerloop = false;
      }
      else {
        outp_file << ' ';
      }
      outp_file << e;
    }
  }
  outp_file.close();
}

std::vector<std::vector<double>> MatrixTransposition(std::vector<std::vector<double>> A) {
  std::vector<std::vector<double>> A_T(A);
  int i{0}, j{0};

  for (auto const& row: A) {
    for (double const& e: row) {
      A_T.at(j++).at(i) = e;
    }
    i++;
    j=0;
  }
  // std::cout << A_T << '\n';
  return A_T;
}

std::vector<std::vector<double>> MatrixMultiplication(std::vector<std::vector<double>> A, std::vector<std::vector<double>> B) {
  std::vector<std::vector<double>> result;

  std::vector<std::vector<double>> B_T = MatrixTransposition(B);

  for (unsigned i=0; i<A.size(); i++) {
    std::vector<double> A_row{A.at(i)};
    std::vector<double> temp_v;

    for (unsigned j=0; j<A_row.size(); j++) {
      std::vector<double> B_column{B_T.at(j)}; // transposed matrix, so row is column
      double temp_d{0};
      for (unsigned k=0; k<A_row.size(); k++) {
        temp_d += A_row.at(k) * B_column.at(k);
      }
      temp_v.push_back(temp_d);
    }
    result.push_back(temp_v);
  }
  return result;
}

void print_matrix(std::vector<std::vector<double>> matrix_A) {
  std::cout << "matrix print: " << '\n';
  std::cout << std::scientific << std::setprecision(10);
  for (auto const& row: matrix_A) {
    for (double const& e: row) {
      std::cout << e << ' ';
    }
    std::cout << '\n';
  }
}
