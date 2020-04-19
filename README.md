# point_cloud_processing

This sample program is a ROS (Robot Operating System) package. It creates a ROS Node which fetches the point cloud data coming from the camera sensor and stores it into the vector of Point Clouds, using ROS Kinetic and Point Cloud Library (PCL).

Note: In this project, `catkin_make` build system has been used which under the hood uses `cmake` & `make` http://wiki.ros.org/catkin/commands/catkin_make

## System Requirements
- Ubuntu 16.04 LTS - Xenial Xerus

## How to use this repo

#### 1. Install Ubuntu 16.04 in your computer/laptop: https://ubuntu.com/tutorials/tutorial-install-ubuntu-desktop-1604#1-overview

#### 2. Install ROS Kinetic ( _this would take time!!_ ): [visit http://wiki.ros.org/kinetic/Installation/Ubuntu for more details]
```
$ sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu $(lsb_release -sc) main" > /etc/apt/sources.list.d/ros-latest.list'
$ sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654
$ sudo apt-get update
$ sudo apt-get install ros-kinetic-desktop-full
```
#### 3. Environment Setup: [visit http://wiki.ros.org/kinetic/Installation/Ubuntu for more details ]
```
$ echo "source /opt/ros/kinetic/setup.bash" >> ~/.bashrc
$ source ~/.bashrc
$ sudo apt install python-rosdep python-rosinstall python-rosinstall-generator python-wstool build-essential
$ sudo apt install python-rosdep
$ sudo rosdep init
$ rosdep update
```

#### 4. Create a ROS Workspace, also known as catkin workspace:
```
$ source /opt/ros/kinetic/setup.bash
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/
$ catkin_make
```

#### 5. Clone this repo in the `src` directory of your catkin workspace:
``` 
$ cd ~/catkin_ws/src
$ git clone https://github.com/milan-r-shah/point_cloud_processing.git
```

#### 6. Compile and run:
```
$ cd ~/catkin_ws
$ catkin_make
$ source devel/setup.bash
$ roslaunch point_cloud_processing point_cloud_processing_node
```

## Directory Structure
```
    .~/catkin_ws/src/point_cloud_processing
    |
    ├── config                          
    │   └── point_cloud_processing.yaml     # config file
    ├── data                                # Directory for storing data
    │   └── usage.txt
    ├── include
    │   └── point_cloud_processing
    │       └── point_cloud_processing.hpp  # header file - class declaration
    ├── launch
    │   └── point_cloud_processing.launch   # launch file
    ├── src
    │   ├── point_cloud_processing.cpp      # source file - class definition
    │   └── point_cloud_processing_node.cpp # contains main()
    ├── CMakeLists.txt                      # compiler instructions
    ├── package.xml                         # ROS Package Info
    └── README.md                           # README
```
#### As can be seen in the above directory structure of this repo/project, the important files are:
- `./package.xml`      :<br />
Contains the information of this ROS package

- `./CMakeList.txt`    :<br />
Contains the compiler instructions for compiling this ROS package

- `./launch/point_cloud_processing.launch` :<br />
Kind of XML file which contains instruction for launching this ROS node

- `./include/point_cloud_processing/point_cloud_processing.hpp` :<br />
Contains the declaration of `PointCloudProcessing` class, member variables, & methods

- `./src/point_cloud_processing.cpp` :<br />
Contains the definition of `PointCloudProcessing` class, member variables, & methods

- `./src/point_cloud_processing_node.cpp` :<br />
Contains main() where the ROS node, named `node`, i.e. an Object of `PointCloudProcessing` class is instantiated, frequency at which the data would be processed is mentioned


## Class Structure
- `PointCloudProcessing` class has `public` constructor, destructor, & class method `runOnce()` which have been declared in `./include/point_cloud_processing/point_cloud_processing.hpp`

- `PointCloudProcessing` class has different `private` methods as well as data members

- In `./src/point_cloud_processing_node.cpp`, first of all, name of the ROS node is initialized (Line No. 5); ROS NodeHandles are defined; and then an instance of class `PointCloudProcessing` is created: named `node`

- In `./src/point_cloud_processing_node.cpp`, there is `node.runOnce()` in the `while` loop which just displays "from runOnce()". The main magic happens by `ros::spinOnce()` which executes callbacks and releases the data from the camera sensor. `rate.sleep()` generates delay.

- In `./src/point_cloud_processing.cpp`, in the constructor, ROS Subscriber is initialized & so does some flag variables.

- In `./src/point_cloud_processing.cpp`, callback function for the ROS Subscriber is also defined.


## Which Rubric points have been addressed
1. Loops, Fnction, I/O: The project demonstrates an understanding of C++ functions and control structures. <br />
Line No. 13 in `./src/point_cloud_processing_node.cpp` : `while` loop

2. Loops, Fnction, I/O: The project reads data from a file and process the data, or the program writes data to a file. <br />
Line No. 10 in `./src/point_cloud_processing.cpp` : reading data from external ROS Topic

3. Loops, Functions, I/O: The project accepts user input and processes the input.
Line No. 3 & 4 in `./launch/point_cloud_processing.launch`

4. OOP: The project uses Object Oriented Programming techniques. <br />
Line No. 15 in `./include/point_cloud_processing/point_cloud_processing.hpp` : class `PointCloudProcessing`

5. OOP: Classes use appropriate access specifiers for class members. <br />
Line No. 17 & Line No. 22 in `./include/point_cloud_processing/point_cloud_processing.hpp`

6. OOP: Class constructors utilize member initialization lists. <br />
Line No. 10 & Line No. 13 in `./src/point_cloud_processing.cpp`

7. OOP: Classes encapsulate behavior. <br />
Line No. 10 & Line No. 27 in `./src/point_cloud_processing.cpp`
