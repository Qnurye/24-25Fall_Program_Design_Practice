# 项目结构

- `build/`: 构建输出目录
- `CMakeLists.txt`: CMake 配置文件
- `config/`: 配置文件目录
- `docs/`: 文档目录
- `src/`: 源码目录
  - `controllers/`: 控制层
  - `database/`: 数据库相关
  - `main.c`: 入口文件
  - `models/`: 数据模型层
  - `views/`: 视图层
- `sql/`: SQL 脚本目录
- `.gitignore`: Git 忽略文件
- `LICENSE`: 许可证文件
- `README.md`: 项目说明文件

## 架构模式

本项目采用 [MVC 设计模式](https://zh.wikipedia.org/zh-cn/MVC)，即 Model–view–controller。

- **Model** 层是数据库的抽象实现，提供数据库与逻辑代码之间的操作方法。本项目使用 MariaDB Connector 作为驱动。
- **Controller** 层对来自 View 的交互请求进行处理，对 Model 进行操作。
- **View** 层使用 GTK 4.0 作为驱动。GTK 4.0 是跨平台库，可构建 Linux / Windows / Mac OS 应用。

# Model

参见 [数据库设计文档](./database.md)。实现数据的抽象化、 [CRUD](https://zh.wikipedia.org/zh-cn/%E5%A2%9E%E5%88%AA%E6%9F%A5%E6%94%B9) 操作方法实现，如：创建用户、选课记录、通知创建。

主要模型包括：

1. User: 用户基本信息
2. Student: 学生信息
3. Teacher: 教师信息
4. Course: 课程信息
5. Classroom: 教室信息
6. CourseSchedule: 课程安排
7. Grade: 成绩信息
8. Notification: 通知信息

每个模型都有相应的头文件和实现文件，定义了数据结构和基本的 CRUD 操作。

# Controller

控制器层应服务于视图层，实现以下功能：

1. 导入信息：用户、成绩、班级、课程信息 - [import_controller.h](../src/controllers/import_controller.h)
2. 登录：针对输入的学号和密码进行校对，并判断用户角色 - [auth_controller.h](../src/controllers/auth_controller.h)
3. 课表查询：接受学号，传出课表 - [schedule_controller.h](../src/controllers/schedule_controller.h)
4. 成绩查询：接受学号，传出成绩 - [grade_controller.h](../src/controllers/grade_controller.h)
5. 选课：接受学号，传出结果 - [course_selection_controller.h](../src/controllers/course_selection_controller.h)
6. 空教室查询：接受时间，传出列表 - [classroom_controller.h](../src/controllers/classroom_controller.h)
7. 发布通知：接受内容，传出结果 - [notification_controller.h](../src/controllers/notification_controller.h)
8. 查询通知，接受学号，传出列表 - [notification_controller.h](../src/controllers/notification_controller.h)

控制器实现方法中应包含对数据的检验、错误处理，例如：

- 登录时学号密码错误返回 null
- 传入教师学号查询成绩返回 null
- 学生发布通知返回 null

# 视图层

使用 GTK 4.0 实现用户界面：

1. 登录界面：用于用户身份验证
2. 主界面：根据用户角色（学生/教师/管理员）显示不同的功能选项
3. 课表查询界面：展示学生个人课表
4. 成绩查询界面：展示学生成绩信息
5. 选课界面：用于学生选课操作
6. 空教室查询界面：展示可用教室信息
7. 通知管理界面：
   - 教师/管理员：发布通知
   - 学生：查看通知列表
8. 信息导入界面（仅管理员可见）：用于批量导入各类信息

每个视图应与相应的控制器进行交互，实现数据的展示和用户操作的处理。视图层应注重用户体验，包括合理的布局、清晰的导航和适当的错误提示。

## 技术实现

- 使用 GTK 4.0 的 C 语言接口
- 遵循 GTK 的设计模式和最佳实践
- 合理使用布局管理器，如 GtkBox、GtkGrid 等
- 利用 GTK 的信号机制实现用户交互
- 使用 GtkCssProvider 进行界面样式定制
