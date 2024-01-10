# 📡 minitalk

## 👋 Welcome to the World of Process Communication!
Hello and welcome to `minitalk`! This project is all about diving into the fascinating world of process communication in C. Ever wondered how processes talk to each other? You're about to find out!

## 🌟 The Mission
`minitalk` is our journey into inter-process communication (IPC) using UNIX signals. Your mission is to create a server and a client that can chat using these signals. It's a fantastic opportunity to explore how processes interact in the world of UNIX.

## 🛠️ Getting Ready
Make sure you're familiar with basic C programming, and it helps if you've had a little exposure to UNIX/Linux systems. Knowing about signals and process control would be a huge plus!

## 🚀 How to Get Started
To get your hands on `minitalk`:
```bash
git clone https://github.com/daanmlab/minitalk.git
```
Navigate to the project directory and compile the server and client:
```bash
make
```
This will create two executables, `server` and `client`.

## 📖 Inside minitalk
`minitalk` includes two main components:
1. **Server**: Waits for messages from the client.
2. **Client**: Sends messages to the server using UNIX signals.

## 📋 Example Usage
Start the server to get its PID:
```bash
./server
```
Then, use the client to send a message:
```bash
./client [server PID] "Hello, minitalk!"
```
The server should display the message sent by the client.
---
