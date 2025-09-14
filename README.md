# NS_web_server
```
http-server/
├─ src/                        # Source code (C/C++)
│  ├─ main.cc                  # 진입점: 인자 파싱(포트), 서버 시작/종료 처리
│  ├─ server/
│  │  ├─ accept_loop.cc        # 리스닝 소켓 생성, accept(), select()/poll() 구동
│  │  ├─ conn_manager.cc       # 각 커넥션 상태, keep-alive 타임아웃(예: 10s)
│  │  ├─ worker_thread.cc      # (선택) thread-per-conn 또는 thread pool
│  │  └─ event_select.cc       # (선택) select() 기반 다중 I/O
│  ├─ http/
│  │  ├─ request.cc            # 요청라인/헤더 파싱(GET/URI/HTTP/1.0,1.1)
│  │  ├─ response.cc           # 상태줄/헤더 조립(Content-Type/Length/Connection)
│  │  ├─ pipeline_queue.cc     # 동일 소켓에서 들어온 요청 순서 보장 큐
│  │  ├─ mime_map.cc           # 확장자→MIME 매핑(과제 표)
│  │  └─ status_codes.hh       # 200/400/403/404/405/505 등 상수/문구
│  ├─ fs/
│  │  ├─ docroot.cc            # ./www 기준 경로 결합, 디렉토리면 index.* 탐색
│  │  └─ sendfile.cc           # 파일 열기/크기(stat), partial send 루프
│  └─ util/
│     ├─ strutil.cc            # trim, to_upper 등
│     ├─ log.cc                # 간단 로거
│     └─ timer.cc              # 타임아웃 관리(마지막 활동시각)
│
├─ include/                    # Public headers
│  ├─ server/*.hh
│  ├─ http/*.hh
│  ├─ fs/*.hh
│  └─ util/*.hh
│
├─ www/                        # Document root (static files)
│  ├─ index.html
│  ├─ index.htm
│  ├─ 403.html
│  ├─ 404.html
│  ├─ assets/
│  │  ├─ img/sample.png
│  │  ├─ img/sample.jpg
│  │  ├─ css/style.css
│  │  └─ js/app.js
│  └─ favicon.ico
│
├─ tests/                      # 수동/자동 테스트 스크립트
│  ├─ smoke_curl.sh            # 200/404/헤더 확인
│  ├─ binary_cmp.sh            # 바이너리 전송 동일성 검증
│  └─ keepalive_nc.sh          # 파이프라이닝/keep-alive 시나리오
│
├─ scripts/
│  ├─ run_dev.sh               
│  └─ kill_by_port.sh
│
├─ CMakeLists.txt              # C++ 사용 시(또는 C도 가능) 빌드 스크립트
├─ Makefile                    # C 전용 간단 빌드가 필요하면 이쪽 사용
├─ .gitignore
├─ README.md
└─ LICENSE
```