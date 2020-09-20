#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  // Assumption: no unreferenced vertex and F_index_v starts from 0
  Chi = (F.maxCoeff()) + 1 - edges(F).rows() + F.rows();
  return Chi;
}
