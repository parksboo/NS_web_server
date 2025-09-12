#!/bin/bash
# keepalive_nc.sh: 파이프라이닝/keep-alive 시나리오
# 예시: 두 요청을 한 커넥션에서 전송
{
  echo -e "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: keep-alive\r\n\r\nGET /404.html HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"
} | nc localhost 8080
