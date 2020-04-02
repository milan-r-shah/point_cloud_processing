# point_cloud_processing
Sample ROS Package for processing PointCloud using Point Cloud Library (PCL)

### How to use this repo

#### 1. Clone this repo in the `src` directory of your catkin workspace:
``` 
$ cd <your_catkin_ws>/src/
$ git clone https://github.com/milan-r-shah/point_cloud_processing.git
```

#### 2. Compile the repo:
```
$ cd ..
$ catkin_make
$ source devel/setup.bash
$ roslaunch point_cloud_processing point_cloud_processing_node
```