drop table if exists course_enrollment cascade;

drop table if exists course_schedule cascade;

drop table if exists classrooms cascade;

drop table if exists grades cascade;

drop table if exists courses cascade;

drop table if exists notifications cascade;

drop table if exists students cascade;

drop table if exists classes cascade;

drop table if exists teachers cascade;

drop table if exists timetable cascade;

drop table if exists users cascade;


CREATE TABLE users
(
    user_id    INT PRIMARY KEY AUTO_INCREMENT,
    password   VARCHAR(255)                NOT NULL,
    sid        VARCHAR(10)                 NOT NULL, -- student / staff id； 学 / 工号
    role       ENUM ('teacher', 'student') NOT NULL,
    name       VARCHAR(100)                NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE teachers
(
    teacher_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id    INT NOT NULL,
    department VARCHAR(100), -- 所属院系
    title      VARCHAR(50),  -- 职称
    FOREIGN KEY (user_id) REFERENCES users (user_id) ON DELETE CASCADE
);

CREATE TABLE classes
(
    class_id   INT PRIMARY KEY AUTO_INCREMENT,
    department VARCHAR(100), -- 所属院系
    major      VARCHAR(100)  -- 专业
);

CREATE TABLE students
(
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id    INT NOT NULL,
    class_id   INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users (user_id) ON DELETE CASCADE,
    FOREIGN KEY (class_id) REFERENCES classes (class_id) ON DELETE CASCADE
);

CREATE TABLE classrooms
(
    classroom_id   INT PRIMARY KEY AUTO_INCREMENT,
    classroom_name VARCHAR(50) NOT NULL, -- 教室名
    capacity       INT,                  -- 容量
    is_available   BOOLEAN DEFAULT TRUE  -- 是否空闲
);

CREATE TABLE timetable
(
    lesson_id INT PRIMARY KEY AUTO_INCREMENT,
    start_at  TIME NOT NULL,
    end_at    TIME NOT NULL
);

CREATE TABLE courses
(
    course_id   INT PRIMARY KEY AUTO_INCREMENT,
    course_name VARCHAR(100) NOT NULL, -- 课程名称
    course_code VARCHAR(20) UNIQUE,    -- 课程代码
    credits     INT,                   -- 学分
    department  VARCHAR(100),          -- 所属院系
    teacher_id  INT,                   -- 教师 id
    FOREIGN KEY (teacher_id) REFERENCES teachers (teacher_id) ON DELETE SET NULL
);

CREATE TABLE course_schedule
(
    schedule_id     INT PRIMARY KEY AUTO_INCREMENT,
    course_id       INT                                                    NOT NULL, -- 课程 id
    classroom_id    INT                                                    NOT NULL,
    classroom       VARCHAR(50),                                                     -- 教室
    day_of_week     ENUM ('Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun') NOT NULL, -- 星期几
    start_lesson_id INT                                                    NOT NULL, -- 开始时间
    end_lesson_id   INT                                                    NOT NULL, -- 结束时间
    FOREIGN KEY (course_id) REFERENCES courses (course_id) ON DELETE CASCADE,
    FOREIGN KEY (classroom_id) REFERENCES classrooms (classroom_id) ON DELETE CASCADE,
    FOREIGN KEY (start_lesson_id) REFERENCES timetable (lesson_id) ON DELETE CASCADE,
    FOREIGN KEY (end_lesson_id) REFERENCES timetable (lesson_id) ON DELETE CASCADE
);

CREATE TABLE grades
(
    grade_id           INT PRIMARY KEY AUTO_INCREMENT,
    student_id         INT NOT NULL,                        -- 学生 id
    course_id          INT NOT NULL,                        -- 课程 id
    regular_grade      DECIMAL(5, 2),                       -- 平时分
    final_grade        DECIMAL(5, 2),                       -- 期末分
    regular_percentage DECIMAL(5, 2),                       -- 平时分占比，单位 `%`
    graded_at          TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- 成绩录入时间
    FOREIGN KEY (student_id) REFERENCES students (student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES courses (course_id) ON DELETE CASCADE
);

CREATE TABLE course_enrollment
(
    enrollment_id   INT PRIMARY KEY AUTO_INCREMENT,
    student_id      INT NOT NULL,                        -- 学生 id
    course_id       INT NOT NULL,                        -- 课程 id
    enrollment_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- 选课时间
    FOREIGN KEY (student_id) REFERENCES students (student_id) ON DELETE CASCADE,
    FOREIGN KEY (course_id) REFERENCES courses (course_id) ON DELETE CASCADE
);

CREATE TABLE notifications
(
    notification_id INT PRIMARY KEY AUTO_INCREMENT,
    title           VARCHAR(200) NOT NULL,               -- 通知标题
    content         TEXT         NOT NULL,               -- 通知内容
    teacher_id      INT          NOT NULL,               -- 发布通知的教师 id
    class_id        INT          NOT NULL,               -- 通知接受行政班级
    created_at      TIMESTAMP DEFAULT CURRENT_TIMESTAMP, -- 通知发布时间
    FOREIGN KEY (teacher_id) REFERENCES teachers (teacher_id) ON DELETE CASCADE,
    FOREIGN KEY (class_id) REFERENCES classes (class_id) ON DELETE CASCADE
);
