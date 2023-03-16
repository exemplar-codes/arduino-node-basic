# arduino-node-basic
Sending messages to my Arduino board over local network


Steps to run:
1. Connect Arduino to the laptop
2. Open the .ino file in VScode, make sure Arduino extension by Microsoft is installed.
3. Set the board type to (Uno), and the programmer to 'AVRISP mkII'
4. Verify and upload the code.
5. Install the dependencies (`pnpm install`) and run the server using `node server.js`
6. Open the browser and go to 'localhost:3000', press the submit button.
7. Optional (if PC and another device are connected to the same "home" WiFi) going to 192.168.x.y servers the form. So any device can used to control the Arduino
The in-built LED toggles!
