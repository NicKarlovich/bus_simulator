# Lab 15 - Assembling a regression test for config_sim and vis_sim

  The purpose of this lab is to have you assemble and run a regression test that can be used to test your final versions 
of __config_sim__ and __vis_sim__.  As noted in the iteration 3 requirements specification, the goal of regression tests is to 
verify that features in your simulation that were already working continue to work, even as you add the new functionality
(that is, code). 

  The regression test you will assemble and run in this lab can also be used as a basis for creating another regression 
test.  Even though the regression test requirement from iteration 2 specified the need for 3 regression tests, 
that requirement has been relaxed for iteration 3 as follows:  
__To get full credit for regression testing in iteration 3, you should create (and deliver) at least ONE other 
working regression test - that is in some way different than the one provided in this lab (lab 15).__ _We will provide more 
guidance on this below._ 

  In this lab we will give you the components necessary to create a regression test that you can use to test the final
versions of your simulations.  As noted above, regression tests are very valuable during the development process,
but even if you have finished development, running a regression test on the components of your simulation that 
have changed during development can help detect issues you have not yet uncovered, and
increase your confidence in your software if the regression test does not expose any issues.

  The regression test you will assemble consists of the original scenario provided with __transit_sim__ in 
iteration 1 (it uses the same inbound and outbound routes and stops, and they are hardcoded in the version of the
local_simulator_file (__r_local_simulator.cc__ and __r_local_simulator.h__) which we provide in this lab.
Once assembled, the regression test you create in this lab will produce the same output each time
it is executed (**once you make some changes to the passenger_factory.cc that we will discuss later**). 

   The lab 15 regression test uses many of the same classes and functionality as the __config_sim__ and __vis_sim__ -  but not all of the same classes
and functionality. Thus, the lab 15 regression test will only test the classes and functionality in the files that it _shares_ with __config_sim__ and __vis_sim__. Note, however, that the following files do not share classes and functionality with __config_sim__ and __vis_sim__. We are providing these new files to you so that you can create the lab 15 regression test:

* regression_driver.cc
* r_local_simulator.h
* r_local_simulator.ccc
* rtest_passenger_generator.h
* rtest_passenger_generator.cc

We have also provided an updated version of:

* passenger_factory.cc 

The methods in this new *passenger_factory.cc* can be configured to work in random or deterministic (repeatable) mode using a MACRO.

#### Creating the Lab 15 regression test executable

To create the regression test executable, perform the following steps with the files in the lab 15 folder:

1) Copy the file **regression_driver.cc** into your _project/drivers_ directory

2) Copy the files: **r_local_simulator.h, r_local_simulator.cc, rtest_passenger_generator.h, rtest_passenger_generator.cc**, and 
**passenger_factory.cc** into your _project/src_ directory

3) The makefile in your _project/src_ directory should have the following target: **%_test**

  Provided it does, you can create the regression test driver using your makefile as shown in step 4 below:

4) In your project/src directory, type the following on a command line: **make regression_test**

  If your make executes successfully, your regression test driver executable will be a file named: *regression_test* in the directory: _project/build/bin_. 

  If your makefile in the _project/src_ directory does **not** successfully create an executable file named *regression_test* in the _project/build/bin_ directory, make a backup copy of your makefile in your _project/src_ directory,
and copy the makefile from lab14 into your _project/src_ directory. Make sure your are in the _project/src_ directory. 

  Then type: **make regression_test** on the command line. 
  
  If your second attempt does not successfully create an executable file named: *regression_test* in the _project/build/bin_ directory, seek help from a TA.

5) Next, change directory to the _project/build/bin_ directory.  Then run the regression test twice, piping each output to a different output file as such:

  a) ./regression_test > rtout1
  
  b) ./regression_test > rtout2
  
6) Compare the output of rtout1 and rtout2 by checking for differences between the two files (there should not be any differences).

  You can do this by typing the following command on the terminal command line: *diff rtout1 rtout2*

