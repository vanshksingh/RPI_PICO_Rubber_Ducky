#include <Keyboard.h> // The main library for sending keystrokes.

void setup() 
{
  Keyboard.begin();  // Initialise the library.
  delay(5000);       // Wait for the host to initialize (adjust time as needed).
  triggerAutomation(); // Automatically trigger the sequence.
}

void loop() 
{
  // No repeating actions required, loop can remain empty.
}

void triggerAutomation()
{
  Keyboard.press(KEY_LEFT_GUI);    // Press and hold the Command key.
  Keyboard.press(' ');             // Press and hold the space key.
  delay(100);                      // Wait for the computer to register the press.
  Keyboard.releaseAll();           // Release both of the above keys.
  delay(500);                      // Wait for Spotlight to open.
  Keyboard.print("Terminal");      // Type "Terminal".
  delay(500);                      // Give Spotlight time to search.
  Keyboard.press(KEY_RETURN);      // Press the Enter key.
  delay(100);                      // Wait for the computer to register the press.
  Keyboard.releaseAll();           // Release the Enter key.
  Keyboard.print("nc towel.blinkenlights.nl 23");
  delay(500);
  Keyboard.press(KEY_RETURN);
  delay(100);
  Keyboard.releaseAll();
}
