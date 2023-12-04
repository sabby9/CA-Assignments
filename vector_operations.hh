#ifndef __A2_VECTOR_OPERATIONS_HH__
#define __A2_VECTOR_OPERATIONS_HH__

#include "params/VectorOperations.hh"
#include "sim/sim_object.hh"
#include <vector>

namespace gem5
{

class VectorOperations : public SimObject
{
  private:

    std::vector<std::vector<float>> v1;
    std::vector<std::vector<float>> v2;

    void FnVectorCrossProduct();
    void FnNormalizeVector();
    void FnVectorSubtraction();


    EventFunctionWrapper VectorCrossProduct;
    EventFunctionWrapper NormalizeVector;
    EventFunctionWrapper VectorSubtraction;

    int tsub;
    int tnor;
    int tcross;

    float v1_0;
    float v1_1;
    float v1_2;

    float v2_0;
    float v2_1;
    float v2_2;

  public:

    VectorOperations(const VectorOperationsParams &p);
    // VectorOperations(const VectorOperationsParams &p, std::vector<float> a, std::vector<float> b);
    virtual void startup() override; 
};



} // namespace gem5

#endif // __LEARNING_GEM5_HELLO_OBJECT_HH__
