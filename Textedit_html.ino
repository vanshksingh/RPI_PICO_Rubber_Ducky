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

  // Type 'TextEdit' and hit Enter
  Keyboard.print("TextEdit");
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(1000);
  Keyboard.releaseAll();

  // Open a new document in TextEdit: Command + N
  Keyboard.press(KEY_LEFT_GUI);  // Press Command
  Keyboard.press('n');           // Press N
  delay(100);
  Keyboard.releaseAll();  // Release all keys
  delay(500);

  // Toggle to Plain Text Mode in TextEdit: Command + Shift + T
  Keyboard.press(KEY_LEFT_GUI);    // Press Command
  Keyboard.press(KEY_LEFT_SHIFT);  // Press Shift
  Keyboard.press('t');             // Press T
  delay(100);
  Keyboard.releaseAll();  // Release all keys
  delay(500);

  // Type HTML content

  Keyboard.print("<!DOCTYPE html>\n<html>\n<head>\n<title>My Page</title>\n</head>\n<body>\n<h1>Hello, World!</h1>\n</body>\n</html>");
  delay(500);

  // Save the file: Command + S
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('s');
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  // Select All: Command + A
  Keyboard.press(KEY_LEFT_GUI);  // Press Command
  Keyboard.press('a');           // Press A
  delay(100);
  Keyboard.releaseAll();  // Release all keys
  delay(500);

  // Delete/Backspace
  Keyboard.press(KEY_BACKSPACE);  // Press Backspace/Delete
  delay(100);
  Keyboard.releaseAll();  // Release all keys
  delay(500);
  // Enter a unique file name and save as .html
  // Ensure the filename is unique and identifiable
  Keyboard.print(randomString);
  delay(500);

  // Save in the default location (likely the Documents folder)
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(100);

  // Press Up Arrow twice
  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  Keyboard.press(KEY_UP_ARROW);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  // Press Enter
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
  delay(500);

  // Command + Q to quit the current application
  Keyboard.press(KEY_LEFT_GUI);  // Press Command key
  Keyboard.press('q');           // Press Q key
  delay(100);
  Keyboard.releaseAll();  // Release all keys
  delay(500);

  // Use Spotlight to open the file
  // Open Spotlight
  Keyboard.press(KEY_LEFT_GUI);  // Press Command
  Keyboard.press(' ');           // Press Space
  delay(100);
  Keyboard.releaseAll();  // Release all keys
  delay(500);

  // Type the unique file name and hit Enter
  Keyboard.print(randomString);
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}
