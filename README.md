# NS_web_server
```
http-server/
├─ src/                        # Source code (C/C++)
│  ├─ main.cc                  # Entry point: argument parsing, server start
│  ├─ http/
│  │  ├─ mime_map.cc           # Extension to MIME type mapping
│  │  ├─ request.cc            # HTTP request parsing
│  │  └─ response.cc           # HTTP response construction and error handling
│  ├─ server/
│  │  ├─ accept_loop.cc        # Listening socket creation, accept loop
│  │  ├─ server.cc             # Main server logic
│  │  └─ worker_thread.cc      # Worker thread: per-connection
│  ├─ util/
│     └─ strutil.cc            # String utility functions (trim, lower)
│
├─ include/                    # Public headers
│  ├─ server/*.h
│  ├─ http/*.h
│  └─ util/*.h
│
├─ www/                        # Document root (static files)
│
│
├─ CMakeLists.txt              
├─ Makefile                    
├─ grade.py                   
├─ .gitignore
├─ README.md
└─ LICENSE
```