**What happened?**  _There is output, so the output files produced by two successive runs of the regression_test executable are not the same_ - which means either the test failed or the test is not working correctly.
_In this case, the test is not working correctly because the methods in the file *passenger_factory.cc* are still using random behavior!_

To change that, change directory to _project/src_ and edit the file **passenger_factory.cc**. 

Find the macro directive:

**#define CONSTPASS 1** 

near the top of the file - it is commented out.

Uncomment-out the directive **#define CONSTPASS 1**, and save the file. 

Then recompile the regression test driver by typing: **make regression_test** at the terminal command line.

7) Finally, change directory to _project/build/bin_ and repeat steps 5 and 6 above.  

When you type the command: *diff rtout1 rtout2* on the terminal command line, it should not produce any ouput to the terminal.  

  If that is the case, congratulations, you have a regression test that you can use for iteration 3 in place!
  
  If that is not the case, talk to a TA.

#### Discussion and building your own regression test for iteration 3 (if you haven't already done so). 

You should inspect the files that we gave you to see how we have changed them from the files that they were based upon (and that we provided for you)
by running the **diff** command on them.  Specifically, you should review the differences between the following file pairs:

* **regression_driver.cc** and **transit_sim.cc**
* **r_local_simulator.h** and **local_simulator.h**
* **r_local_simulator.cc** and **local_simulator.cc**
* **rtest_passenger_generator.h** and **random_passenger_generator.h**
* **rtest_passenger_generator.cc** is based upon **random_passenger_generator.cc**

and finally, review the use of the MACRO to enable random or deterministic (repeatable) behavior at compile time in the file:
* **passenger_factory.cc**

You can use the techniques and concepts illustrated by the lab 15 regression test driver to create your own test driver for iteration 3 
(REMEMBER YOU NEED TO CREATE AT LEAST ONE REGRESSION TEST THAT DIFFERS FROM THE LAB 15 VERSION AND INCLUDE IT IN YOUR FINAL DELIVERABLES FOR ITERATION 3). 

Some possible ideas for creating your iteration 3 regression test are as follows:

1) You could create a new version of the lab 15  **r_local_simulator** files (.h and .cc) that use a subset of hardcoded stops in the __Start__ method, so the 
driver runs faster.  For example,  the eastbound route stops could be: 

* before_transit, tway, Fairgrounds, Buford & Gartner, SPSC

  AND the westbound route stops could be:

* SPSC, Buford & Gartner, Fairgrounds, tway, before_transit

Then create a new regression test driver (named something like my_regression_driver.cc) that uses the new version of r_local_simulator, compile it, and test it out! To make this driver specifically, do 'make my_regression_test'. This is just an example name. Please use one that makes more sense.

2) You could create a new version of all of the lab 15 files (**with the exception of passenger_factory.cc**). The files would use a
new version the passenger generator that adds a constant number
of passengers at each stop each time passengers are generated in a different way that the lab 15 regression test does (for example, each stop adds stop_id + 1 passengers each time a generation takes place)

Then create a new regression test driver (named something like my_regression2_driver.cc) that uses the new versions of the files , compile it, and test it out! To make this driver specifically, do 'make my_regression2_test'. This is just an example name. Please use one that makes more sense.

3) If you have config_sim working, you could make a copy of configuration_sim, and use the copy as the basis of a new regression test driver. 
You could then create a new versions of config_manager.cc. The new version of config_manager.cc could use
the lab 15 version of the **rtest_passenger_generator** (.cc and .h) files and **passenger_factory.cc** file to create 
a test that yields the same output each time.  This approach (approach 3) is the most flexible and complete because:

i) Initially, it  tests a larger set of classes and functionlity that either approach 1 or two above and,

ii) It is provides the ability to test many different routes because it uses the configuration manager - so different versions of config.txt
could be created and used to test. 

4) There are many more possible approaches that you may pursue if you are comfortable doing so. 

If you have already created a regression test that 
is different from the lab 15 regression test provided by this lab, **Congratulations**, you have already met the requirements for iteration 3. 

If not, hopefully this
lab will help you create your own version of the regression test for iteration 3, and you have fun and achieve success in so doing!




