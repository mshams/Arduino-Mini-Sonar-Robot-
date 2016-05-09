Arduino, Mini Sonar Robot

Related project on instructables: http://www.instructables.com/id/Arduino-Mini-Sonar-Robot/

Related blog post (persian): http://www.mshams.ir/blogs/1393/08/%D8%B7%D8%B1%D8%A7%D8%AD%DB%8C-%D8%B1%D9%88%D8%A8%D8%A7%D8%AA-%D8%AA%D8%B4%D8%AE%DB%8C%D8%B5-%D9%85%D9%88%D8%A7%D9%86%D8%B9-%D8%A8%D8%A7-%D8%B3%D9%86%D8%B3%D9%88%D8%B1-%D9%85%D8%A7%D9%81%D9%88%D9%82


In this project I want to make a mini-sonar robot with arduino pro mini. Sonar or ultrasonic sensors work on a principle similar to radar or sonar, which evaluate attributes of a target by interpreting the echoes from radio or sound waves respectively. Active ultrasonic sensors generate high frequency sound waves and evaluate the echo which is received back by the sensor, measuring the time interval between sending the signal and receiving the echo to determine the distance to an object.
I've used a HC-SR04 sensor which is one of the cheapest price in this type. It has 4 pins Vcc 5V, Gnd and two other pins for trigger (out) and echo (in). The mechanism is simple, some wave triggers, the echo receives.

Needed parts:

    1x Arduino Pro mini
    1x Sonar sensor SR-04 (low price)
    2x Two-wheels gearbox pack + dc motor 3V~6V
    4x Plastic wheels
    1x Plastic box (depends on gearbox size)
    2x Double Battery pack AA
    4x Battery AA (Rechargeable is suggested)
    1x Mini speaker
    1x LED
    1x Resistor 470 ohm
    1x L293D IC
    1x IC Socket 16 pins
    2x Pin header (both F & M type)
    1x Mini switch
    1x Fiber board Wires + Soldering iron + cutting pliers + Superglue

Let me start the project with mechanical structure.


Step 1: Robot Body

Find a plastic box depend on the size of the gearbox pack. I've used an earphone box (2 pieces). Use the superglue to attach the parts as shown in the image.


Step 2: Circuit

Make the circuit as mentioned in the image. Someone may wants to depart the power supply of the motor and the logic (micro, ic, ...).

Actually it's recommended to have separate power supplies for the logic and high consuming part (electromechanical devices like as motors), but I think it's not so important for the low power arduino like as Pro-mini. At the other hand, having just 4 batteries, you can't do any other approach.

Step 3: Code

I've tried to write the code easy enough to be plain for the beginners too. But if you have any problems, questions and may suggestions, I like to know.
Some hints:

    Minimum distance is the stopping distance to prevent crash. The best distance from any block to stop the robot, is depends on the gearbox speed.
    Robot comes back to max distance.
    backDist and turnDist should be customized depend on the robot speed.
    A random behavior including a stop, melody and random movement has used.