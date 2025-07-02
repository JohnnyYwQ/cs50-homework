FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# 安装基础工具 + C 编译 + Python + SQLite + Git + curl
RUN apt update && apt install -y \
    gcc make git \
    python3 python3-pip ipython3 \
    sqlite3 curl vim ca-certificates

# 安装 Node.js（使用官方 NodeSource 安装脚本，支持 ARM 架构）
RUN curl -fsSL https://deb.nodesource.com/setup_18.x | bash - && \
    apt install -y nodejs

# 安装 Flask 和 Web 相关 Python 库
RUN pip3 install \
    flask flask-session flask-sqlalchemy jinja2 requests

# 安装 CS50 C 库（源码编译）
RUN git clone https://github.com/cs50/libcs50 && \
    cd libcs50 && make && make install && cd .. && rm -rf libcs50

# 设置工作目录
WORKDIR /workspace