#include <Matrix.hpp>
#include <Vector.hpp>

int main() {
  std::string outp_file;
  std::string file_name;

  file_name = "MatrixA.txt";
  std::vector<std::vector<double>> A {read_matrix(file_name)};

  file_name = "MatrixB.txt";
  std::vector<std::vector<double>> B {read_matrix(file_name)};

  file_name = "MatrixC.txt";
  std::vector<std::vector<double>> C {read_matrix(file_name)};

  file_name = "VectorV.txt";
  std::vector<double> v {read_vector(file_name)};

  std::vector<std::vector<double>> AC (MatrixMultiplication(A, C));
  outp_file = "AC";
  write_matrix(AC, outp_file);

  std::vector<std::vector<double>> AB (MatrixMultiplication(A, B));
  std::vector<double> ABv (MatrixMultiplication(AB, v));
  outp_file = "ABv";
  write_vector(ABv, outp_file);

  std::vector<std::vector<double>> C_t (MatrixTransposition(C));
  std::vector<std::vector<double>> C_tA (MatrixMultiplication(C_t, A));
  outp_file = "CtAv";
  write_matrix(C_tA, outp_file);

  std::vector<std::vector<double>> B_t (MatrixTransposition(B));
  std::vector<std::vector<double>> BtAB (MatrixMultiplication(B_t, AB));
  outp_file = "BtAB";
  write_matrix(BtAB, outp_file);

  return 0;
}
