# Solid-fuel rocket control software
## 1 Design assumption
1. Mikrocontroller STM32F303CBT6 is a processing unit
2. Data acquisition system is provided by PILC company
3. The data acquisition system consists of ADC, AHRS, GPS and recorder
4. TowerPro SG-90 servos deflect the control surfaces (4 servos used)
5. Supply voltage is realized usiong RHINO Li-Po battery
6. Additionally, a radio receiver HK-TR6A V2 is connected to the microcontroller board (only during manual flights)
7. Making a model of the rocket control system in the matlab\simulink program and generating code
8. Using Discovery board as a programmer
9. Devices communicate with each other via CAN bus
## 2 Hardware structure
![image](https://user-images.githubusercontent.com/117314126/200580335-192bd55e-0285-4452-baf0-71f1489f34c2.png)

                              Figure 1 Hardware structure of the designed rocket control system
In the figure 1, hardware structure is performed. In the green frame there are devices that aren't used during automatic flight. The symbols s1, s2, s3 i s4 denote serwomechanism. Devices communicate with each other via CAN bus.   
## 3 Components used in the project
![image](https://user-images.githubusercontent.com/117314126/200574258-b5be1323-db0c-4ad9-ba7c-72cddc4b41fb.png)

                              Figure 2 Container with measuring sensors
![image](https://user-images.githubusercontent.com/117314126/200575893-da6eae8e-e71a-433f-9b1b-34c1c884b56f.png)
                              
                              Figure 3 Sensors connected to the microcontroller via the CAN bus
![image](https://user-images.githubusercontent.com/117314126/200577310-a089de21-4c14-4522-934b-6b33859d2f5f.png)

                              Figure 4 Control system with connected radio receiver
![image](https://user-images.githubusercontent.com/117314126/200578606-fc550135-b600-49d3-acb4-fa103c5473da.png)![IMG_20220824_190933250](https://user-images.githubusercontent.com/117314126/200598105-c991b49b-cb14-49d1-abed-e34c5a53f636.jpg)




                              Figure 5 Control system with mounted control surfaces and rocket view
## 4 Results
![image](https://user-images.githubusercontent.com/117314126/200587488-1d451a5c-050f-4228-a9fe-ac1613c20c26.png)![image](https://user-images.githubusercontent.com/117314126/200588891-3668ad45-6b11-4c53-be80-7ededcd2d44e.png)

                              Figure 6 Rocket attitude and control surface deflection
Figure 6 shows the results obtained during the automatic fligh. A change in the position of the rocket was observed when the deflection of the control surfaces was changed. The rocket was initially placed at an angle of approximately 7.5 degrees to the vertical.
