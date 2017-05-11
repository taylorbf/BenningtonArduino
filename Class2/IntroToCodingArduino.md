# Coding for Arduino: A Primer

Why learn to code? Coding is *expressive*. Code is perhaps the most powerful instrument for expression that we've ever had. As artists who express ourselves through electronics, having an intimate knowledge of our medium is tremendously important, and helps us instill our own personal creative voice in our work. At least, that's how I've always felt!



#### Reference

The [Arduino Language Reference](https://www.arduino.cc/en/Reference/HomePage) is your best friend when writing Arduino code. It contains a written description of every keyword in the Arduino programming language.

#### Background

Arduino code is a subset of Java. If you need to google a code question, you might want to add "Java" or "Arduino" to the end of your search, so that you get responses in the right language. *(Note that Java is a totally different language than Javascript.)*



## Structure: `setup()` and `loop()`

Every Arduino sketch starts here:

```java
void setup() {
  
}

void loop() {
  
}
```

[**setup**](https://www.arduino.cc/en/Reference/Setup)

The code inside the setup() function happens **once** each time the sketch starts. (The sketch starts when the arduino is plugged in, or when you upload a sketch from the Arduino IDE.)

You'll almost always want to add [Serial.begin( 9600 )](https://www.arduino.cc/en/Serial/Begin) to your setup function, for example if you want to use [Serial.println()](https://www.arduino.cc/en/Serial/Println), which is your best tool for debugging.

```java
void setup() {
  Serial.begin(9600);
}
```



[**loop**](https://www.arduino.cc/en/Reference/Loop)

The code inside the loop() function happens **over and over again**, constantly. You can slow down the loop by adding a [delay()](https://www.arduino.cc/en/Reference/Delay) somewhere in your loop.

```java
void loop() {
  Serial.println("ding");
  delay(1000);
  // this delay freezes time for 1 second
  // therefore, the loop() only happens once per second now
}
```

So the code above is literally interpreted by the Arduino as….

```java
Serial.println("ding");
delay(1000);
// wait 1 second

Serial.println("ding");
delay(1000);
// wait 1 second

Serial.println("ding");
delay(1000);
// wait 1 second

... etc etc

```





## Variable Types

**String** — a piece of text

```java
String greeting = "Hey bae";
Serial.println(greeting);
```

**Integer** — a whole number

```java
int x = 10;
Serial.println(x);
```

**Float**  — a decimal or whole number

```java
float x = 1.5;
Serial.println(x);
```

**Array** — a collection or related information

```java
int notes[] = {48, 50, 51, 53, 55, 56}; // I'm sad!
Serial.println( notes[0] ); // prints 48
Serial.println( notes[1] ); // prints 50
```



#### Why use variables?

Variables are a way to store data in descriptive shorthand words, which makes coding a lot easier to read and write.

Additionally, variables let you *work* with the data. In other words, variables are *actionable information* — information you can act on, change, transform, duplicate, etc.  

For example, if you want to take a sentence by John Cage and replace every 'a' with an 'e', you could do it:

```java
void setup() {
  Serial.begin(9600);
  String cage = "If this word music is sacred and reserved for eighteenth and nineteenth century 				instruments, we can substitute a more meaningful term: organization of sound.";
  cage.replace('e','o');
  Serial.println(cage);
}
```

A large part of learning to code is learning different methods for transforming data.





## Logic: `if`

The core logical expression in code is an [*if statement*](https://www.arduino.cc/en/Reference/Else), also called a *coditional statement*.

```java
if (value > 5) {
  // add some code inside these brackets
}
```

Here's a fuller example that you can run in your Arduino IDE and tinker with. It creates a random number, then tests to see if it is greater than or less than 5, and prints the answer to the Serial Monitor.

```java
void setup() {
  
}

void loop() { 
  int value = random(0,10);
  if (value > 5) {
    Serial.print(value);
    Serial.println(" is more than 5");
  } else {
    Serial.print(value);
    Serial.println(" is not more than 5");
  }
  delay(1000);
}
```

Some musical applications for this might be — changing the pitch of a note based on certain conditions; turning notes on or off based on certain conditions; changing the tempo based on certain conditions. 

As you start to add more sensors to your instrument, you can think about what kind of logical conditions you want to apply to each sensor to turn the sensor data into musical actions.

BTW, other common aspects of code are [loops](https://www.arduino.cc/en/Reference/For) and functions, which we won't talk about but are great for further exploration if you are interested.





## Reading and Writing pins on your board

You can read values from specific pins using [analogRead()](https://www.arduino.cc/en/Reference/AnalogRead) and [digitalRead()](https://www.arduino.cc/en/Reference/DigitalRead)

You can also send values to pins using [analogWrite()](https://www.arduino.cc/en/Reference/AnalogWrite) and [digitalWrite()](https://www.arduino.cc/en/Reference/DigitalWrite)





## Math

A lot of programming is math (often simple math), because a large amount of the data that we work with in computation is numeric.

Some useful math methods in Arduino are: 

- [random()](https://www.arduino.cc/en/Reference/Random)   which generates a random number, see reference
- round()    which rounds a value to the nearest integer

When working with sensors, its also very common to need to scale the sensor data to something musically useful. In Max, we use [scale]. In Arduino, the function is called [map]()

#### Scaling sensor data, using map()

```java
float input = analogRead(0);
float minIn = 0;
float maxIn = 1000;
float minOut = 48;
float maxOut = 60;

float scaledValue = map( input, minIn, maxIn, minOut, maxOut );

Serial.println(scaledValue);
```







## Tips

- Keep your Serial Monitor open
- Code rarely works the first time. Errors happen *all the time*. Even though they are printed in red, they are not a sign that the code is broken or bad. They are the computer's way of talking to you and telling you what line of code to work on next.
- If the code isn't acting the way you expect, use Serial.println() to print each of your variable values to the Serial Monitor. Are they what you expect? It may take putting several Serial.println() around your code before you find where things are going awry.

