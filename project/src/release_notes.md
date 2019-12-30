# Bus Simulator Release Notes

## Assumptions:

You will need to UNDEFINE/REDFINE CONSTPASS in the top of the Passenger Factory in order to test that the regression test is still true.

You will need to manually check that the output of the regression test is true by using diff.

The regression test driver and executable is named regression_test.  So to make the regression test you need to be in the src/ directory and run the command `make regression_test`

## Refactorings

#### Refactoring 1 (Pushed From Iteration 2 to Iteration 3)

I originally did this refactoring in Iteration 2.  I've since pushed those changes to a new branch named `refactor/iter2`.  I've also removed the Refactor 1 changes from the master branch.  I accomplished Refactoring 1 by popping 0 off the back of the generation probabilities in src/configuration_simulator.cc and then pushing back on a 0.

#### Refactoring 2

I chose to rename variables and method names.  The code with Refactoring 2 applied is on the branch named `refactor/iter3`.  All my changes for this refactoring were made in the src/bus.cc file.  The refactoring document is present in the `project/docs/` directory in a file named `refactor.pdf`.  This document is only on the `refactor/iter3` branch and is not present on the master branch.

