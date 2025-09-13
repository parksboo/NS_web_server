#!/usr/bin/env bash
set -e
PORT=${1:-9000}
base="http://127.0.0.1:$PORT"
curl -s "$base/images/apple_ex.png" -o /tmp/out.png
cmp /tmp/out.png ./www/images/apple_ex.png && echo "PNG SAME"
