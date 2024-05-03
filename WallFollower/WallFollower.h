#ifndef WALLFOLLOWER_H
#define WALLFOLLOWER_H

class WallFollower {
public:
    WallFollower(int sensorPin); // Constructor with sensor pin
    ~WallFollower(); // Destructor

    void followWall(); // Method to initiate wall following behavior
  
};

#endif // WALLFOLLOWER_H
