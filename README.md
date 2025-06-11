# Basic Server in C

A minimal HTTP server written in C using low-level socket programming. The server listens on port 80, accepts connections, parses incoming GET requests, and responds with a static HTML file.

## 🚀 Features

- Handles HTTP GET requests
- Sends basic HTTP headers and serves static HTML (`home.html`)
- Built using standard POSIX sockets
- Modular code design with `Server.h`, `server.c`, and `test.c`
- Easy to extend for additional routes or file types

---

## 🗂️ Project Structure
.<br>
├── Server.h # Definition of the Server struct and constructor <br>
├── server.c # Implementation of the server setup <br>
├── test.c # Launch logic and response handling <br>
└── home.html # Webpage served to the browser <br>

---

## 🔧 How to Run
### 🧱 Prerequisites
- A Linux-based system or WSL on Windows
- Root permissions (port 80 requires it)

### 📦 Compile
```bash
gcc server.c test.c -o server
```
### ▶️ Run
```bash
sudo ./server
```
Then open a browser and go to:
```
http://localhost
```
You should see your HTML file rendered, and the HTTP request will be printed in your terminal.

## 🧩 Notes

- Ensure `home.html` is in the same directory as the compiled binary to be properly served.
- Port 80 requires elevated privileges, so running the server typically needs `sudo`.
- This server handles one request at a time in a blocking manner and does not support concurrency.
- The implementation assumes simple GET requests and does not support other HTTP methods or headers.
- Designed purely for educational and experimental purposes — not intended for production environments.
- Press `Ctrl + C` to stop the server.

---

## 📚 Learning Goals

This project serves as a foundational learning experience in:

- Creating and managing TCP sockets using the Berkeley Sockets API.
- Setting up a listening server socket to accept client connections.
- Reading HTTP requests from clients and sending properly formatted HTTP responses.
- Structuring a C project using modular design (with headers and source files).
