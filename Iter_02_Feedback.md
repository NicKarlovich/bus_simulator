### Feedback for Iter 02

Run on November 14, 13:47:51 PM.


### Basic Tests on Devel

+ Pass: Checkout devel branch



<hr>

This feedback is being batched and will run every few hours. Note that these feedback tests are a *work in progress* and will possibly be updated to contain more tests as they are developed. Check back periodically for more feedback as well as for your updated results.

<hr>


#### Necessary Files and Structure

+ Pass: Check that directory "project" exists.

+ Pass: Check that directory "project/src" exists.

+ Pass: Check that directory "project/tests" exists.

+ Pass: Check that directory "project/docs" exists.

+ Pass: Change into directory "project/src".

+ Fail: Compiling capture_transit_sim target of the src/ makefile...

<pre>make: *** No rule to make target 'capture_transit_sim'.  Stop.
</pre>



+ Skip: Check that file "../build/bin/capture_transit_sim" exists.

  This test was not run because of an earlier failing test.


#### Style Checking All src/ Files

+ Pass: Check that file "mainpage.h" exists.

+ Pass: Ignoring mainpage.h



+ Fail: Grading style compliancy errors Found: 1 errors, Expected 0.

+ Pass: Restoring mainpage.h




### Git Usage

+ Pass: Run git ls-remote gather all branches in repo

		b03caaaa677927828fd4f71b9d58690704a5b2a5	refs/heads/dev/iteration1

		0fc8828c78a3308553310ba6b2bbb5dfce30e88d	refs/heads/devel

		6851b9f00e4e284128d7a6bc36928d9a7d5a4a00	refs/heads/fix/01-compilation-errors

		711965787aff64888bcfa8d32334696be7502f21	refs/heads/fix/02-enhancement

		98441eee84230b80c77d071c20d18e6c0d3426aa	refs/heads/fix/03-passenger-wait-time

		7ee88775adc55b4b41aef73b212c74ebf75a183f	refs/heads/fix/04-iteration1-prelim2-unit-tests

		4f65b435413269b3a27a6ec0bdfc61155ce103aa	refs/heads/fix/05-unit-tests

		ef15d0c764bf13c58d90e78b904d3b4f538215ea	refs/heads/fix/06-bus-update-segfault

		79ee500dae5f9b0e3cedd231b34c492df90f66f2	refs/heads/fix/07-creating-doxygen

		b03caaaa677927828fd4f71b9d58690704a5b2a5	refs/heads/fix/09-cpplint-compliance

		369685ded690918cde5760cf965ecb836896a9ad	refs/heads/fix/10-bus-testing-functionality

		0a77183896a34d71c8df9bf25bc74dcf2d235a3a	refs/heads/fix/11-cleanup-bus-functions

		2d139e4952bd76168f0b618869ece2a207de6035	refs/heads/lab/12

		ef76550b718f4e57dd342e5e3eecdf2877be977b	refs/heads/master



<hr>

Gathered all branches in this repo. Note that passing this test does *not* mean that a sufficient amount of branches were found.

<hr>

