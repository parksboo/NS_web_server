#!/usr/bin/env bash
set -e
PORT=${1:-9000}
base="http://127.0.0.1:$PORT"

echo "[HEADERS] index.html"
curl -sI "$base/index.html" | sed -n '1,10p'

echo "[HEADERS] wine3.jpg"
curl -sI "$base/images/wine3.jpg" | sed -n '1,10p'

echo "[HEADERS] apple_ex.png"
curl -sI "$base/images/apple_ex.png" | sed -n '1,10p'

echo "[HEADERS] exam.gif"
curl -sI "$base/images/exam.gif" | sed -n '1,10p'

echo "[HEADERS] text1.txt"
curl -sI "$base/files/text1.txt" | sed -n '1,10p'

echo "[HEADERS] welcome.html~"
curl -sI "$base/files/welcome.html~" | sed -n '1,10p'

echo "[HEADERS] welcome.html~"
curl -sI "$base/files/welcome.html~" | sed -n '1,10p'

echo "[404] notfound"
code=$(curl -s -o /dev/null -w "%{http_code}" "$base/nope.html")
echo "HTTP $code (expect 404)"

# set -e
# PORT=${1:-9000}
# base="http://127.0.0.1:$PORT"

# echo "[HEADERS] index.html"
# curl -sI "$base/index.html" | sed -n '1,10p'

# echo "[404] notfound"
# code=$(curl -s -o /dev/null -w "%{http_code}" "$base/nope.html")
# echo "HTTP $code (expect 404)"