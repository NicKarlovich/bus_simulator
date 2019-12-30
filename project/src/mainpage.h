/**
 * @file mainpage.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 * Edited by: Nick Karlovich
 */
#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
#endif  // SRC_MAINPAGE_H_
/*! \mainpage My Personal Index Page

\section intro_sec Introduction to Nick Karlovich's Bus Simulator Project

The current version of this project is Iteration 3: 12/11/19

# Welcome!

This is Nick Karlovich's Bus Simulator.  This program is a project created in CSCI 3081 at the University of Minnesota Twin Cities in the fall of 2019.  Its goal is to easily simulate busses picking up and dropping off passengers along a route.  The project is split into two parts, the configuration simulator and the visualization simulator.  The configuration simulator allows you to load your own configuration files into the program and test your specific bus simiulations.  The visualization simulator is used to visualize the campus connector around the U of M Campus.  There are two main sections: A user guide and a developer guide.  I recommend starting with the user guide in order to get a better understanding of the software.  Both sections will cover installing the software but the user guide will show you how to use the program while the developer guide will go more under the hood in C++ to show how the system works.  If you're not fluent in C++ I'd suggest the user guide.

<h1 id="user-guide">User Guide</h1>

If you are here, you are looking at the User Guide intended for non-developers.  If you are looking for the developer guide follow [this link](#developers-guide).  Before we get started it is important that you are running on a CSE-Labs Environment.  If you are not, many issues may occur where files will not be available and will cause issues that are incredibly difficult to fix when we try to make and run the program.  Also, the visual simulator will not work at all due to it requiring local files only available on CSE-Labs machines.  <b>Make sure you are on a CSE-Labs machine before continuing with this guide.</b>

## Getting the software:
In order to get the software required for this project to work, you will first need to open a web browser such as Firefox, Google Chrome or Microsoft Edge.  Once you have a browser open you will need to navigate to this website/link:

https://github.umn.edu/umn-csci-3081-f19/repo-karlo015

After following this link you should look and check to be certain you are on the master branch of the repository.  If you don’t know how to check that follow this guide.

https://help.github.com/en/github/administering-a-repository/viewing-branches-in-your-repository

Once you have confirmed that you’re on the master branch go over to the right where there should be a green button that says “Clone or download”.  Click that button and then copy the link that appears.  With this link, you should now be able to download the code from the GitHub repo to your machine.  By default the link should be:

https://github.umn.edu/umn-csci-3081-f19/repo-karlo015

From here you’ll want to open a Linux terminal.  If you’re on a CSE-Lab machine you should just be able to hit the Windows Key (or equivalent) and type in “terminal” which will open a command-line terminal.  Now, navigate to the folder where you’d like the program to run from using the ‘cd’ command.
Once you’ve reached the desired location, you should be able to type this command into the command line:

`git clone {link you copied earlier from github.umn.edu}`

Paste the link you copied earlier into the terminal by right-clicking with the mouse (CTRL + V won't work!)  Now, hit enter and it will begin downloading the repository to your computer.  Once that’s done we can move onto Compiling the system.

## Compilation:
At this point, you should have the entire bus simulator repository downloaded.  From here you should be able to ‘cd’ into the project directory by entering this command.

`cd ./repo-karlo015/project/`

From here you have two options, the visualization simulator or the configuration simulator.
The visualization simulator launches a web server on your local machine where you can see the buses traversing along the route.  This will absolutely require you to be on a CSE-Lab machine as some files are only available from a CSE-Lab machine.  If you are not on a CSE-Lab machine you **WILL NOT** be able to compile the visualization simulator.

The configuration simulator runs a command-line version of the bus simulator.  With the configuration simulator you can supply your own configuration file and number of iteration parameter to customize your simulation.

By typing `make` from the project directory (the directory we are currently in) you will be building the executable files for both the visualization simulator and configuration simulator.  If you are on a CSE-Lab Machine you are safe to type `make`, otherwise your compilation will fail.
If you would like to build either simulation you can enter this command to traverse to the src/ directory.

`cd ./src`

Once in this directory you can still type `make` which will create both simulations, but you also have the option of directly creating either simulator independently.
If you’d like to create the visualization simulator type this command:

`make vis_sim`

If you’d like to create the configuration simulator type this command:

`make config_sim`

Once you’ve run one of the above commands your simulator should be fully compiled and ready to run.  If for any reason your compilation fails, type this command to “clean” your directory so you can make the files again from a clean state.

`make clean`

## Running

Now we should have our executable files compiled and ready to run!

### Configuration Sim
We’ll start by running configuration sim.  First, we should first navigate back up to the project directory.  If you try to run this executable from a different folder the executable will not be able to find the files necessary.  So, type this command to go to the project directory (assuming you’re currently in the src/ directory)

`cd ../`

Now, type this command into the terminal

`./build/bin/config_sim`

This should run the configuration simulator in the current terminal window.  Now if we’d like to customize our configuration simulator a bit more we have two optional command line parameters.  Those are, <i>config_file_name</i> and <i>num_of_simulation_updates</i>.  As a note, in order to use the second parameter (<i>number_of_simulation_updates</i>) you will need to supply a configuration file.  The “template” command with these two parameters is a such:

`./build/bin/config_sim {config_file_name} {num_of_simulation_updates}`

Where you would replace the variables above (including the curly braces { } ) with your custom variable.
The configuration file name has a few requirements.  Your configuration file should be a text file, and the file should be located in the /config/ directory (one subfolder down from where we are currently)

The number of simulation updates also has a few requirements.  The value passed in must be a positive integer. For example, 5, 20, 1, 200.  Beware of extremely large numbers as this will cause the simulation to run for a very long time!  Values that aren’t valid would be: -1, -100, 0, 5.2, or cats.
If you supply an invalid configuration file the program will use its default <i>config.txt</i> file.  **DO NOT OVERWRITE THE DEFAULT <i>config.txt</i> FILE**.
If you do not provide, or provide an invalid <i>number_of_simulation_updates</i> value, the program will default to a runtime of 1 (which is very short).  If you'd like to edit the <i>number_of_simulation_updates</i> while not providing a config file, type <i>config.txt</i> for the first value.  This will use the default config file.

Any extra variables supplied to the program will be ignored.  [This section](#creating-custom-config-file) below will describe how to create a custom config.txt file.

### Visualization Sim
Now we will be looking at how to run the visualization sim.

If you aren’t already in the project directory you should navigate to that directory now, this is the command to navigate from the src directory up to the project folder.

`cd ../`

Now that you’re in the project directory you can type this command to run the visualization sim

`./build/bin/vis_sim {port_number}`

When you type in this command you should replace <i>{port_number}</i> (including curly braces { }) with a port number that is available on your machine.  Typically a safe port to use is 8008.  If this port fails, try again with a number between 8000 and 9000 that is not divisible by 5 until you find an open port.

If you see an output in your terminal similar to the one below then your visualization simulator has run successfully.

```
Usage: ./build/bin/ExampleServer 8008
Using default config file: config.txt
starting server...
```

Once you see this output in your terminal open up an internet browser on your local machine and navigate to this url:

http://127.0.0.1:{port_number}/web_graphics/project.html

replacing the parameter <i>{port_number}</i> with the number you used when you ran the command.
Once on this website, the terminal should update and print out the statement “Connection Established”.  Before starting the visualization simulator, no stops or busses will appear on the map.  On this website you should see a screen with a map (by default on the U of M campus) along with 4 elements along the left-hand side:

<ol type="1">
  <li>Number of time steps to run.</li>
    <ol type="a">
      <li>By sliding the slider beneath the label “Number of time steps to run:” you can change the number of times the bus will Update which will move the bus forward and possibly pick up and drop off passengers.  You can choose a value between 1 and 50 with the built in slider.</li>
    </ol>
  <li>Time steps between busses for route.</li>
    <ol type="a">
      <li>By sliding the slider beneath the label “Time steps between busses for route 0:” you will be deciding how many time steps that need to occur in order for another bus to be sent along the outgoing route.  These values can be changed to be between 1 and 10.  If your visualizaiton has more than one route more of these sliders will appear, one for each full route.</li>
    </ol>
  <li>Run.</li>
    <ol type="a">
      <li>The Run text is a header for the Start Button below.</li>
    </ol>
  <li>Start.</li>
    <ol type="a">
      <li>The button Start, when pressed, will begin the simulation.  This will load the stops and routes onto the map.  It will also begin outputting report information to the terminal.  After the simulation has run you will have to hit CTRL + C in the terminal to “kill” the program.</li>
    </ol>
</ol>

Now you're done!  You’ve now run either the configuration simulator or the visualization simulator (or both!).  There are a few more in-depth options that will not be listed here but will be viewable in the developer guide if you’d like to edit the simulator more.  Thanks for using this bus simulator! 

<h1 id="developers-guide">Developers Guide</h1>

## Quickstart Guide:

If you'd like a more in-depth overview of how to run the software look above in the [User Guide](#user-guide).  To run this you'll need to be on a Linux CSE-Labs machine to access all the necessary files.  First, download the repo from https://github.umn.edu/umn-csci-3081-f19/repo-karlo015 and clone it to a local directory.  Next, you'll need to traverse to the repo-karlo015/project/src/ directory.  Once here you can run the command `make` in order to build both the config_sim and vis_sim or run make with either config_sim or vis_sim to build just that executable.  To run both files you'll need to go back into the project/ directory.  Then enter either `./build/bin/config_sim {config_file_name} {number_of_iterations}` or `./build/bin/vis_sim {port_number}`.  The parameters for config_sim are by default set to config.txt and 1 respectively and are optional.  The parameter `port_number` for the vis_sim .exe is suggested to be a local port number over 8000 and not in use.

## Main Classes

Currently, my project is separated into 6 main parts, Configuration Manager, Simulator, Bus, Route, Stops and Passengers.

The Configuration Manager is what controls the simulation if the simulation uses a configuration file.  The ways to build and run the program are either via config_sim or vis_sim.  vis_sim by default uses configuration files and configuration manager logic.  `config_sim` directly uses the configuration manager and subprocesses.  This effectively standardizes the methods by which we run our bus simulator.  This way instead of having to create specific simulator classes and write hard code to run a simulation we can just supply the configuration manager with the appropriate config file and it will do the difficult work of creating the routes and such that make up the simulation.
Currently the configuration manager takes in two parameters, a configuration file (uses a default if the provided is invalid) and a number of iterations the simulation should run for, i.e. the length of the simulation in terms of Update calls.  If you'd like to look into making your own configuration files, the example file config.txt is included in the project/config directory or there is [a guide here](#creating-custom-config-file)

One magic variable that is always defined for the configuration manager is the amount of time between bus generations.  There is some functionality groundwork built into the code, but it is not fully developed and thus not a feature of the configuration simulator.  With some code-editing, you could modify the code to get it to begin working but it is not a supported feature of the configuration manager and as such, the bus generation timings are always ten iterations between every route.

The visualizations simulator is an extension of the configuration simulator.  It pulls from a remote directory only available on CSE-Labs machines and then runs a visualizer on the local machine that executed the compiled file.  The visualizer allows the user to select the time between bus generations to be an integer between 1 and 10.  They can also control how long the simulation runs for by choosing a value between 1 and 50.  There is no currently implemented feature for the visualization simulator to take in configuration files as it will always use its own default. (config.txt)

## Class Structure

At the highest level, Simulators are what control the system.  The simulator handles the creation of stops, busses, routes, passengers, distances between routes and is in charge of updating all the aspects of the simulation.
The simulator also keeps track of adding and removing passengers and buses from the simulation.
When the simulator updates, it calls the Update function on alll existing Bus and Route objects.

The Bus keeps track of its position along a route, what passengers it currently is holding onto, the speed its moving, and the distance it is away from the next stop.

When a Bus is updated, it will first move its speed towards the next stop.  If the Bus's distance_remaining_ is greater than 0, then it still has a distance to go and will call update on each of its passengers.
If the Bus makes it to a stop after a given update call it will first check if there is anybody on the Bus whose stop is the current stop.  It will do this by matching the passenger's destination ID to the stop's ID.
All the passengers whose destination is at the current stop are unloaded from the Bus and removed from the simulation.  Next, the Bus will check it's current capacity, and if the Bus has room, it will begin boarding passengers from the stop.

Important Note: Each stop is unique to a route.  This means that all passengers at a stop will get on any Bus that arrives at that stop.

Important Note2: Busses are in control when they reach a stop and begin adding passengers.  When the bus reaches a stop, it will ask the stop for a list of passengers, remove the passengers it puts on the Bus from the stop, and then return the list of remaining passengers to the stop.

Once all the passengers at the stop are loaded, or the Buses capacity is reached, the Bus will get ready to leave from the stop by setting its destination to the next stop in the route and setting its distance accordingly.
An important exception to the Bus loading protocol occurs when the Bus reaches the end of a route.  No passengers are ever generated at the last stop of a route, but when a Bus reaches the last stop of a route, it will forcefully unload all remaining passengers.
Once the Bus forcefully unloads all remaining passengers, if it has an incoming_route_ remaining, it will begin on that route.  If the Bus has gone out on it's outgoing_route_ and is coming back on its incoming_route, it will remain at the last stop on the incoming_route_ and wait to be removed by the simulation.

When the simulation calls update on the Route, passengers are generated by a PassengerGenerator at the stops that are along the route.
As a rule, passengers are never generated at the last stop on a route, and a passenger's destination is always after its starting stop.
The passengers are generated at stops according to a probability array that is defined in the simulator and given to the PassengerGenerator.

Once the passengers are generated, Route then iterates over the stops it has in its route and calls Update() on them.
An important aspect of routes is that no route object is ever used twice, If two Busses are traveling along the same route, each route may be referencing the same stops but Routes are essential private variables of the Busses that go along them, so a Clone() method has been implemented to duplicate routes in their initial state.

Stops are pretty tame with their updates, they are basically glorified lists with a few helpful identifying variables.  When Stops are updated, they will call Update on each of the passengers currently waiting at the stop.
Bus updates come before Stop updates so there is no risk of passengers being updated twice in a single time step.

Passengers are pretty tame as well.  When they are updated they check a boolean value inside them that tells them if they are on a Bus or if they are at a stop.  Depending on their state they update their time_on_bus_ or wait_at_stop_ times accordingly.
Other than that, when a passenger is placed on the Bus by the Bus, the Bus calls a function called GetOnBus() on the passenger which tells the passenger they are now on a Bus, in this function is where passengers are updated.
The reason we leave the Update() function for the passenger to call is so that the passenger can be certain that it is either on the Bus or off the Bus when its time is incremented as we don't want it to get out of order.  Thus GetOnBus() is the definitive call that puts a passenger on the Bus.

The four main objects of the simulation also each have their respective Report() functions.  These take an ostream variable so that the output location of the reporting of the system can be changed to any valid ostream.

## Implementing Your Own Files

If you'd like to create your own simulators or passenger genrators the best way to do that would be to use some existing files as a template.  If you'd like to add a new passenger generator you have two options, either make a copy of random_passenger_generator.cc/.h and then edit them to fit your needs, or you can create one from scratch.  If you create one from scratch you should make sure to make it a child-class of the parent class PassengerGenerator.

If you'd like to create you rown simulator you can follow a process similar to creating a custom passenger generator.  Either duplicate local_simulator or configuration_simulator and then edit to your liking, or create it from scratch.  Again if you create a file from scratch you should make sure that the custom simulator you implement is a child-class that inherits from Simulator.h

<h2 id="creating-custom-config-file">Creating Custom Config File</h2>

Creating a custom configuration file [Advanced]:

First open up a text editor of choice (notepad or notepad++ works well, Word or Google Docs is suboptimal).  As a general rule any text encapsulated with curly braces { } is text that you will need to replace with the values described in the braces.  As a reference you can also look at config.txt (but don’t edit it, make your own copy)

```
Line 1 should always be:
ROUTE_GENERAL, {name_of_set_of_routes}
Line 2 should be blank
Line 3 should be:
Stop Name, Long, Lat, Pass Gen Prob
Line 4 should be blank


From here you have a repeatable pattern where you could add routes.  The general formula is as follows:
ROUTE, {name_of_outgoing_route}
[newline, ie blank]
STOP, {Stop Name}, {Stop Longitude}, {Stop Latitude}, {Passenger generation probabilities}
[repeat above line as many times as you’d like, one line for each stop]
[newline, ie blank]
ROUTE, {name_of_incoming_route}
ROUTE, {name_of_outgoing_route}
[newline, ie blank]
STOP, {Stop Name}, {Stop Longitude}, {Stop Latitude}, {Passenger generation probabilities}
[repeat above line as many times as you’d like, one line for each stop]
[newline, ie blank]
Now you can repeat this pattern of routes as many times as you’d like, but note that each route needs an outgoing route and incoming route. 
```


Example config file
```
ROUTE_GENERAL, Campus Connector

Stop Name, Long, Lat, Pass Gen Prob

ROUTE, East Bound

STOP, Blegen Hall, 44.972392, -93.243774, .15
STOP, Coffman, 44.973580, -93.235071, .3
STOP, St. Paul Student Center, 44.984630, -93.186352, 0

ROUTE, West Bound

STOP, St. Paul Student Center, 44.984630, -93.186352, .35
STOP, Buford at Gortner Avenue, 44.984482, -93.181657, .05
STOP, Blegen Hall, 44.972638, -93.243591, 0
```


*/
