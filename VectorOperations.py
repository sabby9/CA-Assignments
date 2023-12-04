from m5.params import *
from m5.SimObject import SimObject
from m5.params import VectorParam

class VectorOperations(SimObject):
    type = 'VectorOperations'
    cxx_header = "a2/vector_operations.hh"
    cxx_class = "gem5::VectorOperations"
    sch_cross = Param.Int(150, "time for cross")
    sch_norm = Param.Int(1500, "time for norm")
    sch_sub = Param.Int(15000, "time for sub")
    v1_0 = Param.Float("v1_0")
    v1_1 = Param.Float("v1_1")
    v1_2 = Param.Float("v1_2") 
    v2_0 = Param.Float("v2_0")
    v2_1 = Param.Float("v2_1")
    v2_2 = Param.Float("v2_2") 