#include "euler_characteristic.h"
#include "edges.h"

int euler_characteristic(const Eigen::MatrixXi &F)
{
  int Chi = 0;
  // ADD YOUR CODE HERE
  // Assumption: no unreferenced vertex
  Chi = F.maxCoeff() - edges(F).rows() + F.rows();
  return Chi;
}
