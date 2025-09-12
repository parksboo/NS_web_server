#!/bin/bash
# keepalive_nc.sh: Pipelining/keep-alive scenario
# Example: Send two requests in one connection
{
  echo -e "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: keep-alive\r\n\r\nGET /404.html HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"
} | nc localhost 8080
