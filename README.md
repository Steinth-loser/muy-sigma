
# MUY Sigma — Model Satellite Flight Software

Embedded flight software developed for the TÜRKSAT Model Satellite Competition.

The project focuses on the development of a hierarchical state machine-based control architecture running on an STM32F4 microcontroller.

As part of the competition, our team achieved a **89.2 score in the Critical Design Review (CDR)** and advanced to the stage immediately before the final.

## Project Overview

MUY Sigma is a model satellite software project developed for the TÜRKSAT Model Satellite Competition.

The software was designed around a hierarchical state machine architecture to organize the satellite's operational logic and manage transitions between different system states.

The project provided hands-on experience in embedded software architecture, state-driven system design, and the development of software for a competition-oriented aerospace system.

## Competition Achievement

| Category | Result |
|---|---|
| Competition | TÜRKSAT Model Satellite Competition |
| Microcontroller | STM32F4 |
| Software architecture | Hierarchical State Machine |
| Critical Design Review (CDR) | 89.2 |
| Competition progress | Advanced to the stage immediately before the final |

## Software Architecture

The core of the software is a **hierarchical state machine (HSM)**.

This architecture allows system behavior to be organized into states and substates, with defined transitions based on system events and conditions.

A conceptual representation of the architecture is shown below:

```text
+--------------------------------+
|       Satellite Software       |
+----------------+---------------+
                 |
                 v
+--------------------------------+
|       Top-Level State          |
+----------------+---------------+
                 |
        +--------+--------+
        |                 |
        v                 v
+---------------+ +---------------+
|   State A     | |   State B     |
+-------+-------+ +-------+-------+
        |                 |
        v                 v
+---------------+ +---------------+
|  Substates    | |  Substates    |
+---------------+ +---------------+
```

> The actual state hierarchy, state names, transition conditions, and event-handling mechanisms should be documented directly from the implementation.

## Key Features

- STM32F4-based embedded software
- Hierarchical state machine architecture
- State-driven system behavior
- Embedded C/C++ development
- Software development for a model satellite competition
- Practical experience with structured embedded system design

Additional features such as telemetry, sensor management, communication interfaces, and fault handling should be added only after they are verified in the source code.

## Hardware and Software

### Hardware

| Component | Description |
|---|---|
| Microcontroller | STM32F4 |
| Platform | Model satellite |
| Sensors | To be documented |
| Communication hardware | To be documented |
| Other subsystems | To be documented |

### Software

- C / C++
- STM32F4 development platform
- Hierarchical State Machine architecture
- Development environment: **[Add actual toolchain]**
- Additional libraries or middleware: **[Add if applicable]**

## System Behavior

The hierarchical state machine provides a structured way to represent the operational behavior of the satellite software.

Each state is responsible for a specific part of the system's behavior, while transitions determine how the system moves between operational conditions.

The following aspects should be documented according to the actual implementation:

- Top-level system states
- Nested substates
- State entry and exit behavior
- Transition conditions
- Event handling
- Error and fault states
- Interaction with hardware and communication modules

## Project Structure

The following structure is a placeholder and should be replaced with the actual repository layout:

```text
muy-sigma/
├── Core/
├── Drivers/
├── Inc/
├── Src/
├── README.md
└── ...
```

## Getting Started

### Prerequisites

- STM32F4 development board or target hardware
- Required STM32 toolchain
- Programmer/debugger
- Hardware components required by the model satellite
- **[Add any additional dependencies]**

### Build and Flash

1. Clone the repository:

   ```bash
   git clone https://github.com/Steinth-loser/muy-sigma.git
   ```

2. Open the project in the appropriate STM32 development environment.
3. Configure the target hardware and project settings.
4. Build the firmware.
5. Flash the firmware to the target board.
6. Test the implemented state machine and connected subsystems.

The exact build system and flashing procedure should be documented according to the project files.

## My Contributions

I contributed to the embedded software development of our TÜRKSAT Model Satellite Competition project.

My work included the development of a hierarchical state machine architecture on the STM32F4 platform.

The following details should be refined based on my actual responsibilities:

- Designed and implemented the hierarchical state machine.
- Developed state transitions and system behavior for **[specific operational states]**.
- Implemented **[specific embedded software modules]**.
- Worked on **[sensor handling, communication, telemetry, or other verified components]**.
- Tested and debugged the software on **[actual test environment]**.

## Competition Experience

Participating in the TÜRKSAT Model Satellite Competition provided practical experience in developing embedded software within a structured engineering and review process.

Our team achieved a **89.2 score in the Critical Design Review (CDR)** and progressed to the stage immediately before the final.

This project strengthened my experience in embedded software architecture, collaborative engineering, and the development of software for a complex system with defined operational requirements.

## Future Improvements

Potential future improvements include:

- More detailed documentation of the state hierarchy
- State transition diagrams
- Automated testing of state transitions
- Improved fault handling and diagnostics
- More comprehensive hardware-in-the-loop testing
- Documentation of system interfaces and timing requirements

## Author

**Steinth-loser**

Electrical and Electronics Engineering Student  
Interests: Embedded Systems, IoT, Robotics, and Edge AI

## License

[Add the appropriate license if applicable.]
