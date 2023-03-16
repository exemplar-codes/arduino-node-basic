const http = require("node:http");

const toUno = require("./app");

const server = http.createServer((req, res) => {
  if (req.method === "POST") {
    req.on("data", (chunk) => {
      const pkt = chunk.toString()?.split("=")[1];

      toUno(pkt || "test");

      console.log("POST here <<<<<<");
    });
  }

  res.statusCode = 200;
  res.setHeader("Content-Type", "text/html");
  res.end(
    `<form method="POST" action="/form"><input type="text" value="toggle" name="ardip" placeholder="Enter" /><br /><input type="submit" /></form>`
  );
});

const port = process.env.PORT || 3000;
server.listen(port, () => console.log(`Server running on port ${port}`));
