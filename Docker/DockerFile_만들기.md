# DockerFile 만들기!

## 예제파일

```dockerfile
# syntax=docker/dockerfile:1

FROM node:12-alpine
RUN apk add --no-cache python3 g++ make
WORKDIR /app
COPY
RUN yarn install --production
CM ["node", "src/index.js"]
```

### 명령어

- **FROM**: 베이스 이미지, 간단히 말해 OS이다. 여기 사용되는 alpine은 매주 작은 Linux 배포판인 Alpine linux를 기반으로 하는 기본 이미지이다. `node:12-alpine`의 의미는 노드 12에 설치된 알파인 기반 이미지를 의미하며, node:alpine 사용시 최신 버전의 알파인을 사용할 수 있다.
- **RUN**: 도커 이미지가 생성되기 전에 수행할 쉘 명령어이다.
- **COPY**: Docker 클라이언트의 현재 디렉토리에서 파일을 추가한다. (COPY (source) (dist))
- **CMD**: 컨테이너 내에서 실행할 명령을 지정하며, 도커 파일 내에서 한 번만 사용할 수 있다.
  - 이미지를 실행하고 컨테이너를 생성할 때 베이스 이미지(레이어) 위에 쓰기 가능한 새 레이어("컨테이너 레이어")를 추가한다.
