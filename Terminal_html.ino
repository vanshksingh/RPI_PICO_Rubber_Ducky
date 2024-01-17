

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

  delay(500);
}


void loop() {
  if (BOOTSEL) {
    triggerAutomation();
    while (BOOTSEL);
  }
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
  Keyboard.print("echo '<!DOCTYPE html>\\n");
  Keyboard.print("<html>\\n");
  Keyboard.print("<head>\\n");
  Keyboard.print("<title>Page Title</title>\\n");
  Keyboard.print("<style>\\n");
  Keyboard.print("body {\\n");
  Keyboard.print("display: flex;\\n");
  Keyboard.print("align-items: center;\\n");
  Keyboard.print("justify-content: center;\\n");
  Keyboard.print("font-family: Arial, sans-serif;\\n");
  Keyboard.print("line-height: 1.8;\\n");
  Keyboard.print("min-height: 100vh;\\n");
  Keyboard.print("background: #ffffff;\\n");
  Keyboard.print("flex-direction: column;\\n");
  Keyboard.print("}\\n");
  Keyboard.print(".main {\\n");
  Keyboard.print("background-color: #fff;\\n");
  Keyboard.print("border-radius: 15px;\\n");
  Keyboard.print("box-shadow: 0 0 20px rgba(0, 0, 0, 0.2);\\n");
  Keyboard.print("padding: 20px;\\n");
  Keyboard.print("transition: transform 0.2s;\\n");
  Keyboard.print("width: 600px;\\n");
  Keyboard.print("}\\n");
  Keyboard.print("form {\\n");
  Keyboard.print("display: flex;\\n");
  Keyboard.print("align-items: center;\\n");
  Keyboard.print("justify-content: center;\\n");
  Keyboard.print("flex-direction: column;\\n");
  Keyboard.print("}\\n");
  Keyboard.print("h1 {\\n");
  Keyboard.print("text-align: center;\\n");
  Keyboard.print("color: red;\\n");
  Keyboard.print("}\\n");
  Keyboard.print("input {\\n");
  Keyboard.print("padding: 10px;\\n");
  Keyboard.print("}\\n");
  Keyboard.print("</style>\\n");
  Keyboard.print("</head>\\n");
  Keyboard.print("<body>\\n");
  Keyboard.print("<div class='main'>\\n");
  Keyboard.print("<h1>Welcome To Rubber Ducky</h1>\\n");
  Keyboard.print("<form>\\n");
  Keyboard.print("<p>\\n");
  Keyboard.print("<label>Username :\\n");
  Keyboard.print("<input type='text' /></label>\\n");
  Keyboard.print("</p>\\n");
  Keyboard.print("<p>\\n");
  Keyboard.print("<label>Password :\\n");
  Keyboard.print("<input type='password' /></label>\n");
  Keyboard.print("</p>\n");
  Keyboard.print("<p>\n");
  Keyboard.print("<button type='submit'>Submit</button>\n");
  Keyboard.print("</p>\n");
  Keyboard.print("</form>\n");
  Keyboard.print("</div>\n");
  Keyboard.print("</body>\n");
  Keyboard.print("</html>' > ~/Documents/");


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
