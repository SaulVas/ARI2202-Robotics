# ARI2202-Robotics

Project Part 3 - Line Following
Task 1 - Analysis

1. Define Metrics: Focus will be on detection accuracy, more specifically different coloured lines (example -> black, white and grey). This must be done without changing the light conditions to keep the setup simple. (The obvious observation would be that if the line is the same or similar colour to the floor tiles, then it will be harder to track. I also think that light colours would have trouble being detected depending on how good the sensor is.)
2. Experimental Setup: Test the module's detection accuracy for the chosen colours on surfaces that are uniform in colour and texture. We need to make sure the line itself contrasts well with each bckground colour so that the module has the best chance at detecting it.
3. Observation: Note the performance. The module may have higher accuracy on high contrast surfaces (black line on white background) when compared to surfaces with lower contrast (grey line on white surface). It is also possible that the module's sensors have a colour bias due to their inherent sensitivity or the algorithms used to detect the lines.

The experiment is as follows, detect the analogue output from sensing non-reflective surfaces of 3 colours. Compare this to reflective tape of the 3 colours. Next place a line of reflective tape of each colour onto a plain white paper. See whether the sensor can detect the lines.

Why is it due to the reflective property?
The output from an analog read of an IR sensor is a numerical value that represents the intensity of the detected infrared light (0-1023).


## Task 3 

1. Pseudocode

Note: Set pins as input 
      Serial.begin(9600)

// Straight

if right_sensor and left_sensor do not detect black and middle_sensor detects black
  
  set left motor ON
  
  set right motor ON

// Stop

if right_sensor and left_sensor and middle_sensor do not detect black

  set left motor OFF
  
  set right motor OFF

// Move Left

if only left_sensor detects black

  set left motor OFF
  
  set right motor ON

// Move Right

else if only right_sensor detects black

  set left motor ON
  
  set right motor OFF

// Sharp Move Right

if right_sensor and middle_sensor detect black

// Sharp Move Left

else if left_sensor and middle_sensor detect black

// Checks whether line continues after junction or it is the end

if left_sensor and middle_sensor and right_sensor detect black

  set both motors OFF for 2 seconds
  
  set both motors ON for 1/4th rotation
  
  continue to normal line-following algorithm

// Finish

if left_sensor and middle_sensor and right_sensor detect black

set left motor OFF

set right motor OFF
