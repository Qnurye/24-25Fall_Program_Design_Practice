# 24-25Fall_Program_Design_Practice

2024-2025 年程序设计实训

## 功能特性

- 用户登录（学生、教师、管理员）
- 学生功能：
  - 查询个人信息
  - 查询成绩
  - 查询通知
- 教师功能：
  - 查询信息
  - 上传成绩
  - 发布通知
- 管理员功能：
  - 导入学生信息
  - 导入教师信息
  - 显示所有学生信息
  - 显示所有教师信息
  - 清空学生信息
  - 清空教师信息

## 技术栈

- 编程语言：C
- 构建工具：CMake

## 如何运行

1. 确保你的系统已安装 CMake 和 C 编译器。
2. 克隆此仓库：
   ```
   git clone https://github.com/Qnurye/24-25Fall_Program_Design_Practice.git
   ```
3. 进入项目目录：
   ```
   cd 24-25Fall_Program_Design_Practice
   ```
4. 创建构建目录并进入：
   ```
   mkdir build && cd build
   ```
5. 运行 CMake：
   ```
   cmake ..
   ```
6. 编译项目：
   ```
   cmake --build .
   ```
7. 运行程序：
   ```
   ./Var4
   ```

## 开发

关于项目的更多信息详见 [开发文档](./docs/DEVELOPMENT.md)。

## 许可证

本项目采用 MIT 许可证。详情请见 [LICENSE](LICENSE) 文件。
