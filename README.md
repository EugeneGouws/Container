\# Container Client



A Qt/C++ desktop application for managing containers and pallets, 

with XML serialization and TCP network transmission.



\## Description



Container Client allows users to create and manage two types of containers 

(boxes and cylinders), organise them onto numbered pallets, and transmit 

the resulting pallet data as XML over a TCP connection to the 

Container Server application.



\## Features



\- Create \*\*Box\*\* containers with breadth, length, height and weight

\- Create \*\*Cylinder\*\* containers with diameter, height and weight

\- Auto-generated container codes by year, month and type e.g. `2026/3/B0`

\- Assign unallocated containers to numbered pallets

\- Pallets automatically track total weight and volume

\- XML serialization runs in a separate thread using QtConcurrent

\- Live XML preview in the Post XML tab

\- Send XML data to Container Server via TCP socket

\- Backup and restore container list

\- Splash screen on launch

\- Exit confirmation dialog



\## Screenshots



!\[Containers Tab](screenshots/containers.png)

!\[Container List](screenshots/list.png)

!\[Post XML Tab](screenshots/post.png)



\## Requirements



\- Qt 6.10.1

\- CMake 3.x or higher

\- Qt Creator 18.0.2



\## How to Run



> \*\*Note:\*\* Start \[Container Server](https://github.com/EugeneGouws/ContainerServer) 

> first, otherwise the client will not connect.



1\. Open `CMakeLists.txt` in Qt Creator

2\. Configure the project

3\. Click Run



\## Status



Complete — standalone deployment not yet configured.



\## Author



Eugene Gouws

