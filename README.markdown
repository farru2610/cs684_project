# Line-Following Robot with Obstacle Avoidance and Parking

This project implements a line-following robot controller in the **Heptagon** synchronous programming language. The robot navigates white and black lines, switches between them, avoids obstacles, handles intersections, and performs parking maneuvers using PID control for precise line tracking. Designed for a robotics course, it showcases reactive and state-based control for autonomous navigation.

## Table of Contents
- [Overview](#overview)
- [System Components](#system-components)
- [Requirements](#requirements)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview
The line-following robot uses a synchronous control system to process inputs from five line sensors, two IR sensors (front-left and front-right), and two obstacle sensors (left and right). It employs PID controllers for line tracking, finite state machines for navigation and obstacle avoidance, and specialized logic for intersection handling and parking. The system switches between white and black line modes, adapting sensor processing accordingly, and halts after completing a predefined sequence of intersections.

## System Components
The project is implemented in a single Heptagon file (`line_follower.ept`) with modular nodes for different functionalities:

1. **White Line Following**:
   - **Purpose**: Tracks a white line on a dark surface using five line sensors.
   - **Implementation**: The `White` state in the `main` node inverts sensor values (`1023 - sensor_value`) to treat white as high (reflective) and dark as low.
   - **Behavior**:
     - **Forward**: Moves straight at speed 80 when the central sensors detect the line.
     - **Goleft/Goright**: Turns left or right (speed 80) when outer sensors (sen0 or sen4) detect the line.
     - **Pid**: Applies PID control for fine adjustments when central sensors (sen1, sen3) deviate, maintaining alignment.
   - **Transition**: Switches to black line mode when sensors indicate a horizontal black line (`sen0 > 500 and sen4 > 500` with central sensors low).

2. **Line Switching**:
   - **Purpose**: Transitions between white and black line following modes.
   - **Implementation**: The `main` node’s automaton toggles between `White` and `Black` states based on sensor patterns.
   - **Behavior**:
     - Detects a black line intersection (high values on outer sensors, low on central) to switch from white to black.
     - Uses raw sensor values in black mode and inverted values in white mode, ensuring consistent PID processing.
   - **Significance**: Enables navigation on tracks with alternating line colors.

3. **Black Line Following**:
   - **Purpose**: Tracks a black line on a light surface.
   - **Implementation**: The `Black` state in the `main` node uses raw sensor values (black as high, white as low).
   - **Behavior**:
     - Similar to white line following, with states for `Forward`, `Goleft`, `Goright`, and `Pid`.
     - Checks for obstacles (via IR sensors) before moving forward, transitioning to `Obstacle` state if detected.
     - Detects intersections to trigger specific navigation sequences.
   - **PID**: Uses a separate `pidBlack` node with tuned parameters (`kpB`, `kiB`, `kdB`) for black line tracking.

4. **PID Control**:
   - **Purpose**: Ensures precise line tracking by adjusting motor speeds based on sensor deviations.
   - **Implementation**:
     - Two nodes: `pid` (for white lines) and `pidBlack` (for black lines).
     - Calculates error as the difference between left and right central sensors (`sen1 - sen3`).
     - Applies proportional (P), integral (I), and derivative (D) terms with constants `kp=1`, `ki=100`, `kd=15` (white) and `kpB=1`, `kiB=100`, `kdB=15` (black).
     - Outputs motor speeds (`v_l`, `v_r`) between 30 and 50, with a base speed of 40 adjusted by ±10 based on the PID output.
   - **Tuning**: Parameters are hardcoded but can be adjusted for smoother tracking.

5. **Obstacle Avoidance**:
   - **Purpose**: Bypasses obstacles detected by IR and obstacle sensors.
   - **Implementation**: The `obstacle_avoid` node uses a reactive automaton with states:
     - `FrontDetected`: Sharp right turn (speed 30, dir=45) when front IR sensors trigger.
     - `GoRight`: Moves forward with a right bias (v_l=20, v_r=50) while the obstacle is on the left.
     - `GoLeft`: Adjusts left (v_l=40, v_r=20) to clear the obstacle.
     - `Done`: Completes avoidance with a final adjustment (v_l=30, v_r=55, dir=100).
     - `BackOneLine`: Aligns with the line (v_l=50, v_r=50, dir=4) until central sensors detect it.
     - `Exit`: Stops (v_l=0, v_r=0, dir=9).
   - **Transition**: Returns to PID control when the line is redetected.

6. **Intersection Handling**:
   - **Purpose**: Navigates intersections with predefined turns based on a counter.
   - **Implementation**: The `Intersection` state in the `Black` automaton:
     - Increments a counter (`count`) at each intersection.
     - Executes:
       - Right turn (`dir=4`, speed 40) for counts 1 and 2.
       - Left turn (`dir=3`, speed 60) for counts 3 and 4.
       - Halt (`dir=0`, speed 0) for count 5.
     - Detects intersections when multiple central sensors are low (e.g., `sen[1]<500 and sen[2]<500 and sen[3]<500`).
   - **Significance**: Enables structured navigation on complex tracks.

7. **Parking**:
   - **Purpose**: Executes a parking maneuver after detecting specific conditions.
   - **Implementation**: The `Parking` state in the `Black` automaton:
     - `Start`: Follows the black line using `pidBlack` for 4 seconds, counting obstacle sensor triggers (`bound_left`, `bound_right`).
     - `Check`: Stops and evaluates sensor counts to decide the parking direction.
     - `Goleft/Goright`: Pauses for 2 seconds before parking left or right.
     - `Parkleft/Parkright`: Executes a left (v_l=63, v_r=40, dir=6) or right (v_l=40, v_r=63, dir=5) parking maneuver for 2 seconds.
     - `Final`: Stops (v_l=0, v_r=0, dir=9).
   - **Trigger**: Activated after a 2-second stop (`Stop` state) when intersections are complete.

## Requirements
- **Language**: Heptagon (synchronous programming language)
- **Compiler**: Heptagon compiler (heptc)
- **Hardware**:
  - Robot with two DC motors (left and right)
  - Five line sensors (sen0–sen4) for line tracking
  - Two IR sensors (ir_front_left, ir_front_right) for obstacle detection
  - Two obstacle sensors (obs_left, obs_right) for proximity detection
  - Microcontroller compatible with Heptagon-generated code (e.g., Arduino with C backend)
- **Operating System**: Linux/macOS/Windows (for compiling Heptagon code)
- **Dependencies**: Heptagon libraries and tools

## Setup Instructions
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/line-following-robot.git
   cd line-following-robot
   ```

2. **Install Heptagon**:
   - Follow the official Heptagon documentation to install the compiler (`heptc`).
   - Example for Ubuntu:
     ```bash
     sudo apt-get install heptagon
     ```

3. **Compile the Heptagon Code**:
   - Compile the `line_follower.ept` file to generate C code:
     ```bash
     heptc -target c line_follower.ept
     ```
   - This generates C files (e.g., `line_follower.c`) in a `c` directory.

4. **Integrate with Hardware**:
   - Link the generated C code with your robot’s microcontroller framework (e.g., Arduino).
   - Map sensor inputs (sen0–sen4, ir_front_left, ir_front_right, obs_left, obs_right) and motor outputs (v_l, v_r) to the appropriate pins.
   - Compile and upload the code to the microcontroller using the platform’s IDE (e.g., Arduino IDE).

5. **Test the Robot**:
   - Place the robot on a track with white and black lines, intersections, and obstacles.
   - Power on the robot and verify sensor readings and motor responses.

## Usage
- **Run the Robot**:
  - Deploy the compiled code on the robot.
  - Start the robot on a white line. It will:
    - Follow the white line using PID control.
    - Switch to black line mode at a horizontal black line.
    - Avoid obstacles using IR and obstacle sensors.
    - Navigate intersections with predefined turns (right at 1st/2nd, left at 3rd/4th, halt at 5th).
    - Perform a parking maneuver based on obstacle sensor counts.
  - The robot stops (`dir=9` or `dir=0`) after parking or halting.

- **Tune Parameters**:
  - Adjust PID constants (`kp`, `ki`, `kd`, `kpB`, `kiB`, `kdB`) in `line_follower.ept` for smoother line tracking.
  - Modify turn speeds (`left_turn_speed`, `right_turn_speed`) or timing values (e.g., parking duration) as needed.

- **Debugging**:
  - Use the `dir` output (1=forward, 2=PID, 3=left, 4=right, 5=park right, 6=park left, 9=stop, etc.) to monitor state transitions.
  - Log sensor values to verify line and obstacle detection.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create a feature branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -m "Add feature"`).
4. Push to the branch (`git push origin feature-name`).
5. Open a pull request.

Please include documentation and test results for new features, especially hardware-specific changes.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
