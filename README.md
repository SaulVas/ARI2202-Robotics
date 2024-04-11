# ARI2202-Robotics

Project Part 3 - Line Following & Infrared Sensors

## Task 1 - Analysis

1. Define Metrics: Focus will be on detection accuracy, more specifically different coloured lines (example -> black, white and grey). This must be done without changing the light conditions to keep the setup simple.
2. Experimental Setup: Test the module's detection accuracy for the chosen colours on surfaces that are uniform in colour and texture.
3. Observation: Note the performance differences.

The experiment was performed as follows:
We collected ranges of detection for the background, each of the 3 colours and when the robot was off the ground. These were as follows:

- Background: 37 - 47
- White Tape: 37 - 45
- Gray Tape: 170 - 403
- Black Tape: 615 - 790
- Off the Ground: 850 + (depending on distance to ground)

Using these ranges we created threshold values so the robot could detect what it was on top of and we used serial.print to display the info.

Observations:
White tape is impossible to detect as its ranges overlap the background, we had a very high level of accuracy for all the other states.

## Task 2

For the sake of simplicity in our code we assume we are on a black line whenever a value higher than the lower threshold is recieved. We are ignoring when the robot is lifted off the ground to keep our implementation simple and followable.

Our line following algorithm is as follows:
If (middle on the line):
Move Forwards

if (Only left on line);
Turn left

if (only right on line):
Turn Right

If not on line:
Stop

## Task 3

### Path Navigation

When the robot encounters a sudden change in direction or sharp turn, due to its momentum it tends to slide off the line. Our approach to handle this is to keep track of the last direction the robot turned at all times (Left or Right). When the robot is not on the line, It turns in that direction for 2 seconds at a fixed speed, all the time searching for the line again to continue navigating. If it doesnt find the line in 2 seconds, it turns in the opposite direction for a second and a half at double the speed. This approach allows the robot to handle extremely sharp changes in direction and 90 degree turns.

### Junction Handling

If all 3 sensors detect the black line we enter junction handling mode. Normal robot opperations are suspended and we go into the first of 3 stages.

#### Stage 1

In the first stage the robot moves forward for 0.2 seconds to establish whether the black line continues straight after the junction. If a line is detected (middle > THRESHOLD && (left > THRESHOLD || right > THRESHOLD)), we check for obstacles within 30 cm. If no obstacle is detected we return to normal robot operations and continue forwards. Otherwise, if no valid path is detected within 0.2s, We move onto stage 2.

#### Stage 2

In the second stage, the robot turns left for 2.8 seconds. During this time it searches for a line without an obstacle. if a valid line is found it continues with normal operations, otherwise if the time runs out we proceed to stage 3.

#### Stage 3

In the third stage, the robot turns right at double speed for 2.9 seconds. During this time it searches for a line without an obstacle. if a valid line is found it continues with normal operations, otherwise if the time runs out we stop all robot procedures as weve encountered a dead end.

### Observations

The blind detection function works great and navigates complex turns fantastically. However, the Junction handling approach is limited by the fov of the robot. If there is a small object on the line, it will not be detected and the robot crashes. On the other hand, if the obstacle is very big, It handles intersections great. the obstacle size does not effect obstacles on the path directly infront of the robot.
