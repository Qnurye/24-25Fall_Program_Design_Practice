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
