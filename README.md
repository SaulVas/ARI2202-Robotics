# ARI2202-Robotics

Project Part 3 - Line Following
Task 1 - Analysis

1. Define Metrics: Focus will be on detection accuracy, more specifically different coloured lines (example -> black, white and grey). This must be done without changing the light conditions to keep the setup simple. (The obvious observation would be that if the line is the same or similar colour to the floor tiles, then it will be harder to track. I also think that light colours would have trouble being detected depending on how good the sensor is.)
2. Experimental Setup: Test the module's detection accuracy for the chosen colours on surfaces that are uniform in colour and texture. We need to make sure the line itself contrasts well with each bckground colour so that the module has the best chance at detecting it.
3. Observation: Note the performance. The module may have higher accuracy on high contrast surfaces (black line on white background) when compared to surfaces with lower contrast (grey line on white surface). It is also possible that the module's sensors have a colour bias due to their inherent sensitivity or the algorithms used to detect the lines.

The experiment is as follows, detect the analogue output from sensing non-reflective surfaces of 3 colours. Compare this to reflective tape of the 3 colours. Next place a line of reflective tape of each colour onto a plain white paper. See whether the sensor can detect the lines.

Why is it due to the reflective property?
The output from an analog read of an IR sensor is a numerical value that represents the intensity of the detected infrared light (0-1023).
