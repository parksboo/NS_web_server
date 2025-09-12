#!/bin/bash
# kill_by_port.sh: Kill process on specified port
PORT=$1
if [ -z "$PORT" ]; then
  echo "Usage: $0 <port>"; exit 1
fi
PID=$(lsof -ti tcp:$PORT)
if [ -n "$PID" ]; then
  kill -9 $PID
  echo "Killed process on port $PORT" 
else
  echo "No process found on port $PORT"
fi
