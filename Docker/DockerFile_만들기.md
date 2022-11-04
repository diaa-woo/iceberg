# DockerFile 만들기!

```dockerfile
# syntax=docker/dockerfile:1

FROM node:12-alpine
RUN apk add --no-cache python3 g++ make
WORKDIR /app
COPY
RUN yarn install --production
CM ["node", "src/index.js"]
```