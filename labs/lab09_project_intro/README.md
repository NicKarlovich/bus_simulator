# Proof-of-Concept (POC) for the Transit Simulation Project for 3081W

The base code for the transit simulator project of 3081W was born from this
proof-of-concept application written by Kevin Wendt. There are 2 primary
components: the <i>Passenger</i> and <i>Stop</i>. Passengers will be at stops and are quite oblivious to being there until moved around by the stop. The Stop ends up in control of everything in that it sends messages to Passengers to update. 

<hr>

## Mechanics of the POC

### Resources

You will probably want to refer to these as you work on the lab.

- Google Style Guide : https://google.github.io/styleguide/cppguide.html
- cpplint : https://github.com/google/styleguide/tree/gh-pages/cpplint

### Directory Structure

The directory structure for this lab is identical to that of the project.

- `Makefile`:
   - `make all` and `make clean` for the whole project (calls make recursively
     in subdirs).

- `src`:
  - All source code (.cc AND .h) lives under here.

- `src/Makefile`:
  - Builds the project source.
  - Creates the `build/bin/StopTest.exe` and `build/bin/PassengerTest.exe` executables.

- `build`: Created by the Makefiles. Should be added to your `.gitignore`.
  - `build/bin`: All executables generated for the project will appear in here.
  - **Do not push the build folder to your repo**
  
<hr>

## Getting Started

1. _pull_ into your support-code branch on your repo.

2. _merge_ the new lab code into your master branch.

3. Change directories to Lab 09: `cd labs/lab09_project_intro`

4. Copy your Passenger class files from Lab 08: `cp ../lab08_style_doxy/src/passenger.* ./src`

5. At the top level from the OS command prompt: `make`. 

6. At the command prompt: `./build/bin/PassengerTest.exe`

7. At the command prompt: `./build/bin/StopTest.exe`.

<hr>

## Code Explanation

What is given here is a rudimentary set of files for this POC. In fact, two were already missing: _passenger.h_ and _passenger.cc_, which were already given to you in Lab 08. This is the beginning of work towards a working Transit Simulation. Provided in this POC are testing facilities for both Passenger and Stop. They are *not* Google Test files, but rather simple driver applications which run the classes through a couple simple tasks, basically a working check for progress.

<hr>

## The Lab Assignment

### Fix the Passenger class

As mentioned in Lab 08, the Passenger class you are given is not working. Hopefully, you've added and fixed to make it style-compliant and documented. Now that it is style compliant, you must get it working properly. In particular, you need to fix the constructor, Update(), GetTotalWait(), and IsOnBus() methods.

### Build the Stop class

Stop is in even worse shape than the Passenger class was. The constructor, LoadPassengers(), and AddPassengers() methods all need an implementation.

<hr>

Push your code up to your repo for feedback.

<hr>

### OPTIONAL linter

Run your code through the linter and fix any errors. In the project, any submitted code must not have any cpplint errors, so please get into the habit of making your code Google Style compliant.

### OPTIONAL documentation

Build the documentation for the classes you've fixed. In the project, all the submitted code should be well-documented, so get into the habit of making your code Doxygen ready.
