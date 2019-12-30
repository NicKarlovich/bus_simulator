The purpose of this lab is to help you get the interface from the transit simulation to the visualizer in place. 

First and foremost, if you have not read the requirements specification for iteration 2, you should go to the following link and do so:

https://github.umn.edu/umn-csci-3081-f19/csci3081-shared-upstream/blob/support-code/project/docs/Iteration2Requirements.md

Pay special attention to the deliverables required by the Preliminary 1 deliverable. 

Next, you should copy the file included with this lab, **data_structs.h** to your _project/src_ directory of your 'devel' branch. Keep in mind Lab10, the advanced git lab, and ask yourself (or your neighbors!): "Should we be doing everything in devel?" :thinking:

Once you've completed the previous step,  you should open the file **data_structs.h** and review the structures that the visualizer requests from the transit simulation. The information in the structs is used by web-based visualizer to display infomation about buses, routes, and stops on the campus map _as the transit simulator executes_.  Note that the visualizer is a Web-Server that uses a REST-like interface to communicate with the transit_simulator (That is why you have to run it before running the transit simulation, and refresh it each time before  re-running your transit simulation). 

For your first deliverable for iteration 2, you should add the accessors/getters and mutators/setters below to the bus and route classes and then design, implement 
and run unit tests (created using google test) to ensure the functions work properly.

More specifically, you should implment the following public functions in the bus class

  * `void UpdateBusData()`  - called by the visualizer to instruct the bus object to populate the BusData struct with the latest information (see the file **data_structs.h** to determine what information the BusData struct stores.). This a nontivial method, so we will outline its operation (which you have to implement), below.
  * `BusData GetBusData()` - called by the visualizer to obtain the BusData struct.
  * `string GetName() const` - called by the visualizer to get the name of the bus 
  * `Stop * GetNextStop()` - called by the visualizer to get the pointer to the bus's next stop
  * `size_t GetNumPassengers()` - called by the visualizer to get the current number of passengers on the bus
  * `int GetCapacity()` - called by the visualizer to get the maximum number of passengers that the bus can hold
  
**Outline of UpdateBusData() algorithm - this method populates a BusData struct**

_Make sure to include a member variable BusData within the Bus class._

  1. Store a unique identifier for the bus(name) in the BusData `id` atttribute.
  2. Use the current route to get the previous stop (on the current route). You will need to figure out a way (write a new function, etc.) to get the bus's previous stop.
  3. Compute and store the average of the latitudes and longitudes belonging to the current and previous stops.
  4. Store the averages in the BusData `position` attribute.  (This algorithm is somewhat clunky and not realistic. We may update this in the future.)
  5. Populate the `numPassengers` and `capacity` attributes within your BusData variable.
 
Next you should implement the following public accessors and mutators in the route class

  * `string GetName()` - called by the visualizer to get the name of the route
  * `list<Stop *> GetStops()` - called by the visualizer to get the route's list of Stop pointers
  * `void UpdateRouteData()` -   called by the visualizer to instruct the route object to populate the RouteData struct with the latest information (see the file **data_structs.h** to determine what information the RouteData struct stores.). This a nontivial method, so we will outline its operation (which you have to implement), below. 
  * `RouteData GetRouteData()` - called by the visualizer to obtain the RouteData struct.
  
 **Outline of UpdateRouteData() algorithm**
 
 _Make sure to include a member variable RouteData within the Route class._ **Note: this mistakenly used to say "within the Bus class." There should NOT be a RouteData object within the Bus class.**
 
  1. Store a unique identifier for the route(name) in the RouteData `id` atttribute.
  2. Create a vector that holds StopData structs.
  3. Loop through the Route's stops and do the following:
  - store a unique identifier for the stop(id) in the StopData `id` attribute, position (latitude and longitude), and the number of passengers at the stop in a temporary StopData struct
  - store the temporary StopData struct in the vector of StopData structs you created in step 2 (i.e. "push_back" the struct)
  4. After the loop finishes, store the vector of StopData structs in the `stops` attribute of the Route class's new attribute to store Route Data.
    
**TEST THE FUNCTIONS YOU HAVE JUST CREATED**

Once you have added the functions to the Bus and Route classes and sucessfully compiled and regression tested your transit simulation to ensure it still works, you should write google tests to thoroughly test their operation. At a minimum, your tests should instantiate bus, route, and stop objects (stops will belong to the route(s) you instantiate), and then call the accessors that you have implemented in the Bus and Route classes, and check to make sure that they return the data you populated them with when you instantiated them. 
