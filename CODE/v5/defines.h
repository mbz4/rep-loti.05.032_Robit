

#ifndef DEFINES_H_
#define DEFINES_H_

#define PIN_ENABLE_MOTORS 12   
     
#define PIN_MOTOR1_DIR 27    
#define PIN_MOTOR1_STEP 14    
#define PIN_MOTOR2_DIR 25    
#define PIN_MOTOR2_STEP 26

// NORMAL MODE PARAMETERS (MAXIMUM SETTINGS)
#define MAX_THROTTLE 550
#define MAX_STEERING 140
#define MAX_TARGET_ANGLE 14 // og = 14

// PRO MODE = MORE AGGRESSIVE (MAXIMUM SETTINGS)
#define MAX_THROTTLE_PRO 780   // Max recommended value: 860
#define MAX_STEERING_PRO 260   // Max recommended value: 280
#define MAX_TARGET_ANGLE_PRO 26   // Max recommended value: 32

// Default control terms for
#define KP 0.32 // og = 0.32
#define KD 0.050 // og = 0.05
#define KP_THROTTLE 0.080 // og = 0.08
#define KI_THROTTLE 0.0 //og = 0.1
#define KP_POSITION 0.06 // og = 0.06
#define KD_POSITION 0.45 // og = 0.45
//#define KI_POSITION 0.02

// Control gains for raiseup (the raiseup movement requiere special control parameters)
#define KP_RAISEUP 0.1
#define KD_RAISEUP 0.16
#define KP_THROTTLE_RAISEUP 0   // No speed control on raiseup
#define KI_THROTTLE_RAISEUP 0.0

#define MAX_CONTROL_OUTPUT 500
#define ITERM_MAX_ERROR 30   // Iterm windup constants for PI control
#define ITERM_MAX 10000

#define ANGLE_OFFSET 0.0  // Offset angle for balance (to compensate robot own weight distribution) | og = 0.0

#define ZERO_SPEED 0xffffff
#define MAX_ACCEL 14      // Maximum motor acceleration (MAX RECOMMENDED VALUE: 20) (default:14)

#define MICROSTEPPING 8   // 8 or 16 for 1/8 or 1/16 driver microstepping (default:16)
#define SPEED_FACTOR_8_STEPPING 4 // for 1/8 Microstepping, og = 25 | SPEED_FACTOR_8_STEPPING

// AUX definitions
#define CLR(x,y) (x&=(~(1<<y)))
#define SET(x,y) (x|=(1<<y))
#define RAD2GRAD 57.2957795
#define GRAD2RAD 0.01745329251994329576923690768489

#endif /* DEFINES_H_ */
