# 开发文档

## 项目结构

- `src/`: 源代码文件
    - `models/`: 数据模型
    - `views/`: 视图
    - `controllers/`: 控制器
    - `main.c`: 主函数
- `include/`: 头文件
- `docs/`: 文档
- `data/`: 数据文件
- `README.md`: 项目说明
- `CMakeLists.txt`: CMake 配置文件

## 架构模式

本项目采用 [MVC 设计模式](https://zh.wikipedia.org/zh-cn/MVC)，即 Model–view–controller。

- **Model** 层定义了数据结构和数据操作函数。
- **View** 层定义了用户界面和用户交互。
- **Controller** 层连接了 Model 和 View，负责处理用户输入和输出。

## 模型层

模型层包含以下主要文件：

- `student.c/h`: 学生数据模型
- `teacher.c/h`: 教师数据模型
- `administrator.c/h`: 管理员数据模型

每个模型都包含相应的数据结构和操作函数，如添加、查找、导入、导出等。

## 视图层

视图层包含以下主要文件：

- `student.c/h`: 学生相关视图
- `teacher.c/h`: 教师相关视图
- `administrator.c/h`: 管理员相关视图
- `login.c/h`: 登录相关视图

这些文件负责显示用户界面和处理用户交互。

## 控制器层

控制器层主要包含：

- `login.c/h`: 处理登录逻辑

控制器负责协调模型和视图，处理用户输入并更新相应的模型和视图。

## 数据存储

用户数据存储在文本文件中：

- `students.txt`: 学生数据
- `teachers.txt`: 教师数据
- `administrators.txt`: 管理员数据

## 主要功能

1. 用户登录（学生、教师、管理员）
2. 学生功能：查询个人信息、查询成绩、查询通知
3. 教师功能：查询信息、上传成绩、发布通知
4. 管理员功能：导入 / 显示 / 清空学生和教师信息

## 编译和运行

使用 CMake 进行项目构建。详细步骤请参考 README.md 文件。

## 注意事项

当前用 txt 存数据，数据文件位于 `data/` 目录下。之后可能改进，作为特色点。
