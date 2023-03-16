const { SerialPort, ReadlineParser } = require("serialport");
const port = new SerialPort({ path: "/dev/ttyUSB3", baudRate: 9600 });

const parser = port.pipe(new ReadlineParser({ delimiter: "\r\n" }));
port.on("open", () => {
  console.log("Serial port opened");
});

// port.on("data", (data) => {
//   console.log(`Received data: ${data}`);
// });

port.on("error", (err) => {
  console.error(`Error opening serial port: ${err}`);
});

port.on("close", () => {
  console.log("Serial port closed");
});

port.write("Hello from Node.js", (err) => {
  if (err) {
    console.error(`Error writing to serial port: ${err}`);
  } else {
    console.log("Data sent to serial port");
  }
});

parser.on("data", (data) => {
  console.log(`Received data (parser): ${data}`);
});

process.stdin.setEncoding("utf8");
process.stdin.on("readable", () => {
  const chunk = process.stdin.read();
  if (chunk !== null) {
    port.write("Hello");
  }
  // setInterval(() => {
  //   const pkt = ((Math.random() * 100) % 100).toString();
  //   console.log("Sent to Arduino", pkt);
  //   port.write("123");
  // }, 1000);
});

const toUno = (str) => port.write(str);
module.exports = toUno;

// setInterval(() => {
//   const pkt = Math.floor(Math.random() * 100).toString();
//   console.log("Sent to Arduino", pkt);
//   toUno(pkt);
// }, 1000);
