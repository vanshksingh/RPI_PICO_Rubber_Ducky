#include <Keyboard.h>
#include <Arduino.h>

String randomString;  // Global variable declaration

// Function to generate a random alphanumeric string
String generateRandomString(int length) {
  const char alphanum[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  String result = "";

  for (int i = 0; i < length; ++i) {
    result += alphanum[random(62)];  // random index into alphanum
  }

  return result;
}

void setup() {
  Keyboard.begin();

  // Use an unconnected analog pin to generate a random seed.
  // Make sure the pin A0 (or any other analog pin) is not connected to anything.
  randomSeed(analogRead(A0));

  // Generate a random string of length 10 and add .html extension
  randomString = generateRandomString(10) + ".html";

  delay(5000);
  triggerAutomation();
}


void loop() {
  // No repeating actions required, loop can remain empty.
}

void triggerAutomation() {
  // Open Spotlight
  Keyboard.press(KEY_LEFT_GUI);  // Press Command
  Keyboard.press(' ');           // Press Space
  delay(100);
  Keyboard.releaseAll();  // Release all keys
  delay(500);

  // Type 'Terminal' and hit Enter
  Keyboard.print("Terminal");
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(1000);
  Keyboard.releaseAll();

  // Wait for Terminal to open
  delay(500);

  // Press Command + n
Keyboard.press(KEY_LEFT_GUI);  // Press the Command (GUI) key
Keyboard.press('n');           // Press the 'o' key
delay(100);                    // Short delay to ensure the keystroke is registered
Keyboard.releaseAll();         // Release all keys

// Wait for Terminal to open
  delay(800);

  // Command to create HTML file
  Keyboard.print("echo '<!DOCTYPE html>\n<html>\n<head>\n<title>Rubber Ducky</title>\n</head>\n<body>\n<h1>This is too easy!</h1>\n</body>\n</html>' > ~/Documents/");
  Keyboard.println(randomString);
  delay(500);

  // Run the command to create the file
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

  // Command to open the file
  Keyboard.print("open ~/Documents/");
  Keyboard.println(randomString);
  delay(500);

  // Run the command to open the file
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(1000);

 
}
