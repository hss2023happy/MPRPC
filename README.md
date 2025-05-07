# MPRPC Project
# mprpc - 基于 Muduo 的轻量级 RPC 框架

## 项目简介

`mprpc` 是一个基于 [Muduo](https://github.com/chenshuo/muduo) 网络库构建的高性能、轻量级远程过程调用（RPC）框架，支持多线程、高并发和服务注册发现功能。项目使用了 [Boost 1.75.0](https://www.boost.org/) 提供的序列化功能以及 [Zookeeper 3.4.10](https://zookeeper.apache.org/) 实现服务注册与发现。

项目中包含一键构建脚本 `autobuild.sh`，便于快速搭建和部署运行环境。

---

## 主要特性

- 支持 TCP 长连接传输协议
- 使用 Protobuf 定义接口
- 支持多线程并发处理
- 基于 Zookeeper 的服务注册与发现机制
- 简洁的接口调用方式
- 模块化设计，便于扩展

---

## 项目结构
mprpc/
├── autobuild.sh # 一键构建脚本|
├── src/ # 核心框架代码|
│ ├── mprpcconfig.h # 配置模块|
│ ├── rpcprovider.h # RPC 服务端实现|
│ ├── rpcconsumer.h # RPC 客户端实现|
│ └── ...|
├── example/ # 示例代码（服务端、客户端）|
├── proto/ # Protobuf 接口定义文件|
├── CMakeLists.txt # 构建配置文件|
└── README.md # 项目说明|


---

## 📦 依赖说明

以下依赖需提前安装并配置好环境：

| 依赖库     | 版本        | 说明                         |
|------------|-------------|------------------------------|
| Boost      | 1.75.0      | 智能指针、bind 等工具模块    |
| Muduo      | 最新版建议  | 高性能 C++ 网络库            |
| Zookeeper  | 3.4.10      | 服务注册中心                 |
| Protobuf   | 3.x         | 接口定义和序列化             |
| CMake      | ≥ 3.10      | 项目构建工具                 |
| GCC/G++    | ≥ 7.0       | 支持 C++11 标准              |

---

### 安装示例（Ubuntu）

```bash
sudo apt update
sudo apt install libboost-all-dev cmake protobuf-compiler libprotobuf-dev

```
## 🛠️ 编译方式

项目提供一键构建脚本：

```bash
chmod +x autobuild.sh
./autobuild.sh

```

