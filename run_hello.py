import m5
from m5.objects import *
import argparse

root = Root(full_system = False)

parser = argparse.ArgumentParser(description='Setting params fro schedule time and vectors')

parser.add_argument("--tsub", default=15000, help="Flag for setting value of schedule time for subtraction.")
parser.add_argument("--tnor", default=1500, help="Flag for setting value of schedule time for normalize.")
parser.add_argument("--tcross", default=150, help="Flag for setting value of schedule time for cross.")

parser.add_argument("--v1_0", default=1, help="Flag for setting value of v1_0.")
parser.add_argument("--v1_1", default=2, help="Flag for setting value of v1_1.")
parser.add_argument("--v1_2", default=3, help="Flag for setting value of v1_2.")

parser.add_argument("--v2_0", default=3, help="Flag for setting value of v2_0.")
parser.add_argument("--v2_1", default=4, help="Flag for setting value of v2_1.")
parser.add_argument("--v2_2", default=5, help="Flag for setting value of v2_2.")


args = parser.parse_args()

root.sabby = VectorOperations()

root.sabby.sch_sub = args.tsub
root.sabby.sch_norm = args.tnor
root.sabby.sch_cross = args.tcross
root.sabby.v1_0 = args.v1_0
root.sabby.v1_1 = args.v1_1
root.sabby.v1_2 = args.v1_2
root.sabby.v2_0 = args.v2_0
root.sabby.v2_1 = args.v2_1
root.sabby.v2_2 = args.v2_2

print("Beginning simulation!")

m5.instantiate()

exit_event = m5.simulate()
print('Exiting @ tick {} because {}'
      .format(m5.curTick(), exit_event.getCause()))