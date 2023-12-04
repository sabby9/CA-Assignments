#include "a2/vector_operations.hh"
#include "base/trace.hh"
#include <vector>
#include <cmath>
#include "debug/NORMALIZE.hh"
#include "debug/RESULTSUB.hh"
#include "debug/VECTOR.hh"
#include "debug/RESULTCROSS.hh"


namespace gem5
{
    //(std::vector<float> v1v, std::vector<float> v2v)
// VectorOperations::VectorOperations(const VectorOperationsParams &params, std::vector<float> v1v, std::vector<float> v2v) :
//     SimObject(params), 
//     sub([this]{VectorSubtraction();}, name()) , 
//     cross([this]{VectorCrossProduct();}, name()), 
//     normalize([this]{NormalizeVector();}, name())
// {
//     // the function wrappers are private members of the class, we are initializing
//     // std::cout << "We are inside constructor";
//     // v1 = {{v10}, {v11}, {v12}};

//     v1 = {{v1v[0]}, {v1v[1]}, {v1v[2]}};
//     v2 = {{v2v[0]}, {v2v[1]}, {v2v[2]}};

//     DPRINTF(VECTOR, "\n Vector 1 is: %lf %lf %lf", v1[0][0], v1[1][0], v1[2][0]);
//     DPRINTF(VECTOR, "\n Vector 2 is: %lf %lf %lf \n ", v1[0][0], v2[1][0], v2[2][0]);


// }

VectorOperations::VectorOperations(const VectorOperationsParams &params) :
    SimObject(params), 
    VectorSubtraction([this]{FnVectorSubtraction();}, name()) , 
    VectorCrossProduct([this]{FnVectorCrossProduct();}, name()), 
    NormalizeVector([this]{FnNormalizeVector();}, name()),
    tsub(params.sch_sub),
    tnor(params.sch_norm),
    tcross(params.sch_cross),
    v1_0(params.v1_0),
    v1_1(params.v1_1),
    v1_2(params.v1_2),
    v2_0(params.v2_0),
    v2_1(params.v2_1),
    v2_2(params.v2_2)
{
    // the function wrappers are private members of the class, we are initializing
    // std::cout << "We are inside constructor";
    // v1 = {{v10}, {v11}, {v12}};

    v1 = {{v1_0}, {v1_1}, {v1_2}};
    v2 = {{v2_0}, {v2_1}, {v2_2}};

    DPRINTF(VECTOR, "\n Vector 1 is: %f %f %f", v1[0][0], v1[1][0], v1[2][0]);
    DPRINTF(VECTOR, "\n Vector 2 is: %f %f %f \n ", v2[0][0], v2[1][0], v2[2][0]);


}

void
VectorOperations::startup()
{
    // startup is a special function executed at tick 0.
    // std::cout << "We are inside start-up function";

    // schedule the events
    schedule(VectorCrossProduct, tcross);
    schedule(NormalizeVector, tnor);
    schedule(VectorSubtraction, tsub);
 
}

void
VectorOperations::FnVectorCrossProduct()
{
    // Perform vector cross 

    std::vector<float> v1_transpose;
    std::vector<float> v2_transpose;

    v1_transpose = {v1[0][0], v1[1][0], v1[2][0]};
    v2_transpose = {v2[0][0], v2[1][0], v2[2][0]};
    
    // std::cout << "v1 v2 made";
    std::vector<float> cross;
   
    // // cross_P[0] = vect_A[1] * vect_B[2] - vect_A[2] * vect_B[1];
    float c0 = v1_transpose[1] * v2_transpose[2] - v1_transpose[2] * v2_transpose[1];
    // std::cout << " cross 0 made";

    //  // cross_P[1] = vect_A[2] * vect_B[0] - vect_A[0] * vect_B[2];
    float c1= v1_transpose[2] * v2_transpose[0] - v1_transpose[0] * v2_transpose[2];
    // std::cout << " cross 1 made";

    // // cross_P[2] = vect_A[0] * vect_B[1] - vect_A[1] * vect_B[0];
    float c2= v1_transpose[0] * v2_transpose[1] - v1_transpose[1] * v2_transpose[0];
    // std::cout << " cross 2 made";

    cross.push_back(c0);
    cross.push_back(c1);
    cross.push_back(c2);
 
    DPRINTF(RESULTCROSS, "\n Cross Product of the vectors is: %f %f %f  \n", cross[0], cross[1], cross[2]);

}

void
VectorOperations::FnNormalizeVector()
{
    std::vector<std::vector<float>> n1;
    std::vector<std::vector<float>> n2;

    float v1_norm = sqrt(v1[0][0] * v1[0][0] + v1[1][0] * v1[1][0] + v1[2][0] * v1[2][0]);
    float v2_norm = sqrt(v2[0][0] * v2[0][0] + v2[1][0] * v2[1][0] + v2[2][0] * v2[2][0]);

    n1 = {{v1[0][0]/v1_norm}, {v1[1][0]/v1_norm}, {{v1[2][0]/v1_norm}}};
    n2 = {{v2[0][0]/v2_norm}, {v2[1][0]/v2_norm}, {{v2[2][0]/v2_norm}}};

    DPRINTF(NORMALIZE, "\n Vector 1 after normalization: %f %f %f \n", n1[0][0], n1[1][0], n1[2][0]);
    DPRINTF(NORMALIZE, "\n Vector 2 after normalization: %f %f %f \n", n2[0][0], n2[1][0], n2[2][0]);

}

void
VectorOperations::FnVectorSubtraction()
{
    // Perform vector cross 
    std::vector<std::vector<float>> ans;
    // std::cout<<"Performing v1 - v2";
    ans = {{v1[0][0] - v2[0][0]}, {v1[1][0] - v2[1][0]}, {v1[1][0] - v2[1][0]} };
    DPRINTF(RESULTSUB, "\n Subtraction of the vector is: %f %f %f  \n", ans[0][0], ans[1][0], ans[2][0]);
}

// void
// VectorOperations::Setv1(std::vector<float> a)
// {
//   v1 = {{a[0]}, {a[1]}, {a[2]}};
  
// }

// void
// VectorOperations::Setv2(std::vector<float> a)
// {
//   v2 = {{a[0]}, {a[1]}, {a[2]}};
  
// }

} // namespace gem5
