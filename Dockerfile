FROM osrf/ros:kinetic-desktop

LABEL com.nvidia.volumes.needed="nvidia_driver"
ENV PATH /usr/local/nvidia/bin:${PATH}
ENV LD_LIBRARY_PATH /usr/local/nvidia/lib:/usr/local/nvidia/lib64:${LD_LIBRARY_PATH}

RUN apt-get update \
 && apt-get install -y \
    wget \
    lsb-release \
    sudo \
    mesa-utils \
 && apt-get clean


# Get gazebo binaries
RUN echo "deb http://packages.osrfoundation.org/gazebo/ubuntu `lsb_release -cs` main" > /etc/apt/sources.list.d/gazebo-stable.list \
 && wget http://packages.osrfoundation.org/gazebo.key -O - | apt-key add - \
 && apt-get update \
 && apt-get install -y \
    gazebo8 \
    ros-kinetic-gazebo8-ros-pkgs \
    ros-kinetic-fake-localization \
    ros-kinetic-joy \
 && apt-get clean

RUN apt-get install net-tools
RUN mkdir -p /tmp/workspace/script
COPY rosdocker.bash /tmp/workspace/script
ARG ROSDOCKER_ARG="client 172.17.0.1"
ENV ROSDOCKER_ARG ${ROSDOCKER_ARG}
COPY .run.bash /tmp/workspace/script

RUN mkdir -p /tmp/workspace/src
COPY prius_description /tmp/workspace/src/prius_description
COPY prius_msgs /tmp/workspace/src/prius_msgs
COPY prius_msg_converter /tmp/workspace/src/prius_msg_converter
COPY car_demo /tmp/workspace/src/car_demo
RUN /bin/bash -c 'cd /tmp/workspace \
 && source /opt/ros/kinetic/setup.bash \
 && catkin_make'

CMD /tmp/workspace/script/.run.bash ${ROSDOCKER_ARG}
