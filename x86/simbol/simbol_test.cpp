//
// Created by toohoo on 16/5/2020.
//
/*
 * 词法记号标签
 */
enum Tag{
    ERR,                                // 错误，异常
    END,                                // 文件结束标志
    ID,                                 // 标识符
    KW_INT, KW_CHAR, KW_VOID,           // 数据类型
    KW_EXTERN,                          // extern
    NUM, CH, STR,                       // 常量
    NOT, LEA,                           // 单目运算 ! & - *
    ADD, SUB, MUL, DIV, MOD,            // 算术运算符
    INC, DEC,                           // 自加自减
    GT, GE, LT, LE, EQU, NEQU,          // 比较运算符
    AND, OR,                            // 逻辑运算符
    LPAREN, RPAREN,                     // ()
    LBRACK, RBRACK,                     // []
    LBRACE, RBRACE,                     // {}
    COMMA, COLON, SEMICON,              // 逗号，冒号，分号
    ASSIGN,                             // 赋值
    KW_IF, KW_ELSE,                     // if-else
    KW_SWITCH, KW_CASE, KW_DEFAULT,     // swicth-case-deault
    KW_WHILE, KW_DO, KW_FOR,            // 循环
    KW_BREAK, KW_CONTINUE, KW_RETURN    // break, continue, return
};

/*
 * 词法记号类
 */
class Token{
public:
    Tag tag;
    Token (Tag t);                      // 构造函数
    virtual string toString();          // 虚函数
    virtual ~Token();                   // 析构函数
};
/**
 * 标识符记号类
 */
class Id: public Token{
public:
    string name;
    Id (string n);
    virtual string toString();
};
/*
 * 数字记号类
 */
class Num: public Token{
public:
    int val;
    Num (int v);
    virtual string toString();
};
/*
 * 字符记号类
 */
class Char: public Token{
public:
    char ch;
    Char (char c);
    virtual string toString();
};
/*
 * 字符串记号类
 */
class Str: public Token{
public:
    string str;
    Str (string s);
    virtual string toString();
};
/*
 * 关键字表类
 */
class Keywords{
    // hash 函数
    struct string_hash{
        size_t operator()(const string& str) const {
            return __st1_hash_string(str.c_str());
        }
    };
    hash_map<string, Tag, string_hash> keywords;
public:
    Keywords();
    Tag getTag(string name);
};
//
