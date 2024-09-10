# 项目结构

- `build/`: 构建输出目录
- `CMakeLists.txt`
- `config/`: 配置
- `docs/`: 文档
- `include/`: 公共接口
- `lib/`: 第三方库或外部依赖
- `src/`: 源码
	- `controllers/`: 控制层
	- `database/`: 数据库相关
	- `main.c`: 入口文件
	- `models/`: 数据模型层
	- `utils/`: 工具方法
	- `views/`: 视图层
- `tests/`: 单元测试

## 架构模式

本项目采用 [MVC 设计模式](https://zh.wikipedia.org/zh-cn/MVC)，即 Model–view–controller。

- **Model** 层是数据库的抽象实现，提供数据库与逻辑代码之间的操作方法。本项目使用 MariaDB Connector 作为驱动。
- **Controller** 层对来自 View 的交互请求进行处理，对 Model 进行操作。
- **View** 层使用 GTK 4.0 作为驱动。GTK 4.0 是跨平台库，可构建 Linux / Windows / Mac OS 应用。

# Model

参见 [数据库设计文档](./database.md)。实现数据的抽象化、 [CRUD](https://zh.wikipedia.org/zh-cn/%E5%A2%9E%E5%88%AA%E6%9F%A5%E6%94%B9) 操作方法实现，如：创建用户、选课记录、通知创建。

# Controller

控制器层应服务于视图层，实现以下功能：

1. (数据处理)
	1. 导入信息：用户、成绩、班级、课程信息
2. 登录：针对输入的学号和密码进行校对，并判断用户角色
3. 课表查询：接受学号，传出课表
4. 成绩查询：接受学号，传出成绩
5. 选课：接受学号，传出结果
6. 空教室查询：接受时间，传出列表
7. 发布通知：接受内容，传出结果
8. 查询通知，接受学号，传出列表

控制器实现方法中应包含对数据的检验、错误处理，例如：

- 登录时学号密码错误返回 null
- 传入教师学号查询成绩返回 null
- 学生发布通知返回 null

# 视图层

使用 GTK 4.0。
