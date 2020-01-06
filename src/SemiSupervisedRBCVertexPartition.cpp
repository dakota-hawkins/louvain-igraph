#include "SemiSupervisedRBCVertexPartition.h"

// TODO: If membership is passed, mark mutables and re-label -1 to incremented 
// label 

/**
 * @brief 
 * Create new semi-supervised partition
 * 
 * @param graph: The igraph.Graph on which this partition is defined.
 * @param membership:The membership vector of this partition, i.e. an
 *                   community number for each node. So membership[i] = c
 *                   implies that node i is in community c. If None, it is
 *                   initialised with each node in its own community.
 */
SemiSupervisedRBCVertexPartition::SemiSupervisedRBCVertexPartition(Graph* graph,
                                                                   vector<size_t> const& membership,
                                                                   double resolution_parameter,
                                                                   vector<bool> const& mutables) :
  RBConfigurationVertexPartition(graph, membership, resolution_parameter) {
    this -> set_mutability(membership);
  }

SemiSupervisedRBCVertexPartition::SemiSupervisedRBCVertexPartition(Graph* graph,
                                                                   vector<size_t> const& membership,
                                                                   vector<bool> const& mutables) :
  RBConfigurationVertexPartition(graph, membership) {
    this -> set_mutability(membership);
}

SemiSupervisedRBCVertexPartition::SemiSupervisedRBCVertexPartition(Graph* graph,
                                                                   double resolution_parameter) :
  RBConfigurationVertexPartition(graph, resolution_parameter) {
    this -> set_mutability();
  }

SemiSupervisedRBCVertexPartition::SemiSupervisedRBCVertexPartition(Graph* graph) : 
  RBConfigurationVertexPartition(graph) {
    this -> set_mutability();
  }

/**
 * @brief Set vertex mutability for each vertex in the graph
 * 
 * @param mutables: vector defining which nodes have mutable labels 
 */
SemiSupervisedRBCVertexPartition::set_mutable(vector<size_t> const& mutables) {
  for (size_t i = 0; i < this -> graph -> vcount(); i++) {
    this -> _mutables[i] = mutables[i];
  }
}

SemiSupervisedRBCVertexPartition::set_mutable() {
  for (size_t i = 0; i < this -> graph -> vcount(); i++) {
    this -> _mutables[i] = true;
  }
}