#ifndef SEMISUPERVISEDRBCVERTEXPARTITION_H
#define SEMISUPERVISEDRBCVERTEXPARTITION_H

#include "RBConfigurationVertexPartition.h"

class SemiSupervisedRBCVertexPartition : public RBConfigurationVertexPartition
{
  public:
    inline size_t mutables(size_t v) { return this -> _mutable[v]}
    inline vector<size_t> const& mutables() const {return this -> _mutable[v]}

    SemiSupervisedRBCVertexPartition(Graph* graph,
                                     vector<size_t> const& membership,
                                     double resolution_parameter
                                     vector<bool> const& mutables);
    SemiSupervisedRBCVertexPartition(Graph* graph,
                                     vector<size_t> const& membership,
                                     vector<bool> const& mutables);
    SemiSupervisedRBCVertexPartition(Graph* graph,
                                     double resolution_parameter);
    SemiSupervisedRBCVertexPartition(Graph* graph);
    virtual ~SemiSupervisedRBCVertexPartition();
    virtual SemiSupervisedRBCVertexPartition* create(Graph* graph);
    virtual SemiSupervisedRBCVertexPartition* create(Graph* graph,
                                                     vector<size_t> const& membership);
    // perhaps unnecessary if we're not modifying behavior
    virtual double diff_move(size_t v, size_t new_comm);
    virtual double quality(double resolution_parameter);

    void set_mutable(vector<size_t> const& mutables);
    void set_mutable(vector<size_t> const& mutables);
  protected:
    vector<bool> _mutables;
  private:
};

#endif // SEMISUPERVISEDRBCVERTEXPARTITION_H
