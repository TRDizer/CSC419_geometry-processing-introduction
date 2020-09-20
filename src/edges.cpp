#include "edges.h"
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility>

Eigen::MatrixXi edges(const Eigen::MatrixXi &F)
{
  Eigen::MatrixXi E;
  // ADD YOUR CODE HERE

  // A map to store the potential undirected variance of the already explored edges
  std::unordered_map<int, std::unordered_set<int>> explored_vertices;
  std::vector<int> temp_mat;
  int row_i, col_i;

  for (row_i = 0; row_i < F.rows(); row_i++) {
    for (col_i = 0; col_i < F.cols(); col_i++) {
      int start_v_index = F(row_i, col_i);
      int end_v_index = F(row_i, (col_i + 1) % F.cols());

      std::unordered_map<int, std::unordered_set<int>>::iterator result = explored_vertices.find(start_v_index);
      if (result != explored_vertices.end()) {
        if ((result->second).count(end_v_index) != 0) {
          // Detected an undirected edge; hence do nothing
          continue;
        }
      }
      // Otherwise update explored_vertices accordingly 
      result = explored_vertices.find(end_v_index);
      if (result != explored_vertices.end()) {
        (result->second).insert(start_v_index);
      }
      else {
        explored_vertices.insert(std::make_pair(end_v_index, std::unordered_set<int>::unordered_set({start_v_index})));
      }

      temp_mat.push_back(start_v_index);
      temp_mat.push_back(end_v_index);
    }
  }

  // Resize and populate E
  E.resize(temp_mat.size() / 2, 2);
  for(row_i = 0; row_i < E.rows(); row_i++) {
    E.row(row_i) << temp_mat[row_i * 2] , temp_mat[row_i * 2 + 1];
  }

  return E;
}
