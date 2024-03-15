import matplotlib.pyplot as plt

# Sample data (replace with your actual data)
actual_distances = [15, 20, 30, 40, 50]  # Actual distances in cm
measured_distances = [9, 19, 32, 38, 48]  # Measured distances in cm

# Plot the data
plt.figure(figsize=(8, 6))
plt.scatter(actual_distances, measured_distances, color='blue', label='Measured Distances')
plt.plot(actual_distances, actual_distances, color='red', linestyle='--', label='Actual Distances')  # Plot a diagonal line for reference
plt.xlabel('Actual Distance (cm)')
plt.ylabel('Measured Distance (cm)')
plt.title('Measured vs. Actual Distances')
plt.legend()
plt.grid(True)
plt.show()
