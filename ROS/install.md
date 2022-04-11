1. 언어 설정
(이미 기본 영어로 설정되어 있으면 안해도 됨)

2. 소스 설정
```sh
curl -s https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | sudo apt-key add -
sudo sh -c 'echo "deb [arch=$(dpkg --print-architecture)] http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'
sudo apt update
```

3. 설치 확인 

```sh
source /opt/ros/foxy/setup.bash
ros2 run demo_nodes_cpp talker
```

4. ROS 개발 서브툴 설치

```sh
sudo apt install -y \
    build-essential \
    cmake \
    libbullet-dev \
    python3-colcon-common-extensions \
    python3-flake8 \
    python3-pip \
    python3-pytest-cov \
    python3-rosdep \
    python3-setuptools \
    python3-vcstool \
    wget 

python3 -m pip install -U \
    argcomplete \
    flask8-blind-except \
    python3 -m pip install -U \
    argcomplete \
    flake8-blind-except \
    flake8-builtins \
    flake8-class-newline \
    flake8-comprehensions \
    flake8-deprecated \
    flake8-docstrings \
    flake8-import-order \
    flake8-quotes \
    pytest-repeat \
    pytest-rerunfailures \
    pytest

```

5. Run command 설정
```bash
source /opt/ros/foxy/setup.bash
source ~/study/Dia_study/ROS/practice/install/local_setup.bash

source /usr/share/colcon_argcomplete/hook/colcon-argcomplete.bash
source /usr/share/vcstool-completion/vcs.bash
source /usr/share/colcon_cd/function/colcon_cd.sh
export _colcon_cd_root = ~/study/Dia_study/ROS/practice/

export RMW_IMPLEMENTATION=rmw_fastrtps_cpp
# export RMW_IMPLEMENTATION=rmw_connext_cpp
# export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
# export RMW_IMPLEMENTATION=rmw_gurumdds_cpp

# export RCUTILS_CONSOLE_OUTPUT_FORMAT='[{severity} {time}] [{name}]: {message} ({function_name}() at {file_name}:{line_number})'
export RCUTILS_CONSOLE_OUTPUT_FORMAT='[{severity}]: {message}'
export RCUTILS_COLORIZED_OUTPUT=1
export RCUTILS_LOGGING_USE_STDOUT=0
export RCUTILS_LOGGING_BUFFERED_STREAM=0

alias cw='cd ~/study/Dia_study/ROS/practice'  # personel root(You should be change!)
alias cw='cd ~/study/Dia_study/ROS/practice/src'  # personel root(You should be change!)
alias ccd='colcon_cd'

alias cb='cd ~/study/Dia_study/ROS/practice && colcon build --symlink-install'  # personel root(You should be change!)
alias cbs='colcon build --symlink-install'
alias cbp='colcon build --symlink-install --packages-select'
alias cbs='colcon build --symlink-install --packages-up-to'
alias ct='concon test',
alias ctp='colcon test --packages-select'
alias ctr='colcon test-result'

alias rt='ros2 topic list'
alias re='ros2 topic echo'
alias rn='ros2 node list'

alias killgazebo='killall -9 gazebo & killall -9 gzserver & killall -9 gzclient'

alias af='ament_flake8'
alias ac='ament_cpplint'

alias testpub='ros2 run demo_nodes_cpp talker'
alias testsub='ros2 run demo_nodes_cpp listener'
alias testpubimg='ros2 run image_tools cam2image'
alias testsubimg='ros2 run image_tools showimage'

```

6. vscode extensions 설치
   
C & Python
 - C/C++ : 기본 IntelliSense
 - CMake: CMake 언어 지원
 - CMake Tools: CMake 툴들
 - Python: IntelliSense, 디버깅,린팅 등 가능

ROS Extensions
 - ROS: ROS 개발 지원
 - URDF: URDF/xarco 지원
 - Colcon Tasks: Colcon 명령어를 위한 VSCode Task

File Format Extensions
 - XML Tools
 - YAML
 - Markdown All is One

ETC
 - Highlight Trailing White Spaces: 불필요한 White Spaces 감지
 - EOF Mark: 코드의 끝을 알려줌
 - Bracket Pair Colorizer: 괄호 열기/닫기를 짝을 맞추어 색상화시킴
 - Better Comments: alert, informational, TODO 등의 코멘트 강화 기능
 
7. 개발 환경 세팅

User Settings (path: ~/.config/Code/User/settings.json)

```JSON
{
    "files.associations": {
            "*.repos": "yaml",
            "*.world": "xml",
            "*.xacro": "xml"
    },
    "ros.distro": "foxy",
    "colcon.provideTasks": true
}
```

c_cpp_properties.json

```JSON
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${default}",
                "${workspaceFolder}/**",
                "/opt/ros/foxy/include/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/g++",
            "cStandard": "c99",
            "cppStandard": "c++14",
            "intelliSenseMode": "linux-clang-x64"
        }
    ],
    "version": 4
}
```

tasks.json

```JSON
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "colcon: build",
            "type": "shell",
            "command": "colcon build --cmake-args '-DCMAKE_BUILD_TYPE=Debug'",
            "problemMatcher": [],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        },
        {
            "label": "colcon: test",
            "type": "shell",
            "command": "colcon test && colcon test-result"
        },
        {
            "label": "colcon: clean",
            "type": "shell",
            "command": "rm -rf build install log"
        }
    ]
}
```

launch.json(program의 경로는 바꿔줘야함!)

```JSON
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug-rclpy(debugpy)",
            "type": "python",
            "request": "launch",
            "program": "${file}",
            "console": "integratedTerminal"
        },
        {
            "name": "Debug-rclcpp(gdb)",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceRoot}/ROS/practice/install/${input:package}/lib/${input:package}/${input:node}", 
            "args": [],
            "preLaunchTask": "colcon: build",
            "stopAtEntry": true,
            "cwd": "${workspaceFolder}",
            "externalConsole": false,
            "MIMode": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ],
    "inputs": [
        {
            "id": "package",
            "type": "promptString",
            "description": "package name",
            "default": "topic_service_action_rclcpp_example"
        },
        {
            "id": "node",
            "type": "promptString",
            "description": "node name",
            "default": "argument"
        }
    ]
}
```