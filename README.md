# lara-hapticnavmodel
Math Model of 5x5 Lab setup so we can test our code easily

Note: Check out the main function for some tests I ran. Currently, the printHeart() test function is the most recent, so that is a good one to check out for testing the dots class.

### Dots Class: 
#### manages the 5x5 matrix representing our setup.
- Set initial parameters so size of matrix on initialization.
- Get/Set the Unlocked column or set it to the number of columns + 1 to get all locked
- Update Dots by row just like in the real setup where only the unlocked column gets affected.
- print States function that prints the matrix. One additional factor I added was that as the number for how raised up the dot is gets higher the color changes for easy visuals. I might make a color for each possible level of the real setup.

### Motor Class: 
#### Manages all of the motors in our setup.
- Set number of motors as initialization parameter.
- Getting/Setting individual motor states.
- Adding custom "tags" to motors so basically naming what each motor is for.

### What needs to get done:
- Working on accounting for motor turns per second that implements a sort of motor curve. Accounting for spin up and spin down time for motors, and sets the motor state in real time.
- Just need to link both parts with a device class (file is made but empty as of now) that takes an input of number of motors, number of rows and columns for dots, and allows you to manipulate the dots based on motor manipulation. I am going to try to make the functions for these as close to normal accelstepper functions as possible.
